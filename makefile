#Makefile for CS 219 S22 Programming Project 1

#Build executable from cpp file
pp1:
	g++ -o pp1 programming_project1.cpp -std=c++11

clean:
	rm pp1
