## Leaders in an array
**Problem:** [Leaders in an array](https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0) \
**File:** [Leaders in an array](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture01/leaders.cpp) \
**Solution:** Scan the sequence from the end to the beginning keeping track of the maximum element,
if an element is larger than the maximum it is a leader.\
**Time complexity:** &theta;(n). \
**Space complexity:** &theta;(n), original sequence and the vector containing solutions. 
## Kandane's algorithm
**Problem:** [Kandanes's algorithm](https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0) \
**File:** [Kandanes's algorithm](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture01/kadane.cpp) \
**Solution:** To find the contiguous sub-array with the maximum sum, we have to consider that the sum of any prefix in the sub-array can't be a negative value;
otherwise, we would obtain a better solution excluding it. The solution is obtained scanning the sequence from the beginning keeping track of 
the max sum found; if we meet a positive integer, we include it in the current sub-array, if we meet a negative integer we can add 
it to the sub-array only if the total sum is greater than 0; otherwise we start counting the sum for a new sub-array from the next element.\
**Time complexity:**  &theta;(n). \
**Space complexity:** &theta;(n),the original array is stored in the implementation provided, space is constant if elements are used as soon as they are read from input. 
## Missing number
**Problem:** [Missing number](https://practice.geeksforgeeks.org/problems/missing-number-in-array/0) \
**File:** [Missing number](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture01/missingNumber.cpp) \
**Solution 1:** Considering that the sum of the first n integers is n * (n + 1) / 2, we have to scan the sequence and subtract
each element's values from the value obtained through the previous formula; the remaining value is the solution.\
**Time complexity:**  &theta;(n). \
**Space complexity:** &theta;(n), the original sequence  is stored in the implementation provided, space is constant if elements are used as soon as they are read from input.\
**File:** [Missing number](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture01/missingNumberXOR.cpp) \
**Solution 2:** Considering that x &oplus;  x = 0, compute &oplus; of first n elements and then compute the &oplus; of the elements in the sequence;
the resulting value is the solution.\
**Time complexity:**  &theta;(n). \
**Space complexity:** &theta;(n), the original sequence  is stored in the implementation provided; space is logarithmic if elements are stored using bitset.
## Trapping rain water
**Problem:** [Trapping rain water](https://practice.geeksforgeeks.org/problems/trapping-rain-water/0) \
**File:** [Trapping rain water](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture01/trappingWater.cpp) \
**Solution:** For each element of the sequence, we must keep track of the maximum element on his left side and the maximum element on his right side, to do this
two scans of the sequence are needed, from the beginning to the end for the max on the right and vice versa. Once we identify the two maximum for each position, the value of
water over there is obtained subtracting to the minor max the value of that position.\
**Time Complexity:**&theta;(n).\
**Space Complexity:**&theta;(n). 
## Sliding window maximum
**Problem:** [Sliding window maximum](https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0) \
**File:** [Sliding window maximum](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture01/slidingWinMax.cpp) \
**Solution:** The solution consists of using a queue to keep track of the greatest value within the subarray and its position. You have to iterate 
over all the elements of the sequence, every time we have to check if the first element of the queue is in the range of the sliding window, if it's not, pull it,
then we have to push the element and its position to the queue's tail and remove all the elements above it until we find a larger element or the queue is empty, 
the head of the queue is the maximum of the current window.\
**Time Complexity:**&theta;(n),we insert each element at most once in the queue and if it is compared with m previous elements, it means that at least m-1 are smaller and they are removed
from the queue, so the number of comparisons remains linear.\
**Space Complexity:**&theta;(n). 