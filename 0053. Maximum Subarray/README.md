# 思路(C++)

## 一、动态规划

dp[i]表示以第i个元素为结尾的最大子序列和。

递推方程：

- `dp[i] = max(dp[i-1] + nums[i], nums[i]) `

边界：

- `dp[0] = nums[i]`

时间复杂度：O(n)



## 二、分治法

>我们定义一个操作 get(a, l, r) 表示查询 a 序列 [l, r][l,r] 区间内的最大子段和，那么最终我们要求的答案就是 get(nums, 0, nums.size() - 1)。如何分治实现这个操作呢？对于一个区间 [l, r][l,r]，我们取m=⌊(l+r)/2⌋，对区间 [l, m][l,m] 和 [m + 1, r][m+1,r] 分治求解。当递归逐层深入直到区间长度缩小为 1 的时候，递归「开始回升」。这个时候我们考虑如何通过 [l, m][l,m] 区间的信息和 [m + 1, r][m+1,r] 区间的信息合并成区间 [l, r][l,r] 的信息。最关键的两个问题是：
>
>我们要维护区间的哪些信息呢？
>我们如何合并这些信息呢？
>对于一个区间 [l, r][l,r]，我们可以维护四个量：
>
>lSum 表示 [l, r][l,r] 内以 l 为左端点的最大子段和
>rSum 表示 [l, r][l,r] 内以 r 为右端点的最大子段和
>mSum 表示 [l, r][l,r] 内的最大子段和
>iSum 表示 [l, r][l,r] 的区间和
>以下简称 [l, m][l,m] 为 [l, r][l,r] 的「左子区间」，[m + 1, r][m+1,r] 为 [l, r][l,r] 的「右子区间」。我们考虑如何维护这些量呢（如何通过左右子区间的信息合并得到 [l, r][l,r] 的信息）？对于长度为 11 的区间 [i, i][i,i]，四个量的值都和ai相等。对于长度大于1的区间：
>
>首先最好维护的是 iSum，区间 [l, r][l,r] 的 iSum 就等于「左子区间」的 iSum 加上「右子区间」的 iSum。
>对于 [l, r][l,r] 的 lSum，存在两种可能，它要么等于「左子区间」的 lSum，要么等于「左子区间」的 iSum 加上「右子区间」的 lSum，二者取大。
>对于 [l, r][l,r] 的 rSum，同理，它要么等于「右子区间」的 rSum，要么等于「右子区间」的 iSum 加上「左子区间」的 rSum，二者取大。
>当计算好上面的三个量之后，就很好计算 [l, r][l,r] 的 mSum 了。我们可以考虑 [l, r][l,r] 的 mSum 对应的区间是否跨越 mm——它可能不跨越 mm，也就是说 [l, r][l,r] 的 mSum 可能是「左子区间」的 mSum 和 「右子区间」的 mSum 中的一个；它也可能跨越 mm，可能是「左子区间」的 rSum 和 「右子区间」的 lSum 求和。三者取大。
>这样问题就得到了解决。
>
>作者：LeetCode-Solution
>链接：https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
>来源：力扣（LeetCode）
>著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

虽然分治法的时间复杂度也是O(n)而且可能由于递归运行时间还要长点，但是这种方法的意义在于适用面更广，假设这题是求nums的任意子区间的最大子序列和。那么如果用动态规划就需要给每个子区间都用动归算法算一遍dp数组，而如果用这个线段树的分治法，就只需在开始的时候算一次总区间的线段树(维护的几个量)记录下来，后面任意子区间的答案就可以以O(log n)的复杂度查询得到。即线段树对于大规模区间的性质查询的问题求解有优势。

```cpp
class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};
```

