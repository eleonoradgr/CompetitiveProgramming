## Maximum Path Sum
**Problem:**[Maximum Path Sum between 2 Leaf Nodes](https://practice.geeksforgeeks.org/problems/maximum-path-sum/1) \
**File:**[Maximum Path Sum between 2 Leaf Nodes](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture06/maxPathSum.cpp) \
**Solution:** A postorder visit of the tree is performed, each node receives from its children (if they exist) two values, 
the max path found in the subtree and the max value to reach a leaf from the parent node, in this way the node can compute the value of 
the path that passes through itself and eventually updates the maximum sum.
The maximum computed in the root node is the solution.\
**Time complexity:** &theta;(n). \
**Space complexity:** &theta;(n).

##  Longest k-Good Segment
**Problem:**[ Longest k-Good Segment](https://codeforces.com/contest/616/problem/D?locale=en) \
**File:**[ Longest k-Good Segment](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture06/kGood.cpp) \
**Solution:** To solve this problem we use an hash_table (unordered_map), for each element of the array three situations may occur:
* if it is a new element and the number of different values is less than k, we insert it in the hash table with occurrences set to 1, and we update the length of the current segment;
* If the different values are more than or equal to k, we remove from the hash table the value at the beginning of the segment and all the elements until all the value occurrences are no longer present in the segment. 
  Since we know the elements' occurrences to delete, the algorithm remains linear; indeed, once the elements are visited, we delete them from the segment, and they are not reached anymore.
* If the value has already at least one occurrence in the segment, we increase its value in the hashtable and the length of the current segment.
  
During all these operations the indexes of the segments with max length are kept.\
**Time complexity:** &theta;(n), since operations performed on the hashtable are constant on average. \
**Space complexity:** &theta;(n).