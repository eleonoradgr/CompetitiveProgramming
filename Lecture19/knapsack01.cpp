//
// Created by eleonora on 23/11/20.
//
#include <iostream>
#include <vector>
#include <cstring>

struct elem{
    int size;
    int val;
    elem(int w, int v): size(w),val(v){};
};


int kanpsack(std::vector<elem> const &vector, int s, int n);

int main(){
    int s,n;
    std::cin >> s;
    std::cin >> n;
    std::vector<elem> v;
    v.reserve(n);
    for (int i = 0; i< n; i++){
        int aus1,aus2;
        std::cin>> aus1;
        std::cin >> aus2;
        v.emplace_back(elem(aus1,aus2));
    }
    int res = kanpsack(v,s,n);
    std::cout << res << std::endl;
}

int kanpsack(std::vector<elem> const &v, int s, int n) {
    int a[n + 1][s + 1];
    std::memset(a, 0, sizeof a);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= s; ++j){
            if(v[i-1].size <= j){
                a[i][j] = std::max(a[i-1][j-v[i-1].size] + v[i-1].val, a[i-1][j]);
            }else{
                a[i][j] = a[i-1][j];
            }
        }
    }
    return a[n][s];
}
