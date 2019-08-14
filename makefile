
main: main.c
	gcc -o $@ $<

xcript: xcript.c misc.c error.c
	gcc -o $@ $?

