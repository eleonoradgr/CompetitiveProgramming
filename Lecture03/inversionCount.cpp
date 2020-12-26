#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <climits>


std::pair<std::vector<uint64_t>, long long>
mergeCount(std::pair<std::vector<uint64_t>, long long> left, std::pair<std::vector<uint64_t>, long long> right) {
    std::pair<std::vector<uint64_t>, long long> result(std::vector<uint64_t>(left.first.size() + right.first.size()),
                                                 left.second + right.second);
    long long i = 0;
    long long j = 0;
    long long aus = 0;
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

std::pair<std::vector<uint64_t>, long long> inversionCount(std::vector<uint64_t> &v, int start, int end) {
    if (start >= end) {
        std::vector<uint64_t> base(1);
        base[0] = v[end];
        return std::pair<std::vector<uint64_t>, long long>(base, 0);
    } else {
        int mid = start + ((end - start) / 2);
        std::pair<std::vector<uint64_t>, long long> resLeft = inversionCount(v, start, mid);
        std::pair<std::vector<uint64_t>, long long> resRight = inversionCount(v, mid + 1, end);
        return mergeCount(resLeft, resRight);
    }

}

int main() {

    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        long long n;
        std::cin >> n;
        std::vector<uint64_t> v;
        v.reserve(n);
        for (long long j = 0; j < n; ++j) {
            uint64_t in;
            std::cin >> in;
            v.push_back(in);
        }

        std::pair<std::vector<uint64_t>, long long> result = inversionCount(v, 0, v.size() - 1);
        std::cout << result.second << std::endl;
        v.clear();
    }
}