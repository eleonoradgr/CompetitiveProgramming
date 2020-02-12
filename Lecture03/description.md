##Inversion Count
**Problem:**[Inversion Count](https://www.spoj.com/problems/INVCNT/)\
**Solution:** Order the array through merge sort, in merge process, considering i the index of left sub-array, if the element in right sub-array is smaller than the element in the left sub-array,
 then there are (mid – i) inversions. This is because left and right sub-arrays are sorted, so all the remaining elements in left-subarray have to be counted as inversions. \
**Time complexity:** &theta;(n logn). \
**Space complexity:** &theta;(n).\
##Largest Even Number
**Problem:**[Largest even number](https://practice.geeksforgeeks.org/problems/largest-even-number/0)\
**Solution:** Through a first scan all the digit and their occurrences are identified and then two other scans over the sequence of digit occurrences are needed.
 The first one identifies the smallest even digit to put at the end of the number, the second one inserts digits in decreasing order at the beginning of number. \
**Time complexity:**&theta;(n), where n is the length of the number. \
**Space complexity:**&theta;(d), the number of digits.