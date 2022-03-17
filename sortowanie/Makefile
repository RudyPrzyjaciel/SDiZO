sort: sort.o bubble.o uni.o insert.o quick.o heapsort.o counting.o
	g++ sort.o bubble.o uni.o insert.o quick.o heapsort.o counting.o -o sort
	make clean

bubble.o: dependencies/bubble.c
	g++ -c dependencies/bubble.c
	
uni.o: dependencies/uni.c
	g++ -c dependencies/uni.c

insert.o: dependencies/insert.c
	g++ -c dependencies/insert.c

quick.o: dependencies/quick.c
	g++ -c dependencies/quick.c

counting.o: dependencies/counting.c
	g++ -c dependencies/counting.c

heapsort.o: dependencies/heapsort.c
	g++ -c dependencies/heapsort.c

sort.o: sort.c
	g++ -c sort.c

clean:
	-rm  *.o