#include <iostream>
#include <vector>

int incrsubarray(std::vector<int> &v) {
    std::vector<std::pair<int, int>> p;
    p.reserve(v.size());
    int max = 0;
    int left = 0;
    int right = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] < v[i]) {
            right++;
        } else {
            p.emplace_back(std::make_pair(left, right));
            left = ++right;
        }
    }
    p.emplace_back(std::make_pair(left, right));
    for (int i = 0; i < p.size() - 1; ++i) {
        int len = p[i].second - p[i].first + 1;
        int nextlen = p[i + 1].second - p[i + 1].first + 1;
        if (nextlen == 1) {// the next interval has lenght 1
            if (i + 1 == p.size() - 1) {//next element is the last one
                len++;
            } else {// if we change it we possibly create a sequence with the next one
                if (v[p[i + 2].first] - 1 > v[p[i].second]) {
                    len += p[i + 1].second - p[i + 1].first + 2;
                } else {
                    len++;
                }
            }
        } else {
            if (v[p[i + 1].first + 1] - 1 > v[p[i].second]) {
                len += nextlen;
            } else {
                len++;
            }
        }

        max = (len > max) ? len : max;
    }
    return max;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input;
    input.reserve(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        input.emplace_back(tmp);
    }
    int result = incrsubarray(input);
    std::cout << result;
}
