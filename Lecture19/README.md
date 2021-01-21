## Partition Equal Subset Sum
**Problem:**[Partition Equal Subset Sum](https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1) \
**File:**[Partition Equal Subset Sum](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture19/subset.cpp) \
**Solution:** To solve the problem, we first check if the total sum of the elements is a multiple of two. 
Then we build a matrix A of size (n+1) ×(sum+1); having the first row initialized with true and the first column with false.\
A[i][j] store true if there is a subset of sum j among the elements from 1 to i. If the i<sup>th</sup>element's value is greater than j, we have stored the solution in the previous row; 
indeed, the problem is the same without the last element. \
Otherwise A[i][j] is the ∨ among A[i-1][j] and A[i-1][j-value of i<sup>th</sup>],the case in which we can create a new subset with that item.
The result is at position A[last_row][sum/2]. \
**Time complexity:** &theta;(n&times;sum).\
**Space complexity:** &theta;(n&times;sum).
## Knapsack Problem
**Problem:**[Knapsack Problem](https://www.spoj.com/problems/KNAPSACK/) \
**File:**[Knapsack Problem](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture19/knapsack01.cpp) \
**Solution:**  Given n the number of elements and c the maximum capacity, we build a matrix A of size (n+1)&times;(c+1). We initialize it with all zeros and then A[i][j] is
the max among A[i-1][j], if we don't select the i-th item, and A[i-1][j- w<sub>i</sub>] + v<sub>i</sub>, if we select it, where w<sub>i</sub> is the weight and v<sub>i</sub> is the value.
The result is at cell A[n][c].\
**Time complexity:** &theta;(n&times;c).\
**Space complexity:** &theta;(n&times;c).