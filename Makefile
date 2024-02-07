###
### Makefile for zap Project
###
### Author: Charlie Man

MAKEFLAGS += -L

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

zap: HuffmanCoder.o BinaryIO.o HuffmanTreeNode.o main.o
	$(CXX) $(LDFLAGS) -o $@ $^

main.o: main.cpp HuffmanCoder.h BinaryIO.h HuffmanTreeNode.h
	${CXX} ${CXXFLAGS} -c main.cpp

HuffmanCoder.o: HuffmanCoder.cpp HuffmanCoder.h BinaryIO.h HuffmanTreeNode.h
	${CXX} ${CXXFLAGS} -c HuffmanCoder.cpp

phaseOne.o: phaseOne.cpp phaseOne.h HuffmanTreeNode.h
	${CXX} ${CXXFLAGS} -c phaseOne.cpp

unit_test: unit_test_driver.o HuffmanCoder.o HuffmanTreeNode.o BinaryIO.o \
		   ZapUtil.o
	${CXX} ${CXXFLAGS} $^

clean:
	rm *.o *~ a.out

provide:
	provide comp15 proj3_zap README Makefile unit_tests.h main.cpp \
		HuffmanCoder.h HuffmanCoder.cpp huffman_wiki.txt \
		my_wiki.zap my_new_wiki.txt pride_and_prejudice.txt my_pride.zap \
		my_new_pride.txt