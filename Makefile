CC = g++ -g -std=c++11

ass5.exe: ass5.cpp ass5_func.cpp link.cpp node.cpp
	$(CC) ass5.cpp ass5_func.cpp link.cpp node.cpp -o ass5

link.o: link.cpp
	$(CC) -c link.cpp

ass5_func.o: ass5_func.cpp
	$(CC) -c ass5_func.cpp

node.o: node.cpp
	$(CC) -c node.cpp

ass5.o: ass5.cpp
	$(CC) -c ass5.cpp


clean:
	rm -f *.out *.o ass5

