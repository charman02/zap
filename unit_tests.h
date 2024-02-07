/*
 *  unit_tests.h
 *  Charlie Man
 *  3/31/23
 *
 *  CS 15 Proj 3 zap
 *
 *  Purpose: This file contains all unit tests for testing the phase 1
 *           functions (count_freqs, serialize_tree, deserialize_tree) and
 *           the member functions of the HuffmanCoder class.
 *
 */

#include "HuffmanCoder.h"
#include "HuffmanTreeNode.h"
#include "ZapUtil.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <unordered_map>

using namespace std;

/* PHASE 1 FUNCTIONS */

// void count_freqs_banana() {
//     ifstream inFile("banana.txt");
//     ostringstream oss;
//     count_freqs(inFile, oss);
//     assert(oss.str() == "B: 1\na: 3\nN: 1\nn: 1\n");
// }

// void count_freqs_hi() {
//     ifstream inFile("hi.txt");
//     ostringstream oss;
//     count_freqs(inFile, oss);
//     assert(oss.str() == "h: 3\ni: 3\n : 1\n\n: 1\n");
// }

// void count_freqs_banana_apple() {
//     ifstream inFile("banana_apple.txt");
//     ostringstream oss;
//     count_freqs(inFile, oss);
//     assert(oss.str() == "A: 1\np: 4\nl: 2\ne: 2\n : 1\na: 4\n.: 1\n\n: 1\n"
//                         "B: 1\nn: 2\n?: 1\n");
// }

// void serialize_zap_util() {
//     const char INTERNAL_NODE_VAL = '\0';
//     HuffmanTreeNode *fig1Tree = makeFigure1Tree(INTERNAL_NODE_VAL);
//     string serTree = serialize_tree(fig1Tree);
//     assert(serialize_tree(makeFigure1Tree(INTERNAL_NODE_VAL)) ==
//         "IIILaLbILeLfILcLd");
// }

// void deserialize_zap_util() {
//     const char INTERNAL_NODE_VAL = '\0';
//     HuffmanTreeNode *fig1Tree = makeFigure1Tree(INTERNAL_NODE_VAL);
//     HuffmanTreeNode *deserTree = deserialize_tree("IIILaLbILeLfILcLd");
//     printTree(deserTree, '\0');
// }

/* HUFFMANCODER FUNCTIONS */

// void build_tree_zap_util() {
//     const char INTERNAL_NODE_VAL = '\0';
//     HuffmanTreeNode *fig1Tree = makeFigure1Tree(INTERNAL_NODE_VAL);
//     HuffmanCoder test_coder;
//     unordered_map<char, int> fig1Map;
//     fig1Map['a'] = 1;
//     fig1Map['b'] = 1;
//     fig1Map['c'] = 2;
//     fig1Map['d'] = 2;
//     fig1Map['e'] = 1;
//     fig1Map['f'] = 1;
//     HuffmanTreeNode *myFig1 = test_coder.build_tree(fig1Map);
//     printTree(myFig1, INTERNAL_NODE_VAL);
//     printTree(fig1Tree, INTERNAL_NODE_VAL);
// }

// void build_tree_ecoli() {
    // ifstream inFile("ecoli.coli");
    // HuffmanCoder test_coder;
    // const char INTERNAL_NODE_VAL = '\0';

    // unordered_map<char, int> freqs = test_coder.count_freq(inFile);
    // HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     printTree(tree, INTERNAL_NODE_VAL);
// }

// void generate_codes_zap_util() {
//     const char INTERNAL_NODE_VAL = '\0';
//     HuffmanTreeNode *fig1Tree = makeFigure1Tree(INTERNAL_NODE_VAL);
//     HuffmanCoder test_coder;
//     unordered_map<char, string> code_map =
//         test_coder.generate_codes(fig1Tree);
//     for (auto it = code_map.begin(); it != code_map.end(); it++) {
//         cerr << it->first << ": " << it->second << endl;
//     }
// }

// void generate_codes_ecoli() {
//     ifstream inFile("ecoli.coli");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map =
//         test_coder.generate_codes(tree);
//     for (auto it = code_map.begin(); it != code_map.end(); it++) {
//         cerr << it->first << ": " << it->second << endl;
//     }
// }

// void encode_text_banana() {
//     ifstream inFile("banana.txt");
//     HuffmanCoder test_coder;

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
    
//     for (auto it = code_map.begin(); it != code_map.end(); it++) {
//         cerr << it->first << ": " << it->second << endl;
//     }

//     cerr << encoded << endl;
// }

// void encode_text_hi() {
//     ifstream inFile("hi.txt");
//     HuffmanCoder test_coder;

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
    
//     for (auto it = code_map.begin(); it != code_map.end(); it++) {
//         cerr << it->first << ": " << it->second << endl;
//     }

//     cerr << encoded << endl;
// }

// void encode_text_banana_apple() {
//     ifstream inFile("banana_apple.txt");
//     HuffmanCoder test_coder;

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
    
//     for (auto it = code_map.begin(); it != code_map.end(); it++) {
//         cerr << it->first << ": " << it->second << endl;
//     }

//     cerr << encoded << endl;
// }

// void encode_text_sentences() {
//     ifstream inFile("sentences.txt");
//     HuffmanCoder test_coder;

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
    
//     for (auto it = code_map.begin(); it != code_map.end(); it++) {
//         cerr << it->first << ": " << it->second << endl;
//     }

//     cerr << encoded << endl;
// }

// void encode_text_ecoli() {
//     ifstream inFile("ecoli.coli");
//     HuffmanCoder test_coder;

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
    
    // for (auto it = code_map.begin(); it != code_map.end(); it++) {
    //     cerr << it->first << ": " << it->second << endl;
    // }

