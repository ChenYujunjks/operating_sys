childreniter:
	gcc -o test -Wall iterative-children.c

childrenrecur:
	gcc -o test -Wall recursive-children.c

compiler:
	gcc -o concurrent-compilation/conc-compiler concurrent-compiler.c -Wall
	cd concurrent-compilation/;./conc-compiler main.c toto.c titi.c tata.c
	concurrent-compilation/my_exec

spy:
	gcc -o test -Wall spy.c


clean:
	rm -f test
	rm -f concurrent-compilation/*.o concurrent-compilation/my_exec concurrent-compilation/conc-compiler 

