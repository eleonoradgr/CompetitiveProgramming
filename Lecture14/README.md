## Triplets
**Problem:**[Triplets](https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14022018.pdf) \
**File:**[Triplets](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture14/triplets.cpp) \
**Solution:** To solve this problem, we use two Fenwick trees. The first helps build a vector that maintains at position i the number of elements less than to the element at that position in the sequence. The second helps build a vector that keeps at position i the number of elements greater than the elements in that position in the sequence.
The result is the sum of the products among the values at the same position in the two vectors.\
**Time complexity:** &theta;(nlogn), n is the length of the sequence\
**Space complexity:** &theta;(n).

## Smaller values
**Problem:**[Smaller values](https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14012019.pdf) \
**File:**[Smaller values](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture14/smallerValues.cpp) \
**Solution:**  Given queries in the form (start, end, val), we order them according to value. Then we order the sequence in increasing order, keeping track of the original position of the elements. We build a Fenwick tree, and we process the queries according to the previous defined order.
We add to the Fenwick tree the value 1 to all the position for which the value of the element in the sequence was less than the query value; we do this incrementally, processing queries and sequence.
Following this strategy, when we process the query with a specific value, we have that sum(i) in the Fenwick tree is the number of elements less than val from 0 to i. We obtain the result as the difference among sum(end) and sum(start-1).\
**Time complexity:** &theta;((n+m)logn), n the length of sequence and m the number of queries. \
**Space complexity:** &theta;(n+m).