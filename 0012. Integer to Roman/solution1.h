#pragma once
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::string;
using std::pair;
class Solution
{
private:
    const vector<pair<int, string>> conv = { {1000, "M"}, // compiler not support
                                            {900, "CM"}, 
                                            {500, "D"},
                                            {400, "CD"},
                                            {100, "C"},
                                            {90, "XC"},
                                            {50, "L"},
                                            {40, "XL"},
                                            {10, "X"},
                                            {9, "IX"},
                                            {5, "V"},
                                            {4, "IV"},
                                            {1, "I"}};
public:
    string intToRoman(int num) {
        string res;
        auto it = conv.begin();
        while (num > 0 && it != conv.end()) {
            if (num >= it->first) {
                num -= it->first;
                res += it->second;
            }
            else 
            {
              ++it;
            }
        }
        return res;
    }
};