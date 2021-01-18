## Nested segments
**Problem:**[Nested Segments](https://codeforces.com/problemset/problem/652/D) \
**File:**[Nested Segments](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture10/nestedSegment.cpp) \
**Solution:** To solve the problem, we use a Fenwick tree. We remap the values of all the segments boundaries, such that they are among 0 and 2n, given n segments.
The Fenwick tree maintains at index i the number of segments that starts after that position. Segments are sorted according to increasing end and then evaluated.
For each segment we return the sum stored at the Fenwick tree's value in the starting position of the segment, it represents the number of segments that starts after the segment and ends before it due to the ordering.
Then we add 1 at the beginning of the Fenwick tree and -1 at the segment's starting position.\
**Time complexity:** &theta;(nlogn), where n is the number of segments.\
**Space complexity:** &theta;(n), fenwick tree is an implicit data structure.

## Pashmak and Parmida's problem
**Problem:**[Pashmak and Parmida's problem](https://codeforces.com/problemset/problem/459/D?locale=en) \
**File:**[Pashmak and Parmida's problem](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture10/pashpar.cpp) \
**Solution:** We use an hashtable (unordered_map) to build two vectors that maintain respectively the values f(1,i,a<sub>i</sub>) and f(j,n,a<sub>j</sub>).
We use a Fenwick tree such that the sum at the position i is the number of times f(j,n,a<sub>j</sub>) is smaller than the value i. In this way we can compute in logarithmic time 
the number of j such that f(1,i,a<sub>i</sub>) > f(j,n,a<sub>j</sub>), fixed the i.\
**Time complexity:** &theta;(nlogn), where n is the length of sequence.\
**Space complexity:** &theta;(n).

