##Leaders in an array
**Problem:** [Leaders in an array](https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0) \
**Solution:** Scan the sequence from the end to the beginning keeping track of the maximum element,
if an element is larger than the maximum it is a leader.\
**Time complexity:** &theta;(n). \
**Space complexity:** &theta;(n), the vector containing solutions.
##Kandane's algorithm
**Problem:** [Kandanes's algorithm](https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0) \
**Solution:** To find the contiguous sub-array with maximum sum you have to consider that that the sum of any prefix in the sub-array can't be a negative value,
otherwise you would obtain a better solution excluding it. The solution is obtained scanning the sequence from the beginning keeping track of 
the max sum found, if you meet a positive integer you include it in the current sub-array, if you meet a negative integer you can add 
it to the sub-array only if the total sum is greater than 0, otherwise you start counting the sum for a new sub-array from the next element.\
**Time complexity:**  &theta;(n). \
**Space complexity:** Constant.
##Missing number
**Problem:** [Missing number](https://practice.geeksforgeeks.org/problems/missing-number-in-array/0) \
**Solution:** Considering that the sum of the first n integers is n * (n + 1) / 2, you have to scan the sequence and subtract
the values of each element from the value obtained through the previous formula, the remaining value is the solution.\
**Time complexity:**  &theta;(n). \
**Space complexity:** Constant.
##Trapping rain water
**Problem:** [Trapping rain water](https://practice.geeksforgeeks.org/problems/trapping-rain-water/0)\
**Solution:** For each element of the sequence, you must keep track of the maximum element on his left side and the maximum element on his right side, to do this
two scans of the sequence are needed, from the beginning to the end for the max on the right and vice versa. Once you identify the two max for each position the value of
water over there is given subtracting to the minor max the value of that position.\
**Time Complexity:**&theta;(n).\
**Space Complexity:**&theta;(n).
##Sliding window maximum
**Problem:** [Sliding window maximum](https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0)\
**Solution:** The solution consists of using a queue to keep track of the greatest value within the subarray and his position, you have to iterate 
over all the element of the sequence, every time you have to check if the first element of the queue is in the range of the sliding window, if it's not, remove it,
than you have to push the element and his position to the tail of the queue and remove all the elements above it until you find a larger element or the queue is empty, 
the head of the queue is the maximum of the current window.\
**Time Complexity:**&theta;(n),you insert each element at most one in the queue and if it is compared with m previous elements it means that at least m-1 are smaller and they are removed
from the queue, so the number of comparisons remains linear.\
**Space Complexity:**&theta;(n).