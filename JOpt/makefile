buildHtml.o: buildHtml.c main.h
	gcc -c buildHtml.c
initStat.o: initStat.c main.h 
	gcc -c initStat.c  

main.o: main.c main.h 
	gcc -c main.c

Webby: main.o buildHtml.o initStat.o main.h
	gcc main.o buildHtml.o initStat.o -o Webby