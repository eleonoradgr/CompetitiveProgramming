## Update the array
**Problem:**[Update the array](https://www.spoj.com/problems/UPDATEIT/) \
**File:**[Update the array](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture09/updateArray.cpp) \
**Solution:** To solve the problem, we use a Fenwick tree. For each update (l,r,v)  we add v to l index and -v to r+1 index in logarithmic time,
then to answer to a query q we must perform the prefix sum up to that point, that the Fenwick tree performs in logarithmic time.\
**Time complexity:** &theta;((u+q)logn), where n is the length of the array, u thenumber of updates and q the number of queries.\
**Space complexity:** &theta;(n), fenwick tree is an implicit data structure.