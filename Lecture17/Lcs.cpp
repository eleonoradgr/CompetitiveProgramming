//
// Created by eleonora on 23/11/20.
//

int lcs(int x, int y, string s1, string s2) {
    // your code here
    int a[x + 1][y + 1];
    std::memset(a, 0, sizeof a);
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                a[i][j] = a[i - 1][j - 1] + 1;
            } else {
                a[i][j] = (a[i][j - 1] > a[i - 1][j]) ? a[i][j - 1] : a[i - 1][j];
            }
        }
    }
    return a[x][y];
}

