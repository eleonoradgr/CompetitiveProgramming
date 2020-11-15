//
// Created by eleonora on 15/11/20.
//
#include <vector>
#include <iostream>
#include "fenwick.cpp"

int main(){
    int test;
    std::cin >> test;
    for(auto i = 0; i< test; ++i){
        int n = 0;
        int u;
        int q = 0;
        std::cin >> n;
        std::vector<int> a(n,0);
        fenwick_tree nft = fenwick_tree(a);
        std::cin >> u;
        for(auto j = 0; j < u; ++j){
            int l,r,v;
            std::cin >> l;
            std::cin >> r;
            std::cin >> v;
            nft.add(l, v);
            nft.add(r+1,-v);
        }
        std::cin >> q;

        for ( auto j = 0; j < q; ++j){
            int aus;
            std::cin >> aus;
            auto s = nft.sum(aus);
            std::cout << s << std::endl;
        }
    }


}