/*
 *  HuffmanCoder.cpp
 *  Charlie Man
 *  4/6/23
 *
 *  CS 15 Proj 3 zap
 *
 *  Purpose: This is the implementation for the HuffmanCoder class, which
 *           comprises the main logic of the Huffman coding algorithm. It
 *           contains all definitions for both public and private member
 *           functions of the class.
 *
 */

#include "HuffmanCoder.h"
#include "BinaryIO.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <queue>

using namespace std;

/* 
 * encoder
 * purpose: encodes a given ASCII text file into compressed binary code
 * parameters: input and output file strings
 * returns: none
 */
void HuffmanCoder::encoder(const string &input_file, const string
    &output_file) {
        
    ifstream inFile(input_file);
    if (not inFile.is_open()) {
        string error = "Unable to open file " + input_file;
        throw runtime_error(error);
    }

    BinaryIO binFile;

    unordered_map<char, int> freqs = count_freq(inFile);
    HuffmanTreeNode *tree = build_tree(freqs);
    unordered_map<char, string> code_map = generate_codes(tree);
    string encoded = encode_text(inFile, code_map);
    string serialized = serialize_tree(tree);
    binFile.writeFile(output_file, serialized, encoded);

    cout << "Success! Encoded given text using " << encoded.size();
    cout << " bits." << endl;

    delete_tree(tree);
}

/* 
 * count_freq
 * purpose: counts the number of occurrences of each character in the given
 *          text
 * parameters: input stream containing contents of given text
 * returns: unordered map of characters in text and their frequencies
 */
unordered_map<char, int> HuffmanCoder::count_freq(istream &text) {
    
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

    return freqs;
}

/* 
 * build_tree
 * purpose: builds a Huffman code tree for given text using a priority queue
 * parameters: unordered map of character frequencies
 * returns: root node in Huffman code tree
 */
HuffmanTreeNode *HuffmanCoder::build_tree(unordered_map<char, int> freqs) {
    
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>,
                   NodeComparator> my_pq;

    for (auto it = freqs.begin(); it != freqs.end(); it++) {
        HuffmanTreeNode *node = new HuffmanTreeNode(it->first, it->second);
        my_pq.push(node);
    }

    while (my_pq.size() > 1) {
        HuffmanTreeNode *n1 = my_pq.top();
        my_pq.pop();
        HuffmanTreeNode *n2 = my_pq.top();
        my_pq.pop();
        HuffmanTreeNode *parent = new HuffmanTreeNode('\0', n1->get_freq() +
            n2->get_freq());
        parent->set_right(n1);
        parent->set_left(n2);
        my_pq.push(parent);
    }

    return my_pq.top();
}

/* 
 * generate_codes
 * purpose: generates binary codes for each character
 * parameters: root node in Huffman code tree
 * returns: unordered map of binary codes for each character
 */
unordered_map<char, string> HuffmanCoder::generate_codes(HuffmanTreeNode
    *root) {

    unordered_map<char, string> code_map;
    generate_codes_helper(root, "", code_map);
    return code_map;

}

/* 
 * generate_codes_helper
 * purpose: recursive helper function for generate_codes
 * parameters: root node, string to represent encodings for each character,
 *             unordered map of each character in the text and their
 *             frequencies
 * returns: none
 */
void HuffmanCoder::generate_codes_helper(HuffmanTreeNode *node, string code,
    unordered_map<char, string> &code_map) {

    if (node->isLeaf()) {
        code_map[node->get_val()] = code;
        return;
    }

    generate_codes_helper(node->get_left(), code + "0", code_map);
    generate_codes_helper(node->get_right(), code + "1", code_map);
    
}

/* 
 * encode_text
 * purpose: encode the given text into binary
 * parameters: input stream containing containing given text and unordered
 *             map of character encodings
 * returns: encoded binary string
 */
string HuffmanCoder::encode_text(istream &text, unordered_map<char, string>
    &code_map) {
    
    char c = '\0';
    string encoded = "";

    while (text.get(c)) {
        encoded += code_map[c];
    }

    return encoded;

}

/* 
 * serialize_tree
 * purpose: store the Huffman tree as a string
 * parameters: root node in Huffman tree
 * returns: serialized tree string
 */
string HuffmanCoder::serialize_tree(HuffmanTreeNode *root) {

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

/* 
 * decoder
 * purpose: decompresses a previously zapped file and saves the resulting
 *          ASCII text to an output file
 * parameters: input and output file strings
 * returns: none
 */
void HuffmanCoder::decoder(const string &input_file, const string
    &output_file) {

    BinaryIO binFile;
    string serial_tree, encoded_text;
    pair<string, string> zapPair = binFile.readFile(input_file);
    string serialized = zapPair.first;
    string encoded = zapPair.second;
    HuffmanTreeNode *root = deserialize_tree(serialized);
    string decoded = decode_string(root, encoded);
    ofstream outFile(output_file);
    outFile << decoded;
    delete_tree(root);
}

/* 
 * deserialize_tree
 * purpose: convert the tree from its serialized string format back into a
 *          tree data structure composed of HuffmanTreeNodes
 * parameters: serialized tree string
 * returns: root node of tree
 */
HuffmanTreeNode *HuffmanCoder::deserialize_tree(string &serialized) {

    if (serialized == "") {
        return nullptr;
    } else {
        istringstream iss(serialized);
        return deserialize_tree_helper(iss);
    }

}

/* 
 * deserialize_tree_helper
 * purpose: recursive helper function for deserialize_tree
 * parameters: input stream containing serialized tree
 * returns: root node of tree
 */
HuffmanTreeNode *HuffmanCoder::deserialize_tree_helper(istream &iss) {

    char c;
    iss.get(c);
    if (c == 'I') {
        // internal node
        return new HuffmanTreeNode('\0', 0, deserialize_tree_helper(iss),
            deserialize_tree_helper(iss));
    } else {
        // leaf node
        iss.get(c);
        return new HuffmanTreeNode(c, 0);
    }
    
}

/* 
 * decode_string
 * purpose: decode the encoded binary string
 * parameters: root node of tree, encoded binary string
 * returns: decoded string
 */
string HuffmanCoder::decode_string(HuffmanTreeNode *root, string encoded) {

    if (encoded == "") {
        return encoded;
    }

    istringstream iss(encoded);
    return decode_string_helper(root, iss);

}

/* 
 * decode_string_helper
 * purpose: helper function for decode_string
 * parameters: root node of tree, input stream containing encoded string
 * returns: decoded string
 */
string HuffmanCoder::decode_string_helper(HuffmanTreeNode *root,
    istream &iss) {

    HuffmanTreeNode *curr = root;
    string decoded = "";
    char c = '\0';

    while (iss.get(c)) {
        if (c == '0') {
            if (curr->get_left()->isLeaf()) {
                decoded += curr->get_left()->get_val();
                curr = root;
            } else {
                curr = curr->get_left();
            }
        } else if (c == '1') {
            if (curr->get_right()->isLeaf()) {
                decoded += curr->get_right()->get_val();
                curr = root;
            } else {
                curr = curr->get_right();
            }
        }
    }

    if (curr != root) {
        throw runtime_error("Encoding did not match Huffman tree.");
    }

    return decoded;
}

/* 
 * delete_tree
 * purpose: recycle heap memory of tree
 * parameters: root node of tree
 * returns: none
 */
void HuffmanCoder::delete_tree(HuffmanTreeNode *root) {
    
    if (root == nullptr) {
        return;
    }

    delete_tree(root->get_left());
    delete_tree(root->get_right());
    delete root;
}