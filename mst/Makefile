mst: graphEdges.o pointInt2.o mst.o
	g++ graphEdges.o pointInt2.o mst.o  -o mst

graphEdges.o: dep/graphEdges.cpp
	g++ -c dep/graphEdges.cpp

pointInt2.o: dep/pointInt2.cpp
	g++ -c dep/pointInt2.cpp

mst.o: mst.cpp
	g++ -c mst.cpp

clean:
	(make clean)
	-rm *.o