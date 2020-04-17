all: my_prog

my_prog: test.o big_int.o 
		g++ -o my_prog test.o big_int.o

big_int.o: big_int.cpp big_int.h
		g++ -c big_int.cpp

test.o: test.cpp big_int.h
		g++ -c test.cpp
		
run:	my_prog
		./my_prog

clean:
		rm -rf *.o my_prog
		rm -rf *.stackdump my_prog
		rm -rf *.exe my_prog