# 思路(C++)
- 这题如果没有把握好方向，盲目用两个下标指针来依次移动，会有很多的情况(corner cases)需要处理，很容易出漏洞。
## 思路一
**空间换时间**：将两个有序数组归并进一个目标有序总序列，最后返回总序列的中间值。这样就是需要一个大小为两序列长度和的数组来存归并后的数组，但是时间复杂度可以降到最低。返回中位数值的时候，可以返回(num[mid] + num[mid + num.size() - 1])/2.0（其中mid = (nums1.size() + nums2.size())/2)。
## 思路二
>> 来自leetcode discuss的[高赞回答](https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2588/O(lg(m%2Bn))-c%2B%2B-solution-using-kth-smallest-number)

### “查找第k大的数“函数：findKth()

我们有两个数组
```
nums1[0], nums1[1]....nums1[m - 1];
nums2[0], nums2[2]....nums2[n - 1];
```
按序合并后的结果为：

`num[0],num[1],num[2]...num[m + n - 1];`

num[k - 1]为数组num里第k大的数

比较nums1[k/2 - 1] 和 nums2[k/2 - 1]

结论：如果 nums1[k/2 - 1] < nums2[k/2 - 1]
则nums1[k/2 - 1]和它左边的数都比num[]里第k大的数小(即, num[k - 1])

证明：因为，极端情况就是，nums2的nums2[0...k/2 - 2]都比nums1[k/2 - 1]小，这时候，加上nums1[k/2 - 1]和它左边的k/2 - 1个数，比nums1[k/2 - 1]小的数共有k/2 - 1 + k/2 - 1 = k - 2个数，所以，算上nums1[k/2 - 1]本身，就有k-1个数比num的第k个数num[k-1]小。（ nums1[k/2 - 1] > nums2[k/2 - 1]的情况也类似）

利用以上结论，就可以用递归的方法，不断缩小查找范围，直到找到目标。这种方式空间复杂度最低。

### 注意点
思路二的一个注意点就是，当size1 < k/2 的情况，nums1缩小的范围就应该size1，即整个nums1。这个通过min(k/2, size1)来解决。还有就是为了方便处理，统一将当前元素少的数组放在前面。
