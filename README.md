# Purpose
The purpose of Project 3 was to write my own compression program called zap.
The program will be used specifically for compressing and decompressing text
files using the Huffman coding algorithm.

# Files
HuffmanCoder.h: interface of HuffmanCoder class

HuffmanCoder.cpp: implementation of HuffmanCoder class

unit_tests.h: unit tests used to test HuffmanCoder member functions

main.cpp: calls encoder or decoder on given input and output files, depending on whether "zap" or "unzap" is given as one of the command line arguments

README: explains program design and discusses specifics

Makefile: defines rules to create executable

huffman_wiki.txt: the Wikipedia definition of Huffman coding - used as a new input text file to test and pass to ./zap zap

my_wiki.zap: zapped (encoded) file of huffman_wiki.txt

my_new_wiki.txt: unzapped (decoded) file of my_wiki.zap

pride_and_prejudice.txt: the entire text of Pride and Prejudice used as a new input text file to test and pass to ./zap zap

my_pride.zap: zapped (encoded) file of pride_and_prejudice.txt

my_new_pride.txt: unzapped (decoded) file of my_pride.zap

# Compile/Run
        make zap
        ./zap [zap | unzap] inputFile outputFile

# Outline
A min-heap priority queue of HuffmanTreeNode pointers was used to build the
Huffman code tree. The queue was represented under the hood using a vector.
A min-heap priority queue can be used to construct a Huffman code tree because
it allows us to easily find and merge the two smallest nodes in the tree
during each step of the construction process, and then insert the merged node
back into the heap. Therefore, a min-heap priority queue is an efficient way
to keep track of the nodes. Next, I used an unordered map to represent
character counts as well as the binary code map. This is beneficial because
we need to perform a lot of lookups to retrieve the frequency counts and the
binary codes for each character. Since the order of the elements is not
important in this case, using an unordered map provides faster lookup times
and efficient storage of the data. One of the algorithms I implemented was the
serialize_tree function, which stored the Huffman tree as a string. This was
an essential function for my program as the serialized tree must be included
in the zapped output file. Another example is the algorithm I implemented for
decode_string, which decoded the binary encoded string obtained from the
encode_text function. My program relied on the decode_string function as it
was the most important part of the decoding process in producing the final
unzapped file (the original text).

# Testing
I tested all member functions of the HuffmanCoder class (except for encoder, 
decoder, and the helper functions) using the unit testing framework. I
temporarily made all of the member functions public when I was testing in
order to be able to call them. I used assert statements to test count_freqs
and decode_string, but the rest of the functions were tested by calling
printTree or printing using cerr. For example, I tested encode_text by
printing out the character codes and the encoded string to verify that it
was correct. Another example is that I tested serialize_tree by calling
printTree and then printing the serialized tree using cerr to compare the two
and verify that they matched. Finally, after I finished implementing all of
the member functions, I tested that the program as a whole was implemented
correctly by using the provided .txt files. I also created some of my own .txt
files. First, I zapped the .txt files and created .zap output files. Then,
I unzapped the .zap files and created new .txt output files. Finally, I used
diff to compare the original .txt file with the new .txt file. I also used
diff to compare new .txt output files using my program versus the reference
implementation.
