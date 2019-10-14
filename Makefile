all:
	g++ -std=c++11 -pthread -o synch synch.cpp
	./synch
clean:
	rm synch.txt synch