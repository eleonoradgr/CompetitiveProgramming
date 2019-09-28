#include <iostream>
#include <vector>


std::pair<int, int> towers(std::vector<int> const &v) {
    int maxHeight = 0;
    int nTowers = 0;
    std::vector<int> counter(1000);
    for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); ++iter) {
        if (counter[(*iter)-1] == 0) {
            nTowers++;
        }
        counter[(*iter)-1]++;
        if (counter[(*iter)-1] > maxHeight) {
            maxHeight++;
        }
    }
    std::pair<int, int> result(maxHeight, nTowers);
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        int aus;
        std::cin >> aus;
        v.push_back(aus);
    }
    std::pair<int, int> res(towers(v));
    std::cout << res.first << " " << res.second;
}

