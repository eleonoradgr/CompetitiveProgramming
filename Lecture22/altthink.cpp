//
// Created by eleonora on 14/01/21.
//

#include <string>
#include <iostream>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int len = 1;
    for (int i = 1; i < n; ++i) {
        len += (s[i] != s[i - 1]);
    }
    if (len <= n - 2) len += 2;
    else {
        if (len == n - 1) len += 1;
    }

    std::cout << len;
}