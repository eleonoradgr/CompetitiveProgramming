//
// Created by eleonora on 07/10/20.
//
#include <iostream>
#include <vector>

int findk(std::vector<int> const &elem) {
    int k = 0;
    for (auto it = elem.rbegin(); it != elem.rend(); ++it) {
        int diff = 0;
        if (it == elem.rend()) {
            diff = *it;
        } else {
            diff = *it - *(it + 1);
        }
        if (diff > k) {
            k = diff;
        } else {
            if (diff == k) {
                k++;
            }
        }
    }
    return k;
}

int main() {
    int n, m = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> m;
        std::vector<int> elem;
        elem.reserve(m);
        for (int j = 0; j < m; ++j) {
            int aus;
            std::cin >> aus;
            elem.push_back(aus);
        }
        int k = findk(elem);
        std::cout << "Case " << i + 1 << ": " << k << std::endl;
        elem.clear();
    }
    return 0;
}
