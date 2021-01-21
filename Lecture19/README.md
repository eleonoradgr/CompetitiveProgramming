## Knapsack Problem
**Problem:**[Knapsack Problem](https://www.spoj.com/problems/KNAPSACK/) \
**File:**[Knapsack Problem](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture19/knapsack01.cpp) \
**Solution:**Given n the number of elements and c the maximum capacity, we build a matrix A of size (n+1)\*(c+1). We initialize it with all zeros and then fill it as:
$$
A[i][j]= max
\begin{cases}
k[i-1][j] &\text{if we do not select the ith item} \\
k[i-1][j-w_i] +v_i &\text{if we select the ith item }.
\end{cases}
$$
The result is at cell A\[n\]\[c\].\\
**Time complexity:** &theta;(n\*c).\\
**Space complexity:** &theta;(n\*c).\\