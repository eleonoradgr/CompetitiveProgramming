//
// Created by eleonora on 24/11/20.
//


#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends


class Solution {
public:
    int editDistance(string s, string t) {
        // Code here
        int edit[s.length() + 1][t.length() + 1];
        for (int i = 0; i <= s.length(); ++i) {
            edit[i][0] = i;
        }
        for (int i = 0; i <= t.length(); ++i) {
            edit[0][i] = i;
        }
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 1; j <= t.length(); ++j) {
                if (s[i - 1] == t[j - 1]) {
                    edit[i][j] = std::min(std::min(edit[i - 1][j] + 1, edit[i][j - 1] + 1), edit[i - 1][j - 1]);
                } else {
                    edit[i][j] = std::min(std::min(edit[i - 1][j] + 1, edit[i][j - 1] + 1), edit[i - 1][j - 1] + 1);
                }
            }
        }
        return edit[s.length()][t.length()];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}