server.out: compileAll
	g++ *.o -pthread
	rm -f *.o

compileAll: include/*.h src/*.cpp
	g++ -Iinclude/ -c src/*.cpp -g
run:
	./a.out

