#include "trie.h"
#include <functional>

using namespace std;

Trie::Trie()
{
    root = new TrieNode();
}

void Trie::insert(const string &word)
{
    TrieNode *currentNode = root;
    for (char ch : word)
    {
        if (!currentNode->children.count(ch))
        {
            currentNode->children[ch] = new TrieNode();
        }
        currentNode = currentNode->children[ch];
    }
    currentNode->isEndOfWord = true;
}

bool Trie::search(const string &word)
{
    TrieNode *currentNode = root;
    for (char ch : word)
    {
        if (!currentNode->children.count(ch))
        {
            return false;
        }
        currentNode = currentNode->children[ch];
    }
    return currentNode->isEndOfWord;
}

vector<string> Trie::autocomplete(const string &prefix)
{
    vector<string> results;
    TrieNode *currentNode = root;

    for (char ch : prefix)
    {
        if (!currentNode->children.count(ch))
        {
            return results;
        }
        currentNode = currentNode->children[ch];
    }

    function<void(TrieNode *, string)> findWords = [&](TrieNode *node, string word)
    {
        if (node->isEndOfWord)
        {
            results.push_back(word);
        }
        for (auto &pair : node->children)
        {
            findWords(pair.second, word + pair.first);
        }
    };

    findWords(currentNode, prefix);
    return results;
}
