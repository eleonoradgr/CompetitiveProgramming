## Next larger element
**Problem:**[Next larger element](https://practice.geeksforgeeks.org/problems/next-larger-element/0) \
**Solution:** To solve this problem you have to scan the sequence and insert each element in a queue, then you compare this with the previous ones until
they are smaller than the current element, in this case you remove them from the queue establishing the current element as the next larger. \
**Time complexity:** &theta;(n), you insert each element at most one in the queue and if it is compared with m previous elements it means that at least m-1 are smaller and they are removed 
from the queue, so the number of comparisons remains linear. \
**Space complexity:** &theta;(n).
## Towers
**Problem:**[Towers](http://codeforces.com/problemset/problem/37/A?locale=en) \
**Solution:** Considering that the length of the wooden bars is limited (minor than the number of bars) you can initialize a vector of length n and
for every bar you increment the element in the position equal to his length, keeping track of the max height, the length of bars which compose the highest tower so far 
and the different towers. (If the length is not limited a solution could be ordering the sequence of bars according to their length) \
**Time complexity:** &theta;(n). \
**Space complexity:** &Omicron;(n).
## Find team members
**Problem:**[Find team members](http://codeforces.com/problemset/problem/579/B?locale=en) \
**Solution:** Given 2n people,order the possible couples according to the strength of pair and than start to create pairs according to max strength. \
**Time complexity:** &Omicron;( n<sup>2</sup>2logn).\
**Time complexity:** &theta;(n<sup>2</sup>).
