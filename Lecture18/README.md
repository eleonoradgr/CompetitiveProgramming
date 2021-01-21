## Minimum number of jumps
**Problem:**[Minimum number of jumps](https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1) \
**File:**[Minimum number of jumps](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture18/minJumps.cpp) \
**Solution:** Given an array of integers, we build another one of same dimension n.
We initialize it with all zeros, and we store at position i the minimum number of jumps to reach position i, 
for each element in the original array we check all the positions that we can go with the increment given by its value. \
For each element, we consider the minimum among the actual value for that position and the number of jumps needed to reach the element from which we came plus one.\
The solution is the last element of the built array.\
**Time complexity:** &theta;(n<sup>2</sup>).\
**Space complexity:** &theta;(n).