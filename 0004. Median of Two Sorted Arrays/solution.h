#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // method 1: space for time
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t s1 = nums1.size(), s2 = nums2.size(), mid = (s1 + s2) >> 1, i = 0, j = 0;
        vector<int> tmp;
        while (i < s1 && j < s2)
        {
            if (nums1[i] < nums2[j])
            {
                tmp.push_back(nums1[i++]);
            }
            else
            {
                tmp.push_back(nums2[j++]);
            }
        }
        if (i != s1)
        {
            while (i < s1) tmp.push_back(nums1[i++]);
        }
        else {
            while (j < s2) tmp.push_back(nums2[j++]);
        }
        return (tmp[mid] + tmp[tmp.size() - 1 - mid]) * 0.5;
    }
    
    // method 2: find-Kth-smallest-element Function, recursion version
    int findKth(const vector<int>& nums1, size_t nums1left, size_t nums1right, const vector<int>& nums2, size_t nums2left, size_t nums2right, size_t k) {
        size_t s1 = nums1right - nums1left;
        size_t s2 = nums2right - nums2left;
        // make sure that size1 < size2 for easily handle the case where s1 < k/2
        if (s1 > s2) return findKth(nums2, nums2left, nums2right, nums1, nums1left, nums1right, k);
        // obvious case
        if (s1 == 0) return nums2[nums2left + k - 1];
        // for k/2 - 1 < 0 now
        if (k == 1) return min(nums1[nums1left], nums2[nums2left]);

        size_t s1left = min(s1, k / 2);
        size_t s2left = k - s1left;

        if (nums1[nums1left + s1left - 1] == nums2[nums2left + s2left - 1])
        {
            // the two are k-1th and kth in num[] respectively
            return nums1[nums1left + s1left - 1];
        }
        else if (nums1[nums1left + s1left - 1] < nums2[nums2left + s2left - 1])
        {
            return findKth(nums1, nums1left + s1left, nums1right, nums2, nums2left, nums2right, k - s1left);
        }
        else
        {
            return findKth(nums1, nums1left, nums1right, nums2, nums2left + s2left, nums2right, k - s2left);
        }
    }
    double findMedianSortedArraysRecursion(vector<int>& nums1, vector<int>& nums2) {
        size_t s1 = nums1.size(), s2 = nums2.size(), mid = (s1 + s2) >> 1;
        int num1 = findKth(nums1, 0, s1, nums2, 0, s2, mid + 1);
        if ((s1 + s2) % 2 == 0)
        {
            int num2 = findKth(nums1, 0, s1, nums2, 0, s2, mid);
            return (num1 + num2) * 0.5;
        }
        return num1 * 1.0;
    }
};