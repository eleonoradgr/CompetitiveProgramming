#include <iostream>
#include <vector>

std::vector<std::vector<int>> dpvector(std::vector<std::vector<int>> &v, int h, int w) {
    std::vector<std::vector<int>> dp(h + 1, std::vector<int>(w + 1, 0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            int newpos = (v[i][j] && v[i][j - 1]) + (v[i][j] && v[i - 1][j]);
            dp[i][j] = dp[i - 1][j] + (dp[i][j - 1] - dp[i - 1][j - 1]) + newpos;
        }
    }
    return dp;
}

std::vector<std::vector<int>> dpvector3(std::vector<std::vector<int>> &v, int h, int w) {
    std::vector<std::vector<int>> dp(h + 1, std::vector<int>(w + 1, 0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            int newpos = (v[i][j] && v[i - 1][j]);
            dp[i][j] = dp[i][j - 1] + newpos;
        }
    }
    return dp;
}

std::vector<std::vector<int>> dpvector4(std::vector<std::vector<int>> &v, int h, int w) {
    std::vector<std::vector<int>> dp(h + 1, std::vector<int>(w + 1, 0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            int newpos = (v[i][j] && v[i][j - 1]);
            dp[i][j] = dp[i - 1][j] + newpos;
        }
    }
    return dp;
}

int main() {
    int h, w, q;
    std::cin >> h >> w;
    std::vector<std::vector<int>> v(h + 1, std::vector<int>(w + 1, 0));
    for (int i = 1; i <= h; ++i) {
        std::string s;
        std::getline(std::cin >> std::ws, s);
        for (int j = 0; j < w; ++j) {
            if (s[j] == '.') {
                v[i][j + 1] = 1;
            }
        }
    }
    std::vector<std::vector<int>> v2 = dpvector(v, h, w);
    std::vector<std::vector<int>> v3 = dpvector3(v, h, w);
    std::vector<std::vector<int>> v4 = dpvector4(v, h, w);
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;
        int res = v2[r2][c2] + v2[r1 - 1][c1 - 1] - v2[r1 - 1][c2] - v2[r2][c1 - 1] - (v3[r1][c2] - v3[r1][c1 - 1]) -
                  (v4[r2][c1] - v4[r1 - 1][c1]);
        std::cout << res << std::endl;
    }
    return 0;
}
