## Next larger element
**Problem:** [Next larger element](https://practice.geeksforgeeks.org/problems/next-larger-element/0) \
**File:** [Next larger element](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture02/nextLargerElem.cpp) \
**Solution:** To solve this problem we have to scan the sequence and insert each element in a queue; 
then we compare this with the previous ones until they are smaller than the current element, in this case, we remove them from the queue establishing the current element as the next larger. \
**Time complexity:** &theta;(n), we insert each element at most once in the queue, and if it is compared with m previous elements it means that at least m-1 are smaller and they are removed 
from the queue, so the number of comparisons remains linear. \
**Space complexity:** &theta;(n).
## Towers
**Problem:** [Towers](http://codeforces.com/problemset/problem/37/A?locale=en) \
**File:** [Towers](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture02/towers.cpp) \
**Solution:** Considering that the length of the wooden bars is limited (minor than the number of bars) we can initialize a vector of length n, and
for every bar we increment the element in the position equal to his length, keeping track of the  height of the highest tower so far 
and the different towers. (If the length is not limited a solution could be obtained ordering the sequence of bars according to their length) \
**Time complexity:** &theta;(n). \
**Space complexity:** &theta;(n).
## Find team members
**Problem:** [Find team members](http://codeforces.com/problemset/problem/579/B?locale=en) \
**File:** [Find team members](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture02/findTeamMemebers.cpp) \
**Solution:** Given 2n people, order the possible couples according to the strength of pair and then start to create teams according to max strength. \
**Time complexity:** &Omicron;( n<sup>2</sup>logn).\
**Space complexity:** &theta;(n<sup>2</sup>).
