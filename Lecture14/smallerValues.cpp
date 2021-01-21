//
// Created by eleonora on 11/01/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

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


struct query {
    int l;
    int r;
    int val;
    int idx;
    int result;

    query(int left, int right, int v, int i) : l(left), r(right), val(v), idx(i) {
        result = 0;
    }
};

bool myfunction(query const &i, query const &j) {
    return i.val < j.val;
}

bool myfunction2(std::pair<int, int> &i, std::pair<int, int> &j) {
    return i.first < j.first;
}

bool myfunction3(query const &i, query const &j) {
    return i.idx < j.idx;
}

int main(int argc, char **argv) {
    int n;
    int m;
    std::cin >> n;
    std::cin >> m;
    std::vector<std::pair<int, int>> sequence;
    std::vector<query> queries;
    sequence.reserve(n);
    queries.reserve(m);
    std::vector<int> ft(n, 0);
    fenwick_tree<int> ftree(ft);
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        sequence.emplace_back(tmp, i);
    }
    for (int i = 0; i < m; ++i) {
        int tmpl;
        int tmpr;
        int v;
        std::cin >> tmpl >> tmpr >> v;
        queries.emplace_back(tmpl, tmpr, v, i);
    }
    std::sort(queries.begin(), queries.end(), myfunction);
    std::sort(sequence.begin(), sequence.end(), myfunction2);
    int s = 0;
    for (int q = 0; q < m; ++q) {
        while (sequence[s].first <= queries[q].val && s < n) {
            ftree.add(sequence[s].second, 1);
            ++s;
        }
        queries[q].result = (queries[q].l == 0) ? ftree.sum(queries[q].r) : ftree.sum(queries[q].r) -
                                                                            ftree.sum(queries[q].l - 1);
    }
    std::sort(queries.begin(), queries.end(), myfunction3);
    for (int q = 0; q < m; ++q) {
        std::cout << queries[q].result << std::endl;
    }
}