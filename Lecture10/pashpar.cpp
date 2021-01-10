//
// Created by eleonora on 08/01/21.
//
#include <iostream>
#include <vector>
#include <unordered_map>

template <class T>
struct fenwick_tree{
    std::vector<T> ft;

    fenwick_tree(std::vector<T> v): ft(v.size() + 1 , 0){
        for (auto i = 0; i < v.size(); ++i)
            ft[i+1] = v[i];
        for(auto i = 1; (i + (i & -i)) < v.size(); ++i)
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
int main(){
    int n = 0;
    std::cin >> n;
    std::vector<int> sequence;
    /*vector to keep values of f(1,i,a_i)*/
    std::vector<int> f1i(n,0);
    /*vector to keep values of f(j,n,a_j)*/
    std::vector<int> fjn(n,0);
    /* map to build the previous vectors*/
    std::unordered_map<int,int> um;
    sequence.reserve(n);
    //f1i.reserve(n);
    //fjn.reserve(n);
    um.reserve(n);
    std::vector<int> smallerthan(n,0);
    fenwick_tree<int> smallt(smallerthan);
    /*read the sequence from input and create f(1,i,a_i) using hashmap*/
    for (int i = 0; i< n; i++){
        int elem = 0;
        std::cin >> elem;
        sequence.push_back(elem);
        auto exist = um.find(elem);
        if (exist == um.cend()){
            um.insert(std::make_pair(elem,1));
            f1i[i]=1;
        }else{
            exist->second ++;
            f1i[i]=exist->second;
        }
    }
    /*create f(j,n,a_j) using hashmap*/
    um.clear();
    for (int i = n-1; i >= 0; i--){
        int elem = sequence[i];
        auto exist = um.find(elem);
        if (exist == um.cend()){
            um.insert(std::make_pair(elem,1));
            fjn[i] = 1;
        }else{
            exist->second ++;
            fjn[i]=exist->second;
        }
    }
    /*use fenwick tree to keep the numeber of times fjn is smaller than the value i*/
    /*update fenwick tree while decreasing */
    int j = n-1;
    int i = j-1;
    long long res = 0;
    while(i>=0){
        smallt.add(fjn[j]+1,1);
        res += smallt.sum(f1i[i]);
        --i;
        --j;
    }
    std::cout <<res <<std::endl;
}