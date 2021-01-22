## Longest Increasing Subsequence
**Problem:**[Longest Increasing Subsequence](https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1) \
**File:**[Longest Increasing Subsequence](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture20/lis.cpp) \
**Solution:** To solve this problem, we use a binary search tree to keep all the elements of the longest increasing subsequence. 
Given an element, if it is greater than all the elements already inserted, we insert it. 
Otherwise, we insert it only if it is a dominating position, that means given i > j we have that the longest increasing subsequence till i is longer than the one till j,
and the value of i is less than or equal to those of j. After the insertion of a dominating element, we remove all the dominated elements that succeeded it.
The result is the size of the binary search tree.\
**Time complexity:** &theta;(nlogn).\
**Space complexity:** &theta;(n).

## Longest Bitonic Subsequence
**Problem:** [Longest Bitonic Subsequence](https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1) \
**File:**[Longest Bitonic Subsequence](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture20/lbs.cpp) \
**Solution:** Solving this problem means to find the position with the maximum sum of the longest increasing subsequence and the longest decreasing subsequence.\
In this case we build LIS[i] as 1 + maximum(LIS[j] | 1 <= j <= i and value_of(i) < value_of(j) ).
We build LDS[i] in the same way, starting from the reversed vector.\
**Time complexity:**  &theta;(n<sup>2</sup>), we don't use the previous algorithm to build LIS and LDS vectors.\
**Space complexity:** &theta;(n).