#include "lcs.h"

#include <thread>
#include <vector>
#include <algorithm>


using namespace std;

string lcs(const string& first, const string& second) {
    vector<vector<int> > max_len;
    max_len.resize(first.size() + 1);
    for (int i = 0; i <= static_cast<int>(first.size()); i++)
        max_len[i].resize(second.size() + 1);

    for (int i = static_cast<int>(first.size()) - 1; i >= 0; i--)
    {
        for (int j = static_cast<int>(second.size()) - 1; j >= 0; j--)
        {
            if (first[i] == second[j])
            {
                max_len[i][j] = 1 + max_len[i + 1][j + 1];
            }
            else
            {
                max_len[i][j] = max(max_len[i + 1][j], max_len[i][j + 1]);
            }
        }
    }

    string res;

    for (int i = 0, j = 0; max_len[i][j] != 0 && i < static_cast<int>(first.size()) && j < static_cast<int>(second.size()); )
    {
        if (first[i] == second[j])
        {
            res.push_back(first[i]);
            i++;
            j++;
        }
        else
        {
            if (max_len[i][j] == max_len[i + 1][j])
                i++;
            else
                j++;
        }
    }
    return res;
}