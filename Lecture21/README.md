## Edit Distance
**Problem:**[Edit Distance](https://practice.geeksforgeeks.org/problems/edit-distance3702/1) \
**File:**[Edit Distance](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture21/editDistance.cpp) \
**Solution:** Given two strings of length l<sub>1</sub> and l<sub>2</sub>, we build a matrix A of size (l<sub>1</sub>+1)&times;(l<sub>2</sub>+1).\
Elements A[i][0] and A[0][i] are equal to i. The value of A[i][j] is equal to:
- min(A[i-1][j]+1,A[i][j-1]+1,A[i-1][j-1]),if i<sup>th</sup> letter's value is equal to j<sup>th</sup> letter's value of the two strings,
  that means respectively add a new letter, remove a letter, match that letters; 
- min(A[i-1][j]+1,A[i][j-1]+1,A[i-1][j-1]+1),if i<sup>th</sup> letter's value is not equal to j<sup>th</sup> letter's value of the two strings,
  that means respectively add a new letter, remove a letter, replace a letters;
  
The Result is at position A[l<sub>1</sub>][l<sub>2</sub>].\
  **Time complexity:** &theta;((l<sub>1</sub>+1)&times;(l<sub>2</sub>+1)).\
**Space complexity:** &theta;((l<sub>1</sub>+1)&times;(l<sub>2</sub>+1)).

## Vertex Cover
**Problem:**[Vertex Cover](https://www.spoj.com/problems/PT07X/) \
**File:**[Vertex Cover](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture21/vertexCover.cpp) \
**Solution:** To solve this problem, we choose one of the nodes as the root of the tree. The solution id the minimum among the dimension of the vertex cover if it is part of it or if it is not. In the first case, we continue recursively considering that al its children
can be part or not of the vertex cover. In the second case, all its children must be part of the vertex cover.\
We process all the nodes in this way recursively; the m remains linear thanks to memoization, the solution for a certain subtree are stored
in the node that is the root of it.\
**Time complexity:** &theta;(n).\
**Space complexity:** &theta;(n).\
**File:**[Vertex Cover 2](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture21/vertexCover2.cpp) contains a quadratic solution, that starts from the leaves,choosing to exclude them from the vertex cover.

## Longest Palindromic Subsequence
**Problem:**[Longest Palindromic Subsequence](https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0#) \
**File:**[Longest Palindromic Subsequence](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture21/palindSub.cpp) \
**Solution:** Given a string of length n, we build a matrix A of size (n+1)&times;(n+1), initialized with all 0s.\
A[i][j] ids equal to the maximum among:
- A[i-1][j], A[i][j-1] and A[i-1][j-1]+1, if the character at position i is equal to that at position n-j.
- A[i-1][j], A[i][j-1] and A[i-1][j-1], otherwise.

This problem is similar to that of the largest common subsequence but the strings compared are the reverse of each other.
The solution i at position A[n][n].\
**Time complexity:** &theta;(n<sup>2</sup>).\
**Space complexity:** &theta;(n<sup>2</sup>).
