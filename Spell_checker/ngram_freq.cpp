#include "ngram_freq.h"
#include "damerau_levenshtein.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

void NGramFrequency::loadFromFile(const string &filename)
{
    ifstream file(filename);
    string line;

    while (getline(file, line))
    {
        istringstream ss(line);
        string word;
        long long int frequency;

        if (getline(ss, word, ',') && ss >> frequency)
        {
            frequencyMap[word] = frequency;
        }
    }
}

vector<string> NGramFrequency::getWords()
{
    vector<string> words;
    for (const auto &pair : frequencyMap)
    {
        words.push_back(pair.first);
    }
    return words;
}

vector<string> NGramFrequency::getSuggestions(const string &input)
{
    vector<pair<string, long long int>> suggestions;

    char startLetter = tolower(input[0]);

    for (const auto &pair : frequencyMap)
    {
        const string &word = pair.first;

        if (tolower(word[0]) == startLetter)
        {
            int overlap = 0;
            for (char c : input)
            {
                if (word.find(c) != string::npos)
                {
                    overlap++;
                }
            }

            int distance = damerauLevenshtein(input, word);

            if (overlap > 1 || distance <= 3)
            {
                suggestions.emplace_back(word, pair.second);
            }
        }
    }

    sort(suggestions.begin(), suggestions.end(), [&input](const auto &a, const auto &b)
         {
             const string &wordA = a.first;
             const string &wordB = b.first;
             int overlapA = 0, overlapB = 0;
             for (char c : input)
             {
                 if (wordA.find(c) != string::npos) overlapA++;
                 if (wordB.find(c) != string::npos) overlapB++;
             }
             if (overlapA != overlapB)
                 return overlapA > overlapB;

             int distanceA = damerauLevenshtein(input, wordA);
             int distanceB = damerauLevenshtein(input, wordB);

             if (distanceA != distanceB)
                 return distanceA < distanceB;
             return a.second > b.second; });

    vector<string> result;
    if (!suggestions.empty())
    {
        result.push_back(suggestions[0].first);
    }

    return result;
}
