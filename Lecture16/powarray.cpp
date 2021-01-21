#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

template<typename T>
struct query{
    int l;
    int r;
    int idx;
    int tot;
    T res;
    query(int left, int right, int index, int total): l(left),r(right),idx(index), tot(total){
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
template< typename T>
bool sort_fun1(query<T> &i, query<T> &j){
    return i.idx < j.idx;
}
template<typename T, typename S>
void solve( std::vector<T> const& a, std::vector<query<S>> & q,std::vector<S> const& values, int s, int e ){
    int curri = q[s].l;
    int currj = q[s].l -1;
    std::vector<S> occ(a.size(),0);
    int64_t answer = 0;
    for ( int i = s; i<e; ++i){
        while(curri < q[i].l){
                answer -= occ[a[curri]]*occ[a[curri]]*values[a[curri]];
                occ[a[curri]]--;
                answer += occ[a[curri]]*occ[a[curri]]*values[a[curri]];
                curri++;
        }
        while(curri > q[i].l){
            -- curri;
            answer -= occ[a[curri]]*occ[a[curri]]*values[a[curri]];
            occ[a[curri]] ++;
            answer += occ[a[curri]]*occ[a[curri]]*values[a[curri]];

        }
        while(currj < q[i].r){
            ++ currj;
            answer -= occ[a[currj]]*occ[a[currj]]*values[a[currj]];
            occ[a[currj]] ++;
            answer += occ[a[currj]]*occ[a[currj]]*values[a[currj]];

        }
        while(currj > q[i].r ){
            answer -= occ[a[currj]]*occ[a[currj]]*values[a[currj]];
            occ[a[currj]]--;
            answer += occ[a[currj]]*occ[a[currj]]*values[a[currj]];
            -- currj;
        }
        q[i].res = answer;
    }
}
template<typename T, typename S>
void powarray_moalgo(std::vector<T> const& a, std::vector<query<S>> & q, std::vector<S> const& values){
    std::sort(q.begin(),q.end(), sort_fun<S>);
    int start = 0;
    solve(a,q,values, start,q.size());
    /* Same complexity if we solve all the queries togheter or in different calls of solve function
     * int end = 0;
       int idx = 0;
     * while(end < q.size()){
        idx += (int)sqrt(a.size());
        while(q[end].l < idx && end < q.size()){
            end++;
        }
        solve(a,q,values, start,end);
        start = end;
    }*/
    std::sort(q.begin(),q.end(), sort_fun1<S>);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int64_t> array;
    std::vector<int64_t> remap;
    std::vector<int> pos;
    std::vector<query<int64_t>> queries;
    array.reserve(n);
    remap.reserve(n);
    pos.reserve(n);
    for(int i =0; i<n; ++i){
        int64_t tmp;
        std::cin >> tmp;
        array.push_back(tmp);
        remap.push_back(tmp);
    }
    std::sort(remap.begin(), remap.end());
    for( int i = 0; i<n; ++i){
        auto pp = std::lower_bound(remap.begin(),remap.end(),array[i]);
        int p = (pp-remap.begin());
        pos.push_back(p);
    }
    for(int i =0; i<q; ++i){
        int tmpl, tmpr;
        std::cin >> tmpl >> tmpr;
        queries.push_back(query<int64_t>(tmpl-1,tmpr-1,i,n));
    }
    powarray_moalgo(pos,queries ,remap);
    for(auto &q : queries){
        std::cout << q.res << std::endl;
    }
}