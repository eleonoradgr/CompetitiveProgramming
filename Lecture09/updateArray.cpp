//
// Created by eleonora on 15/11/20.
//
#include <vector>
#include <iostream>

template<class T>
struct fenwick_tree {
    std::vector<T> ft;

    fenwick_tree(std::vector<T> v) : ft(v.size() + 1, 0) {
        for (auto i = 0; i < v.size(); ++i)
            ft[i + 1] = v[i];
        for (auto i = 1; (i + (1 & -i)) < v.size(); ++i)
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
    int test;
    std::cin >> test;
    for (auto i = 0; i < test; ++i) {
        int n = 0;
        int u;
        int q = 0;
        std::cin >> n;
        std::vector<int> a(n, 0);
        fenwick_tree<int> nft = fenwick_tree<int>(a);
        std::cin >> u;
        for (auto j = 0; j < u; ++j) {
            int l, r, v;
            std::cin >> l;
            std::cin >> r;
            std::cin >> v;
            nft.add(l, v);
            nft.add(r + 1, -v);
        }
        std::cin >> q;

        for (auto j = 0; j < q; ++j) {
            int aus;
            std::cin >> aus;
            auto s = nft.sum(aus);
            std::cout << s << std::endl;
        }
    }


}