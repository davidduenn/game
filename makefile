all: game

game: main.o army.o units.o map.o
	g++ -g main.o army.o units.o map.o -ogame

main.o: main.cpp
	g++ -g -c main.cpp

army.o: army.cpp
	g++ -g -c army.cpp

units.o: units.cpp
	g++ -g -c units.cpp

map.o: map.cpp
	g++ -g -c map.cpp

run: game
	clear; ./game > oput.txt

clean:
	rm*.o

nuke:
	rm *.o game
