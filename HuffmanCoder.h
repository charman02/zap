/*
 *  HuffmanCoder.h
 *  Charlie Man
 *  4/6/23
 *
 *  CS 15 Proj 3 zap
 *
 *  Purpose: This file defines the interface for the HuffmanCoder class,
 *           which comprises the main logic of the Huffman coding algorithm.
 *           It contains all of the public and private member functions and
 *           variables for the class. The public members can be accessed by
 *           the user, while the private members can only be accessed by
 *           other members of the class.
 *
 */
#ifndef __HUFFMANCODER_H__
#define __HUFFMANCODER_H__

#include "HuffmanTreeNode.h"
#include <string>
#include <iostream>
#include <unordered_map>

class HuffmanCoder {
public:
    void encoder(const std::string &input_file, const std::string &output_file);
    void decoder(const std::string &input_file, const std::string &output_file);

private:
    // encoder
    std::unordered_map<char, int> count_freq(std::istream &text);
    HuffmanTreeNode *build_tree(std::unordered_map<char, int> freqs);
    std::unordered_map<char, std::string> generate_codes(HuffmanTreeNode *root);
    std::string encode_text(std::istream &text, std::unordered_map<char,
        std::string> &code_map);
    std::string serialize_tree(HuffmanTreeNode *root);

    void generate_codes_helper(HuffmanTreeNode *node, std::string code,
        std::unordered_map<char, std::string> &code_map);

    // decoder
    HuffmanTreeNode *deserialize_tree(std::string &serialized);
    std::string decode_string(HuffmanTreeNode *root, std::string encoded);
    void delete_tree(HuffmanTreeNode *root);

    HuffmanTreeNode *deserialize_tree_helper(std::istream &iss);
    std::string decode_string_helper(HuffmanTreeNode *root, std::istream &iss);
};
#endif