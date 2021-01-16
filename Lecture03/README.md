## Inversion Count
**Problem:**[Inversion Count](https://www.spoj.com/problems/INVCNT/) \
**File:**[Inversion Count](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture03/inversionCount.cpp) \
**Solution:** Order the array through merge sort, in the merge process, considering i the index of left sub-array, if the element in the right sub-array is smaller than the element in the left sub-array, then there are (sizeof(left sub-array) – i) inversions.
Because the left and right sub-arrays are sorted, all the remaining elements in left-subarray have to be counted as inversions. \
**Time complexity:** &theta;(n logn). \
**Space complexity:** &theta;(n logn).
## Largest Even Number
**Problem:**[Largest even number](https://practice.geeksforgeeks.org/problems/largest-even-number/0) \
**File:**[Largest even number](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture03/largestEvenNumber.cpp) \
**Solution:** All the digit and their occurrences are identified through a first scan, and then two other scans over the sequence of digit occurrences are needed. 
The first one identifies the smallest even digit to put at the end of the number; the second one inserts digits in decreasing order at the beginning of the number. \
**Time complexity:**&theta;(n), where n is the length of the number. \
**Space complexity:**&theta;(n+d), d the number of digits.
## The Monkey and the Oiled Bamboo
**Problem:**[The Monkey and the Oiled Bamboo](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3183) \
**File:**[The Monkey and the Oiled Bamboo](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture03/mokeyBamboo.cpp) \
**Solution:** To evaluate the minimum value of k, we consider the lengths of the rungs from the end to the beginning. 
Initially, k is zero, then if a rung length is greater than k, k is updated with the rung length, if it is equal to the value of k, k is incremented by one.\
**Time complexity:**&theta;(n), where n is the number of the rungs. \
**Space complexity:** &theta;(n).