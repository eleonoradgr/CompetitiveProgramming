## Frog and Mosquitoes
**Problem:**[Frog and Mosquitoes](https://codeforces.com/contest/609/problem/F?locale=en) \
**File:**[Frog and Mosquitoes](https://github.com/eleonoradgr/CompetitiveProgramming/blob/master/Lecture05/frogsMosquitoes.cpp) \
**Solution:**\
Data structures used to solve the problem:
- vector of frog structs, each of them keeps the number of the frog, the initial position, the length of the tongue and the number of eaten mosquitoes;
- binary search tree of frogs seen as non-overlapping segments, built once all the data about frogs are known;
- binary search tree for pairs that represent the uneaten mosquitoes.\

For each mosquito position, if a predecessor is not found in the tree of frogs or it is found but the frog can't eat it, the mosquito 
is inserted in the binary search tree of uneaten mosquitoes. 
Otherwise we compute some update operations:
- the length of the tongue of the frog found is updated with the mosquito value;
- the tree of frogs is updated to keep the segments non-overlapping;
- we check,  among the uneaten mosquitoes, if the successor of the frog that ate last can be eaten, if so we repeat these update operations.

**Time complexity:** &Omicron;(mlogm +(m+n)logn), n frogs, m mosquitoes. Build the tree of frog is   &theta;(nlogn), updates of the trees &Omicron;((n+m)logn), updates fro the tree of mosquitoes &Omicron;(mlogm). \
**Space complexity:** &theta;(n + m).