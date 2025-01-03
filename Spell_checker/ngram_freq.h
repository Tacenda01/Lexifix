#ifndef NGRAM_FREQ_H
#define NGRAM_FREQ_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class NGramFrequency
{
private:
    unordered_map<std::string, long long int> frequencyMap;

public:
    void loadFromFile(const std::string &filename);
    vector<std::string> getSuggestions(const std::string &word);
    vector<std::string> getWords();
};

#endif
