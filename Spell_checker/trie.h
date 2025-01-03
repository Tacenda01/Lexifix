#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie();
    void insert(const std::string &word);
    bool search(const std::string &word);
    vector<std::string> autocomplete(const string &prefix);
};

#endif
