## Ilya and Queries
**Problem:**[Ilya and Queries](http://codeforces.com/problemset/problem/313/B?locale=en) \
**File:**[Ilya and Queries](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture07/ilyaQueries.cpp) \
**Solution:** We build a prefix sum vector, it maintains at position i the number of consecutive equal values 
from the beginning of the string to the i<sup>th</sup> character. To answer to the m queries, that are intervals, 
just return the difference among  vector values at the end and at the beginning of the interval.\
**Time complexity:** &theta;(n + m), where n is the length of the string and m the number of queries.\
**Space complexity:** &theta;(n).

## Number of Ways
**Problem:**[Number of Ways](http://codeforces.com/problemset/problem/466/C?locale=en) \
**File:** [Number of Ways](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture07/numberOfWays.cpp) \
**Solution:** To solve the problem, the total sum of the array elements must be a multiple of three, say 3s, and the sum of values of
each segment must be s. So we build a suffix vector where we store the number of segments with total sum s from i to the end at position i.
We scan the array from the beginning, each time the prefix sum is equal to s, let's say at position x, we count as a way of splitting the array
the number stored in the suffix vector at position x+2.\
**Time complexity:** &theta;(n), where n is the length of the array. \
**Space complexity:** &theta;(n).

## Little Girl and Maximum Sum
**Problem:**[Little Girl and Maximum Sum](http://codeforces.com/problemset/problem/276/C?locale=en) \
**File:** [Little Girl and Maximum Sum](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture07/littleGirl.cpp) \
**Solution:** To solve the problem we build a vector to keep track of the queried elements, in particular, given a certain query l<sub>i</sub> r<sub>i</sub>, we add 1 to position l<sub>i</sub> and -1 to position r<sub>i</sub>+1, after that a prefix sum is performed such that in the vector is stored the number of times the element is accessed.
This vector is sorted, as the vector containing the values of elements, so the result is computed summing up the products among the number of accesses and the element's value.\
**Time complexity:** &theta;(nlogn),  where n is the number of elements. \
**Space complexity:** &theta;(n+q),  where n is the number of elementsand q number of elements.