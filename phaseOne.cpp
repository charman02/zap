/*
 *  phaseOne.cpp
 *  Charlie Man
 *  3/30/23
 *
 *  CS 15 Proj 3 zap
 *
 *  Purpose: This file contains the function definitions for count_freqs,
 *           serialize_tree, and deserialize_tree.
 *
 */

#include "phaseOne.h"
#include "HuffmanTreeNode.h"
#include <string>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

void count_freqs(istream &text) {

    unordered_map<char, int> freqs;
    char c = '\0';

    while (text.get(c)) {
        if (freqs.count(c) == 0) {
            freqs[c] = 1;
        } else {
            freqs[c]++;
        }
    }

    text.clear(); // reset the stream state
    text.seekg(0); // rewind to the beginning of the stream

    while (text.get(c)) {
        if (freqs.count(c)) {
            cout << c << ": " << freqs[c] << endl;
            // remove the character from the map to avoid printing it twice
            freqs.erase(c);
        }
    }
}

string serialize_tree(HuffmanTreeNode *root) {

    if (root == nullptr) {
        return "";
    } else if (root->isLeaf()) {
        // leaf node
        return "L" + string(1, root->get_val());
    } else {
        // internal node
        return "I" + serialize_tree(root->get_left()) +
            serialize_tree(root->get_right());
    }
}

HuffmanTreeNode *deserialize_tree(string serial_tree) {

    if (serial_tree == "") {
        return nullptr;
    } else {
        istringstream iss(serial_tree);
        return deserialize_tree_helper(iss);
    }
}

HuffmanTreeNode *deserialize_tree_helper(istringstream &iss) {
    
    char c = '\0';
    iss >> c;
    if (c == 'I') {
        // internal node
        return new HuffmanTreeNode('\0', 0, deserialize_tree_helper(iss),
            deserialize_tree_helper(iss));
    } else {
        // leaf node
        iss >> c;
        return new HuffmanTreeNode(c, 0);
    }
}