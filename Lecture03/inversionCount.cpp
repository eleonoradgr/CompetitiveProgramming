#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <climits>


std::pair<std::vector<uint64_t>, uint64_t>
mergeCount(std::pair<std::vector<uint64_t>, uint64_t> left, std::pair<std::vector<uint64_t>, uint64_t> right) {
    std::pair<std::vector<uint64_t>, uint64_t> result(std::vector<uint64_t>(left.first.size() + right.first.size()),
                                                      left.second + right.second);
    uint64_t i = 0;
    uint64_t j = 0;
    uint64_t aus = 0;
    left.first.push_back(INT_MAX);
    right.first.push_back(INT_MAX);
    while (i < left.first.size() - 1 || j < right.first.size() - 1) {
        if (left.first[i] <= right.first[j]) {
            result.first[aus] = left.first[i];
            ++i;
        } else {
            result.first[aus] = right.first[j];
            ++j;
            result.second += (left.first.size() - 1) - i;
        }
        ++aus;
    }
    return result;
}

std::pair<std::vector<uint64_t>, uint64_t> inversionCount(std::vector<uint64_t> &v, int start, int end) {
    if (start >= end) {
        std::vector<uint64_t> base(1);
        base[0] = v[end];
        return std::pair<std::vector<uint64_t>, uint64_t>(base, 0);
    } else {
        int mid = start + ((end - start) / 2);
        std::pair<std::vector<uint64_t>, uint64_t> resLeft = inversionCount(v, start, mid);
        std::pair<std::vector<uint64_t>, uint64_t> resRight = inversionCount(v, mid + 1, end);
        return mergeCount(resLeft, resRight);
    }

}

int main() {

    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        uint64_t n;
        std::cin >> n;
        std::vector<uint64_t> v;
        v.reserve(n);
        for (uint64_t j = 0; j < n; ++j) {
            uint64_t in;
            std::cin >> in;
            v.push_back(in);
        }

        std::pair<std::vector<uint64_t>, uint64_t> result = inversionCount(v, 0, v.size() - 1);
        std::cout << result.second << std::endl;
        v.clear();
    }
}