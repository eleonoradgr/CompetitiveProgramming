#include <iostream>
#include <algorithm>

#include <vector>

template<class T>
struct fenwick_tree {
    std::vector<T> ft;

    fenwick_tree(std::vector<T> &v) : ft(v.size() + 1, 0) {
        for (auto i = 0; i < v.size(); ++i)
            ft[i + 1] = v[i];
        for (auto i = 1; (i + (i & -i)) < v.size(); ++i)
            ft[i + (i & -i)] += ft[i];
    }

    T sum(int k) {
        T s = 0;
        for (++k; k > 0; k &= k - 1)
            s += ft[k];
        return s;
    }

    void add(int k, T v) {
        for (++k; k < ft.size(); k += k & -k)
            ft[k] += v;
    }

};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> sequence;
    sequence.reserve(n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        sequence.push_back(tmp);
    }
    std::vector<int> l(n, 0);
    std::vector<int> r(n, 0);
    std::vector<int> res1(n, 0);
    std::vector<int> res2(n, 0);
    fenwick_tree<int> lessthan(l);
    fenwick_tree<int> greaterthan(r);
    lessthan.add(sequence[0] + 1, 1);
    for (int j = 1; j < n - 1; ++j) {
        res1[j] = lessthan.sum(sequence[j]);
        lessthan.add(sequence[j] + 1, 1);
    }
    greaterthan.add(0, 1);
    greaterthan.add(sequence[n - 1], -1);
    for (int j = n - 2; j > 0; --j) {
        res2[j] = greaterthan.sum(sequence[j]);
        greaterthan.add(0, 1);
        greaterthan.add(sequence[j], -1);
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += (res1[i] * res2[i]);
    }
    std::cout << result << std::endl;
}