sort: sort.o bubble.o uni.o insert.o quick.o
	g++ sort.o bubble.o uni.o insert.o quick.o -o sort
	make clean

bubble.o: dependencies/bubble.c
	g++ -c dependencies/bubble.c
	
uni.o: dependencies/uni.c
	g++ -c dependencies/uni.c

insert.o: dependencies/insert.c
	g++ -c dependencies/insert.c

quick.o: dependencies/quick.c
	g++ -c dependencies/quick.c

sort.o: sort.c
	g++ -c sort.c

clean:
	-rm  *.o