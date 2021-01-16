## Two Types of Spells
**Problem:**[Two Types of Spells](https://codeforces.com/contest/1398/problem/E?locale=en) \
**File:**[Two Types of Spells](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture04/twoTypesSpells.cpp) \
**Solution:** 
Considering a set of s spells, if there are l < s lightning spells the total number of doubled damage is l, to maximise the damage we can select the ones with highest values.
The idea is to keep two binary search tree:
- one stores the spells whose value is doubled, and we call it doubling tree;
- the other keeps the remaining spells, and we call it the spells tree.\
When we insert a new spell
- if it is fire, we check if it is bigger than the minimum in doubling tree and eventually substitute it, otherwise insert it in spells.
- if it is lightning, we insert it in spells and move the spell with the highest value from spells tree to doubling tree.\
When we remove a spell
- if it is fire, simply remove it, if it was in doubling tree, add in the tree the biggest from spells tree;
- if it is lightning, remove it, if it was in spells tree, we move the smallest element in doubling tree to spells tree.\
The total damage is computed dynamically during these operations.\
  If all the biggest elements are lightning we have to consider that we can double only l-1 lightnings, because they appear in a sequence.
  
**Time complexity:** &theta;(nlogn), n number of changes to the spells set, at most n of the mentioned operations, each of then has a logarithmic cost. \
**Space complexity:** &theta;(n).