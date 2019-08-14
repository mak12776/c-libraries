
commit:
	git commit -m "more codes"

main: main.c
	gcc -o $@ $<

xcript: xcript.c misc.c error.c
	gcc -o $@ $?

