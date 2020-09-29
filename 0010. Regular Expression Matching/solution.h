#include <string>
using std::string;

class Solution
{
public:
    bool isMatch(string s, string p) {
        if (p.empty())  return s.empty();
        //if (s.empty())  return p.empty(); // when s is empty but p is '*'

        bool is_match = (!s.empty() && (s[0] == p[0] || p[0] == '.') );

        if (p.size() >= 2 && p[1] == '*') {
            return (isMatch(s, p.substr(2)) || (is_match && isMatch(s.substr(1), p) ) );
        }
        else
        {
            return (is_match && isMatch(s.substr(1), p.substr(1)));
        }
    }
};