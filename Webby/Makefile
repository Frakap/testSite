buildHtml.o: buildHtml.c 
	gcc -c buildHtml.c
initStat.o: initStat.c
	gcc -c initStat.c
main.o: main.c
	gcc -c main.c

Launch: main.o initStat.o buildHtml.o
	gcc main.o initStat.o buildHtml.o -o Launch