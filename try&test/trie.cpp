//
//  trie.cpp
//  try&test
//
//  Created by Praneeth Patil on 10/27/17.
//  Copyright © 2017 Praneeth Patil. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Trie {
    unordered_map<char, vector<Trie*>> map_;
    bool end_of_word;
};

int insert_word (Trie* root, const string& word) {
    if (!root) return -1;
    for (size_t w_idx = 0; w_idx < word.length(); ++w_idx) {
        // if root is end of word, create a new node and add root's map
        // else, get the vector and
        while (!root->end_of_word) {
            auto it = root->map_.find(word[w_idx]);
            if (it == root->map_.end()) return -1;
            root = it->second;
        }
    }
}
