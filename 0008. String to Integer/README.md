# 思路(C++)

这题其实不难，就是要考虑到的情况有点多。还有要想到可以用long long存目标整数，方便判断是否overflow。

## 思路一

外层for加内层while，用同一个循环变量。可以用string的find_not_of(char )方法判断第一个非空格字符的索引值。然后从该索引值开始不断*10+当前位转成整数。并判断是否会越界。符号先判断好，最后再乘上去。
