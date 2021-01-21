## Powerful array
**Problem:**[Powerful array](http://codeforces.com/contest/86/problem/D) \
**File:**[Powerful array](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture16/powarray.cpp) \
**Solution:** The solution to this problem is the application of Mo's algorithm. 
Once the queries are ordered according to membership in √n size block of their starting point and then according to their endpoint in each block, we compute the results keeping trace of each value's occurrences in the sequence, for this reason, we remap the original sequence. \
Every time there is a new element n the interval queries we increment the occurrence, we remove the previous contribution from the result, and we add the new one; vice versa for the deletion of an element.\
**Time complexity:** &theta;(tlogt + (n+t)&radic;n), n is the sequence length and t the number of queries.\
**Space complexity:** &theta;(n+t).

## Tree and queries
**Problem:**[Tree and queries](http://codeforces.com/contest/375/problem/D) \
**File:**[Tree and queries](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture16/treeandq.cpp) \
**Solution:**  To solve the problem, we build a structure such that each node is associated with a segment which contains all the elements of its subtree. Answering the queries is an application of Mo's algorithm indeed at that point asking how many colours appears more than k times ina a subtree means asking the same thing for the segment.\
The queries are ordered according to their membership in √n size block of their starting position and then according to their endpoint in each block.\
We compute the result keeping trace of each colour's occurrences and, in particular, the number of times the occurrences are bigger than a certain value, to do this the colours are remapped.\
Every time there is a new element in the interval query, we increment the occurrences and the values of "biggerthan", vice versa for the deletion of an element.\
**Time complexity:** &theta;(mlogm + (m+n)&radic;n), n is the sequence length and m the number of queries.\
**Space complexity:** &theta;(n+m).