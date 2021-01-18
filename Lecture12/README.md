## Circular RMQ
**Problem:**[Circular RMQ](https://codeforces.com/problemset/problem/52/C) \
**File:**[Circular RMQ](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture12/crmq.cpp) \
**Solution:**  To solve the problem, we use a lazy segment tree. The nodes of the trees store the minimum value present in the subarray, such that the query for the minimum is logarithmic. 
The updates are logarithmic too, we keep them in a lazy tree, and we need that value they are applied. 
We manage circular queries as they were two regular queries, and then we combine their results.\
**Time complexity:** &theta;(n+qlogn), where n is the length of the sequence and q is the number of queries and updates.\
**Space complexity:** &theta;(n+q) in the implementation we store all the resulting values before printing.