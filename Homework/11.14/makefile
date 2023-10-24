CC = gcc

JacobBilesHW5: functions.o main.o
	g++ functions.o main.o -o JacobBilesHW5

functions.o: functions.cpp
	g++ -c functions.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	del -rf *.o *.exe