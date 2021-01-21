## Longest Common Subsequence
**Problem:**[Longest Common Subsequence](https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1) \
**File:**[Longest Common Subsequence](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture17/Lcs.cpp) \
**Solution:** Given two sequence of lengths l<sub>1</sub> and l<sub>2</sub>, we build a matrix A of size l<sub>1</sub> &times; l<sub>2</sub>.
The first row and the first column are set to 0. Then for each position A[i][j], we assign A[i-1][j-1]+1 if the elements at position i and j of the sequences are equal,
otherwise the maximum among a[i-1][j] and a[i][j-1]. We return the value at A[l<sub>1</sub>][l<sub>2</sub>].\
**Time complexity:** &theta;(l<sub>1</sub> &times; l<sub>2</sub>).\
**Space complexity:** &theta;(l<sub>1</sub> &times; l<sub>2</sub>).
