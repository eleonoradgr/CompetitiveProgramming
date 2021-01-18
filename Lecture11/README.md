## Nested segments
**Problem:**[Nested Segments](https://codeforces.com/problemset/problem/652/D) \
**File:**[Nested Segments](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture11/nestedSegment2.cpp) \
**Solution:** To solve the problem, we use a segment tree. We remap the values of all the segments boundaries, such that they are among 0 and 2n, given n segments.
We order the segments in increasing order of their ending point. For each segment, we return the sum stored in the segment tree among the starting and ending position. It represents the number of nested segments; in this way we count only elements starting after it and finishing before it, the others are not still present. Then we update the segment tree adding 1 to the starting position
of the segment.\
**Time complexity:** &theta;(nlogn), where n is the number of segments.\
**Space complexity:** &theta;(n).