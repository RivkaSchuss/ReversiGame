#shakedy6
#207234196

a.out: compileAll
	g++ *.o
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp
