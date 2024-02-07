/*
 *  phaseOne.h
 *  Charlie Man
 *  3/30/23
 *
 *  CS 15 Proj 3 zap
 *
 *  Purpose: This file contains the function declarations for
 *           count_freqs, serialize_tree, and deserialize_tree.
 *
 */

#include "HuffmanTreeNode.h"
#include <iostream>
#include <string>
#include <sstream>

void count_freqs(std::istream &text);

std::string serialize_tree(HuffmanTreeNode *root);

HuffmanTreeNode *deserialize_tree(std::string serial_tree);

// recursive helper function for deserialize_tree
HuffmanTreeNode *deserialize_tree_helper(std::istringstream &iss);