#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

//
// Created by eleonora on 14/01/21.
//
template< typename  T>
void perform_prefix( std::vector<T> &p ){
    for(auto i = 1 ; i < p.size(); ++i ){
        p[i] = p[i] + p[i-1];
    }
}
template<typename T>
struct query{
    int l;
    int r;
    int idx;
    int k;
    int tot;
    T res;
    query(int left, int right, int index,int key, int total): l(left),r(right),idx(index),k(key), tot(total){
        res =0;
    }
};
template<typename T>
bool sort_fun(query<T> &i, query<T> &j){
    int bi = (int) (i.l / (int)std::sqrt(i.tot));
    int bj = (int) (j.l / (int)std::sqrt(j.tot));
    //part of the same block
    if( bi == bj ){
        return i.r < j.r;
    }else{
        return bi < bj;
    }
}
template<typename T, typename S>
void solve(std::vector<T> & seg,std::vector<query<S>> & q){
    int curri = q[0].l;
    int currj = q[0].l -1;
    std::vector<S> occ(seg.size(),0);
    for ( int i = 0; i<q.size(); ++i){
        while(curri < q[i].l){
            occ[seg[curri]]--;
            curri++;
        }
        while(curri > q[i].l){
            -- curri;
            occ[seg[curri]] ++;
        }
        while(currj < q[i].r){
            ++ currj;
            occ[seg[currj]] ++;
        }
        while(currj > q[i].r ){
            occ[seg[currj]]--;
            -- currj;
        }
        q[i].res = (occ[q[i].k]>0)?1 : 0;
    }
}

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> segments(n+1,0);
    std::vector<query<int>> queries;
    queries.reserve(m);
    for(int i = 0; i<n; ++i){
        int l, r;
        std::cin >> l >> r;
        segments[l]++;
        segments[r+1]--;
    }
    perform_prefix(segments);
    for(int i = 0; i<m; ++i){
        int l, r, k;
        std::cin >> l >> r >> k;
        queries.push_back(query<int>(l,r,i,k,n));
    }
    std::sort(queries.begin(),queries.end(),sort_fun<int>);
    solve(segments, queries);
    std::sort(queries.begin(),queries.end(), [&](query<int> &i,query<int> &j){return i.idx<j.idx;});

    for(int i = 0; i<m; ++i){
        std::cout << queries[i].res;
        if(i<m-1) std::cout << std::endl;
    }
    return 0;
}