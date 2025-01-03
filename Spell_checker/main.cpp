#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "ngram_freq.h"
#include "trie.h"

using namespace std;

void correctSentence(NGramFrequency &ngramFrequency, Trie &trie, const string &input)
{
    istringstream iss(input);
    string word;
    string correctedSentence;

    while (iss >> word)
    {
        string cleanWord;
        string punctuation;

        size_t end = word.size();
        while (end > 0 && ispunct(word[end - 1]))
        {
            punctuation = word[end - 1] + punctuation;
            --end;
        }

        cleanWord = word.substr(0, end);
        transform(cleanWord.begin(), cleanWord.end(), cleanWord.begin(), ::tolower);

        if (trie.search(cleanWord))
        {
            correctedSentence += cleanWord + punctuation + " ";
        }
        else
        {
            vector<string> suggestions = ngramFrequency.getSuggestions(cleanWord);
            if (!suggestions.empty())
            {
                correctedSentence += suggestions[0] + punctuation + " ";
            }
            else
            {
                correctedSentence += cleanWord + punctuation + " ";
            }
        }
    }

    if (!correctedSentence.empty())
    {
        correctedSentence.pop_back();
    }

    string normalizedSentence;
    char lastChar = 0;
    for (char c : correctedSentence)
    {
        if (ispunct(c) && c == lastChar)
        {
            continue;
        }
        normalizedSentence += c;
        lastChar = c;
    }

    cout << normalizedSentence << endl;
}

int main()
{
    NGramFrequency ngramFrequency;
    Trie trie;

    ngramFrequency.loadFromFile("ngram_freq_dict.csv");

    for (const auto &word : ngramFrequency.getWords())
    {
        trie.insert(word);
    }

    string input;
    getline(cin, input);

    correctSentence(ngramFrequency, trie, input);

    return 0;
}
