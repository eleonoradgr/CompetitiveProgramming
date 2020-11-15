//
// Created by eleonora on 15/11/20.
//
#include <vector>

template <class T>
struct fenwick_tree{
    std::vector<T> ft;

    fenwick_tree(std::vector<T> v): ft(v.size() + 1 , 0){
        for (auto i = 0; i < v.size(); ++i)
            ft[i+1] = v[i];
        for(auto i = 1; (i + (1 & -i)) < v.size(); ++i)
            ft[i + (i & -i)] += ft[i];
    }

    T sum(int k) {
        T s = 0;
        for (++k; k > 0; k &= k-1)
            s += ft[k];
        return s;
    }

    void add(int k, T v) {
        for (++k; k < ft.size(); k += k&-k)
            ft[k] += v;
    }

};

