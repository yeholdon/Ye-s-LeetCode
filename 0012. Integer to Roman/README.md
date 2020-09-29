# 思路（C++）

### 思路一

我的第一种做法非常繁琐，基本就是加了很多map把整个匹配过程模拟了一遍，还有很多特殊情况要判断，执行效率也很低。

### 思路二

```cpp
class Solution
{
private:
    const vector<pair<int, string>> conv = { {1000, "M"}, 
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
```

这个方法很巧妙地解决了IV等两个字母的情况带来的问题，而且采用的是一个个减去的方式，这样的思路很清晰，效率也很高。