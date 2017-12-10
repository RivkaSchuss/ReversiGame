#schussr1
#340903129
server.out: Server.o main.o
	g++ main.o Server.o

Board.o: Server Server.h
	g++ -c Server.cpp

main.o: main.cpp Server.h
	g++ -c main.cpp