//     cerr << encoded << endl;
// }

// void serialize_tree_banana() {
//     ifstream inFile("banana.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     string serialized = test_coder.serialize_tree(tree);

//     printTree(tree, INTERNAL_NODE_VAL);
//     cerr << serialized << endl;
// }

// void serialize_tree_hi() {
//     ifstream inFile("hi.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     string serialized = test_coder.serialize_tree(tree);

//     printTree(tree, INTERNAL_NODE_VAL);
//     cerr << serialized << endl;
// }

// void serialize_tree_banana_apple() {
//     ifstream inFile("banana_apple.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     string serialized = test_coder.serialize_tree(tree);

//     printTree(tree, INTERNAL_NODE_VAL);
//     cerr << serialized << endl;
// }

// void serialize_tree_ecoli() {
//     ifstream inFile("ecoli.coli");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     string serialized = test_coder.serialize_tree(tree);

//     printTree(tree, INTERNAL_NODE_VAL);
//     cerr << serialized << endl;
// }

// void deserialize_tree_banana() {
//     ifstream inFile("banana.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     printTree(tree, INTERNAL_NODE_VAL);
//     string serialized = test_coder.serialize_tree(tree);
//     HuffmanTreeNode *deserialized = test_coder.deserialize_tree(serialized);
//     printTree(deserialized, INTERNAL_NODE_VAL);
// }

// void deserialize_tree_hi() {
//     ifstream inFile("hi.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     printTree(tree, INTERNAL_NODE_VAL);
//     string serialized = test_coder.serialize_tree(tree);
//     HuffmanTreeNode *deserialized = test_coder.deserialize_tree(serialized);
//     printTree(deserialized, INTERNAL_NODE_VAL);
// }

// void deserialize_tree_banana_apple() {
//     ifstream inFile("banana_apple.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     printTree(tree, INTERNAL_NODE_VAL);
//     string serialized = test_coder.serialize_tree(tree);
//     HuffmanTreeNode *deserialized = test_coder.deserialize_tree(serialized);
//     printTree(deserialized, INTERNAL_NODE_VAL);
// }

// void deserialize_tree_ecoli() {
//     ifstream inFile("ecoli.coli");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';

//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     printTree(tree, INTERNAL_NODE_VAL);
//     string serialized = test_coder.serialize_tree(tree);
//     HuffmanTreeNode *deserialized = test_coder.deserialize_tree(serialized);
//     printTree(deserialized, INTERNAL_NODE_VAL);
// }

// void decode_string_banana() {
//     ifstream inFile("banana.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';
    
//     ostringstream oss;
//     oss << inFile.rdbuf();
//     string originText = oss.str();
//     inFile.clear();
//     inFile.seekg(0, ios::beg);
    
//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
//     string serialized = test_coder.serialize_tree(tree);
//     HuffmanTreeNode *deserialized = test_coder.deserialize_tree(serialized);
//     string decoded = test_coder.decode_string(deserialized, encoded);
//     assert(decoded == originText);
// }

// void decode_string_hi() {
//     ifstream inFile("hi.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';
    
//     ostringstream oss;
//     oss << inFile.rdbuf();
//     string originText = oss.str();
//     inFile.clear();
//     inFile.seekg(0, ios::beg);
    
//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
//     string serialized = test_coder.serialize_tree(tree);
//     HuffmanTreeNode *deserialized = test_coder.deserialize_tree(serialized);
//     string decoded = test_coder.decode_string(deserialized, encoded);
//     assert(decoded == originText);
// }

// void decode_string_banana_apple() {
//     ifstream inFile("banana_apple.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';
    
//     ostringstream oss;
//     oss << inFile.rdbuf();
//     string originText = oss.str();
//     inFile.clear();
//     inFile.seekg(0, ios::beg);
    
//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
//     string serialized = test_coder.serialize_tree(tree);
//     HuffmanTreeNode *deserialized = test_coder.deserialize_tree(serialized);
//     string decoded = test_coder.decode_string(deserialized, encoded);
//     assert(decoded == originText);
// }

// void decode_string_shakespeare() {
//     ifstream inFile("works_of_shakespeare.txt");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';
    
//     ostringstream oss;
//     oss << inFile.rdbuf();
//     string originText = oss.str();
//     inFile.clear();
//     inFile.seekg(0, ios::beg);
    
//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
//     string serialized = test_coder.serialize_tree(tree);
//     HuffmanTreeNode *deserialized = test_coder.deserialize_tree(serialized);
//     string decoded = test_coder.decode_string(deserialized, encoded);
//     assert(decoded == originText);
// }

// void decode_string_ecoli() {
//     ifstream inFile("ecoli.coli");
//     HuffmanCoder test_coder;
//     const char INTERNAL_NODE_VAL = '\0';
    
//     ostringstream oss;
//     oss << inFile.rdbuf();
//     string originText = oss.str();
//     inFile.clear();
//     inFile.seekg(0, ios::beg);
    
//     unordered_map<char, int> freqs = test_coder.count_freq(inFile);
//     HuffmanTreeNode *tree = test_coder.build_tree(freqs);
//     unordered_map<char, string> code_map = test_coder.generate_codes(tree);
//     string encoded = test_coder.encode_text(inFile, code_map);
//     string serialized = test_coder.serialize_tree(tree);
//     HuffmanTreeNode *deserialized = test_coder.deserialize_tree(serialized);
//     string decoded = test_coder.decode_string(deserialized, encoded);
//     assert(decoded == originText);
// }