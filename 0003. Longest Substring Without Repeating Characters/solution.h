#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
using std::max;
#include <vector>
using std::vector;

// version1: two cumbersome
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        size_t f = 0,  maxL = 0;
//        unordered_map<char, int> mp;
//        for (size_t i = 0; i < s.length(); i++)
//        {
//            auto b = mp.find(s[i]);
//            if (b != mp.end())
//            {
//                while (f < b->second && f < s.length())
//                {
//                    mp.erase(s[f]);
//                    f++;
//                }
//                f++;
//                mp[s[i]] = i;
//            }
//            else
//            {
//                mp.emplace(s[i], i);
//            }
//            maxL = max(i - f + 1, maxL);
//        }
//        return maxL;
//    }
//};

// version 2: more simple
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        size_t f = 0, maxL = 0;
//        unordered_map<char, int> mp;
//        for (size_t i = 0; i < s.length(); i++)
//        {
//            auto b = mp.find(s[i]);
//            if (b != mp.end() && f <= b->second)
//            {
//                f = b->second + 1;
//            }
//            mp[s[i]] = i;
//            maxL = max(i - f + 1, maxL);
//        }
//        return maxL;
//    }
//};

// version 3: the fastest, replace unordered_map with hash array.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t f = 0, maxL = 0;
        vector<int> mp(256, -1);
        for (size_t i = 0; i < s.length(); i++)
        {
            if (mp[s[i]] != -1 && f <= mp[s[i]])
            {
                f = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            maxL = max(i - f + 1, maxL);
        }
        return maxL;
    }
};
