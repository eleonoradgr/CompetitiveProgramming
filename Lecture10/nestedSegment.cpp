//
// Created by eleonora on 15/11/20.
//
//#include "../Lecture09/fenwick.cpp"
#include <iostream>
#include <algorithm>

#include <vector>

template<class T>
struct fenwick_tree {
    std::vector<T> ft;

    fenwick_tree(std::vector<T> v) : ft(v.size() + 1, 0) {
        for (auto i = 0; i < v.size(); ++i)
            ft[i + 1] = v[i];
        for (auto i = 1; (i + (i & -i)) < ft.size(); ++i)
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


struct segment {
    int begin;
    int end;
    int ind;

    segment(int l, int r, int i) : begin(l), end(r), ind(i) {}
};

bool my_function(segment i, segment j) {
    return i.end < j.end;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<segment> segments;
    std::vector<int> remap;
    std::vector<int> result(n, 0);
    segments.reserve(n);
    remap.reserve(n);
    std::vector<int> sa(n * 2, 0);;
    fenwick_tree<int> start_after(sa);
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l;
        std::cin >> r;
        segments.emplace_back(segment(l, r, i));
        remap.emplace_back(l);
        remap.emplace_back(r);
    }
    std::sort(segments.begin(), segments.end(), my_function);
    std::sort(remap.begin(), remap.end());
    for (int i = 0; i < n; ++i) {
        auto li = std::lower_bound(remap.begin(), remap.end(), segments[i].begin);
        int l = (li - remap.begin());
        result[segments[i].ind] = start_after.sum(l);
        start_after.add(0, 1);
        start_after.add(l, -1);
    }
    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << std::endl;
    }
}
