all: Test Countingsort.o

Countingsort.o: Countingsort.cpp
	g++ -Wall -c Countingsort.cpp

Test: Countingsort.cpp CountingsortTest.cpp
#	g++ -Wall -std=c++11 -o Test CountingsortTest.cpp -lcppunit
	g++ -Wall -o Test CountingsortTest.cpp -lcppunit

clean:
	rm Test *.o *~
