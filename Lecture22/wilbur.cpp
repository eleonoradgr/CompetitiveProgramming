//
// Created by eleonora on 14/01/21.
//

#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long int> b;
    b.reserve(n);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        long long tmp;
        std::cin >> tmp;
        b.push_back(tmp);
    }
    res = std::abs(b[0]);
    for (int i = 1; i < n; ++i) {
        res += std::abs(b[i] - b[i - 1]);
    }
    std::cout << res;
}