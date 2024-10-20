#include <os-scheduling.h>
#include <limits.h>


int admitNewTasks(task tasks[], int nbOfTasks, sched_data* schedData, int currentTime) {
    int i, j;
    j = 0;
    while (schedData->queues[0][j] != -1)
        j++;
    for(i = 0; i < nbOfTasks; i++) {
        if ((tasks[i].state == UPCOMING) && (tasks[i].arrivalDate == currentTime)) {
            tasks[i].state = READY;
            schedData->queues[0][j] = i;
            j++;
        }
    }
    return 1;
}


int FCFS(task tasks[], int nbOfTasks, sched_data* schedData, int currentTime) {
    
    int i, j;
    
    // Initialize single queue
    if (currentTime == 0) {
        printf("Initializing job queue\n");
        schedData->nbOfQueues = 1;
        for (i = 0; i < MAX_NB_OF_TASKS; i++) {
            schedData->queues[0][i] = -1;
        }
    }
    
    admitNewTasks(tasks, nbOfTasks, schedData, currentTime);
    printQueues(tasks, schedData);
    
    // Is the first task in the queue running? Has that task finished its computations?
    //   If so, put it in terminated state and remove it from the queue
    //   If not, continue this task
    i = schedData->queues[0][0];
    if (i != -1) {
        if (tasks[i].state == RUNNING) {
            if (tasks[i].executionTime == tasks[i].computationTime) {
                tasks[i].state = TERMINATED;
                tasks[i].completionDate = currentTime;
                for (j = 0; j < MAX_NB_OF_TASKS - 1; j++) {
                    schedData->queues[0][j] = schedData->queues[0][j+1];
                }
            } else {
                /* Reelect this task */
                tasks[i].executionTime ++;
                return i;
            }
        }
    }
    
    // Otherwise, elect the first task in the queue
    i = schedData->queues[0][0];
    if (i != -1){
        tasks[i].executionTime ++;
        tasks[i].state = RUNNING;
        return i;
    }
    
    // No task could be elected
    return -1;
}


int SJF(task tasks[], int nbOfTasks, sched_data* schedData, int currentTime) {
    int i, selectedTask = -1;
    int shortestTime = INT_MAX;

    admitNewTasks(tasks, nbOfTasks, schedData, currentTime);
    printQueues(tasks, schedData);

    // 找到最短作业（非抢占式）
    for (i = 0; i < nbOfTasks; i++) {
        if (tasks[i].state == READY && tasks[i].computationTime < shortestTime) {
            shortestTime = tasks[i].computationTime;
            selectedTask = i;
        }
    }

    if (selectedTask != -1) {
        tasks[selectedTask].executionTime++;
        tasks[selectedTask].state = RUNNING;
        if (tasks[selectedTask].executionTime == tasks[selectedTask].computationTime) {
            tasks[selectedTask].state = TERMINATED;
            tasks[selectedTask].completionDate = currentTime;
        }
        return selectedTask;
    }
    //TODO (LAB Q3)
    return -1;
}


int SRTF(task tasks[], int nbOfTasks, sched_data* schedData, int currentTime) {
    //TODO (LAB Q3)
    int i, selectedTask = -1;
    int shortestRemainingTime = INT_MAX;

    admitNewTasks(tasks, nbOfTasks, schedData, currentTime);
    printQueues(tasks, schedData);

    // find shortest lasting task
    for (i = 0; i < nbOfTasks; i++) {
        if (tasks[i].state == READY || tasks[i].state == RUNNING) {
            int remainingTime = tasks[i].computationTime - tasks[i].executionTime;
            if (remainingTime < shortestRemainingTime) {
                shortestRemainingTime = remainingTime;
                selectedTask = i;
            }
        }
    }

    if (selectedTask != -1) {
        tasks[selectedTask].executionTime++;
        tasks[selectedTask].state = RUNNING;
        if (tasks[selectedTask].executionTime == tasks[selectedTask].computationTime) {
            tasks[selectedTask].state = TERMINATED;
            tasks[selectedTask].completionDate = currentTime;
        }
        return selectedTask;
    }

    return -1;
}


int RR(task tasks[], int nbOfTasks, sched_data* schedData, int currentTime) {
    //TODO (ASSIGNMENT Q1)
    return -1;
}

int MFQ(task tasks[], int nbOfTasks, sched_data* schedData, int currentTime) {
    //TODO (ASSIGNMENT Q2)
    return -1;
}

int IORR(task tasks[], int nbOfTasks, sched_data* schedData, int currentTime) {
    //TODO (ASSIGNMENT BONUS)
    return -1;
}
