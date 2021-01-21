## Knapsack Problem
**Problem:**[Knapsack Problem](https://www.spoj.com/problems/KNAPSACK/) \
**File:**[Knapsack Problem](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture19/knapsack01.cpp) \
**Solution:**  Given n the number of elements and c the maximum capacity, we build a matrix A of size (n+1) $\times$ (c+1). We initialize it with all zeros and then A[i][j] is
the max among A[i-1][j], if we don't select the i-th item, and A[i-1][j- w<sub>i</sub>] + v<sub>i</sub>, if we select it, where w<sub>i</sub> is the weight and v<sub>i</sub> is the value.
The result is at cell A[n][c].\
$$
A[i][j]= max
\begin{cases}
k[i-1][j] &\text{if we do not select the ith item} \\
k[i-1][j-w_i] +v_i &\text{if we select the ith item }.
\end{cases}
$$
$$X = \begin{bmatrix}1 & x_{1}\\
1 & x_{2}\\
1 & x_{3}
\end{bmatrix}$$
**Time complexity:** &theta;(nc).\
**Space complexity:** &theta;(nc).