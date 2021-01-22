//
// Created by eleonora on 07/12/20.
//
// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends



class Solution {
public:
    int LongestBitonicSequence(vector<int> nums) {
        // code here
        std::vector<int> numsrev;
        numsrev.reserve(nums.size());
        std::reverse_copy(nums.begin(), nums.end(), numsrev.begin());
        int lis[nums.size()] = {0};
        int lds[nums.size()] = {0};

        lis[0] = 1;
        lds[nums.size() - 1] = 1;
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            int max_inc = 0;
            int max_dec = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    max_inc = (max_inc > lis[j]) ? max_inc : lis[j];
                }
                if (numsrev[i] > numsrev[j]) {
                    max_dec = (max_dec > lds[nums.size() - j - 1]) ? max_dec : lds[nums.size() - j - 1];
                }
            }
            lis[i] = 1 + max_inc;
            lds[nums.size() - i - 1] = 1 + max_dec;
        }
        for (int i = 0; i < nums.size(); i++) {
            result = (result > (lis[i] + lds[i])) ? result : (lis[i] + lds[i]);
        }
        return result - 1;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.LongestBitonicSequence(nums);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
