//
// Created by eleonora on 07/12/20.
//
// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int longestSubsequence(int, int[]);

int main() {
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--) {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence
int longestSubsequence(int n, int a[]) {
    // your code here
    std::map<int, int> bst;
    for (int i = 0; i < n; ++i) {
        if (bst.empty()) {
            bst.insert(std::make_pair(a[i], 1));
        } else {
            auto pred = bst.lower_bound(a[i]);
            int len = 0;
            int to_insert = 0;
            if (pred != bst.begin()) {
                pred--;
                len = 1 + pred->second;
                pred++;
            } else {
                len = 1;
            }
            if (pred == bst.end()) {
                to_insert = 1;
            }
            while (pred != bst.end()) {
                if (pred->second <= len) {
                    auto aus = pred;
                    pred++;
                    bst.erase(aus);
                    to_insert = 1;
                } else {
                    break;
                }
            }
            if (to_insert) bst.emplace(a[i], len);
        }

    }
    return bst.size();
}