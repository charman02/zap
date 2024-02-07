/*
 *  main.cpp
 *  Charlie Man
 *  4/12/23
 *
 *  COMP 15 Proj 3 zap
 *
 *  Purpose: This is the Main file that calls encoder or decoder on given
 *           input and output files, depending on if "zap" or "unzap"
 *           is given as one of the command line arguments.
 *
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "HuffmanCoder.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 4) {
        cerr << "Usage: ./zap [zap | unzap] inputFile outputFile" << endl;     
        return EXIT_FAILURE;
    }
    
    HuffmanCoder coder;
    
    if (strcmp(argv[1], "zap") == 0) {
        coder.encoder(argv[2], argv[3]);
    } else if (strcmp(argv[1], "unzap") == 0) {
        coder.decoder(argv[2], argv[3]);
    } else {
        cerr << "Usage: ./zap [zap | unzap] inputFile outputFile" << endl;
        return EXIT_FAILURE;
    }

};