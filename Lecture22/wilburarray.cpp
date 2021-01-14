//
// Created by eleonora on 14/01/21.
//

#include <vector>
#include <iostream>

template <class T>
struct fenwick_tree{
    std::vector<T> ft;

    fenwick_tree(int n):ft(n + 1 ){
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

int main(){
    int n;
    std::cin >> n;
    std::vector<long long int> b;
    b.reserve(n);
    long long res = 0;
    for(int i = 0; i< n; ++i){
        long long tmp;
        std::cin >> tmp;
        b.push_back(tmp);
    }
    fenwick_tree<long long> ftree(n);
    ftree.add(0,b[0]);
    for(int j = 1; j<n; ++j){
        ftree.add(j,b[j]-b[j-1]);
    }
    for(int i = 0; i<n; ++i){
        long long to_add = - ftree.sum(i);
        if(to_add != 0){
            res += std::abs(to_add);
            ftree.add(i,to_add);
        }
    }
    std::cout << res;
}