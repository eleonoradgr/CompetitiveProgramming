## N meetings in one room
**Problem:**[N meetings in one room](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1) \
**File:**[N meetings in one room](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture22/meetings.cpp) \
**Solution:** To solve the activity selection problem, we sort activities according to their increasing ending time.\
We start selecting the activity that ends first, and then we continue choosing those that begin after that the last selected ended.\
**Time complexity:** &theta;(nlogn), given n activities.\
**Space complexity:** &theta;(n).

## Magic Number
**Problem:**[Magic Number](http://codeforces.com/problemset/problem/320/A?locale=en) \
**File:**[Magic Number](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture22/magicnumbers.cpp) \
**Solution:** We process the sequence starting from the end, to the beginning.
- If we find a 4 for the first time, we expect a 1 or a 4 as next element.
- If we find a 4 for the second time, we expect a 1 as next element.
- If we find a 1, we don't have constraints on the next processed elements.(That can be only 1 or 4)
  
If we scan the whole sequence without violating the constraints, the answer is YES, otherwise NO.\
**Time complexity:** &Omicron;(n), where n is the length of the sequence.\
**Space complexity:** &theta;(n).

## Wilbur and Array
**Problem:**[Wilbur and Array](http://codeforces.com/problemset/problem/596/B) \
**File:**[Wilbur and Array](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture22/wilbur.cpp) \
**Solution:** Change the first value 0 to b<sub>1</sub> costs b<sub>1</sub> operations, and then changing a<sub>2</sub>, that has become equal to b<sub>1</sub>, to b<sub>2</sub> costs
abs(b<sub>2</sub> - b<sub>1</sub>). We continue counting operations with this strategy.\
**Time complexity:** &theta;(n).\
**Space complexity:** &theta;(n).\
**File:**[Wilbur and Array 2](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture22/wilburarray.cpp) provides a &theta;(nlogn) solution using Fenwick tree.

## Alternative Thinking
**Problem:**[Alternative Thinking](http://codeforces.com/problemset/problem/603/A?locale=en) \
**File:**[Alternative Thinking](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture22/altthink.cpp) \
**Solution:** First, we count the length of the alternating subsequence as it is given in input. At this point, if the size of subsequences found is less or equal to n-2 means that there is at least a subsequence of "00" or "11"(example: 01011101) for which we can change at least a value such that we can add 2 to the previous result.
If the length is n-1, we can add 1; indeed, we can switch the sequence from the value that is not part of the result till the end.\
**Time complexity:** &theta;(n).\
**Space complexity:** &theta;(n).