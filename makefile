#shakedy6 schussr1
#207234196 340903129

a.out: compileAll
	g++ *.o
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp
