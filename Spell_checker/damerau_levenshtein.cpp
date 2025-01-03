#include "damerau_levenshtein.h"
#include <vector>
#include <algorithm>
using namespace std;

int damerauLevenshtein(const string &s1, const string &s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int>> d(len1 + 2, vector<int>(len2 + 2, 0));

    for (int i = 0; i <= len1; i++)
        d[i + 1][1] = i;
    for (int j = 0; j <= len2; j++)
        d[1][j + 1] = j;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i + 1][j + 1] = min({d[i][j + 1] + 1, d[i + 1][j] + 1, d[i][j] + cost});

            if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && s1[i - 2] == s2[j - 1])
            {
                d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i - 1][j - 1] + cost);
            }
        }
    }
    return d[len1 + 1][len2 + 1];
}
