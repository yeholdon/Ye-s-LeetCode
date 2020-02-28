#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// number-index map
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> integer_map;
        vector<int> result;
        for (unsigned int i = 0; i < numbers.size(); i++){
            if(integer_map.find(target - numbers[i]) != integer_map.end()){
                result.push_back(integer_map[target - numbers[i]]);
                result.push_back(i);
                return result;
            }
            integer_map[numbers.at(i)] = i;
        }
        return {-1, -1};
    }
};

/* 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> record;
        for (int i = 0; i != nums.size(); ++i) {
            auto found = record.find(nums[i]);
            if (found != record.end())
                return {found->second, i};
            record.emplace(target - nums[i], i); // emplace()直接构造，避免临时变量
        }
        return {-1, -1};
    }
};
*/
