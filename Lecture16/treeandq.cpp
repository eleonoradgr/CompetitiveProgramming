//
// Created by eleonora on 15/01/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

template<typename T>
struct query{
    T left;
    T right;
    T k;
    T tot;
    T idx;
    T res;
    query(T l, T r, T key, T t, T i, T re): left(l), right(r), k(key), tot(t), idx(i), res(re){}
};

template<typename T>
bool sort_fun(query<T> &i, query<T> &j){
    int bi = (int) (i.left / (int)std::sqrt(i.tot));
    int bj = (int) (j.left / (int)std::sqrt(j.tot));
    //part of the same block
    if( bi == bj ){
        return i.right < j.right;
    }else{
        return bi < bj;
    }
}

template<typename T>
void remap(std::vector<T> & v){
    std::vector<T> old(v);
    std::sort(old.begin(),old.end());
    for(size_t i= 0; i<v.size(); ++i){
        auto n = std::lower_bound(old.begin(),old.end(),v[i]);
        int nv = (n-old.begin());
        v[i] = nv;
    }
}

template<typename T>
void build_seq(std::vector<T> & colors, std::vector<T> &colors_ord, std::vector<std::set<T>> &edges,
               std::vector<std::pair<T, T>> &segments, T elem, T & counter) {
    colors_ord[counter] = colors[elem];
    //represent each node as a segment that contains all the elements of the subtree
    segments[elem].first = counter;
    for(auto e : edges[elem]){
        edges[e].erase(std::find(edges[e].begin(),edges[e].end(),elem));
        build_seq(colors,colors_ord,edges,segments,e,++counter);
    }
    segments[elem].second = counter;
}

void treeq_mo(std::vector<int> &colors, std::vector<query<int>> &queries) {
    std::sort(queries.begin(),queries.end(), sort_fun<int>);
    std::vector<long> biggerthan(colors.size()+1,0);
    std::vector<long> occ(colors.size(),0);
    int curri = queries[0].left;
    int currj = queries[0].left-1;
    for( int i = 0; i< queries.size(); ++i){
        if(queries[i].k >= biggerthan.size()){
            queries[i].res = 0;
        }else{
            while(curri < queries[i].left){
                biggerthan[occ[colors[curri]]]--;
                occ[colors[curri]]--;
                curri++;
            }
            while(curri > queries[i].left){
                curri--;
                occ[colors[curri]]++;
                biggerthan[occ[colors[curri]]]++;
            }
            while(currj < queries[i].right){
                currj++;
                occ[colors[currj]]++;
                biggerthan[occ[colors[currj]]]++;
            }
            while(currj > queries[i].right ){
                biggerthan[occ[colors[currj]]]--;
                occ[colors[currj]]--;
                currj--;
            }
            queries[i].res = biggerthan[queries[i].k];
        }
    }
    std::sort(queries.begin(),queries.end(), [&](query<int> &i,query<int> &j){return i.idx<j.idx;});
}

int main(){
    int n,m;
    std::cin >> n >> m;
    std::vector<int> colors;
    colors.reserve(n);
    std::vector<int> colors_ord(n,0);
    std::vector<std::set<int>> edges(n);
    std::vector<std::pair<int,int>> subtree_seg(n,std::make_pair(0,0));
    std::vector<query<int>> queries;
    queries.reserve(m);
    for(int i = 0; i<n; ++i){
        int tmp;
        std::cin >> tmp;
        colors.emplace_back(tmp);
    }
    remap(colors);
    for(int i = 0; i<n-1; ++i){
        int from, to;
        std::cin >> from >> to;
        edges[from-1].insert(to-1);
        edges[to-1].insert(from-1);
    }

    int c2 = 0;
    build_seq(colors, colors_ord, edges, subtree_seg,0,c2);
    for(int i = 0; i<m; ++i){
        int root, kval;
        std::cin >> root >> kval;
        queries.emplace_back(query<int>(subtree_seg[root-1].first,subtree_seg[root-1].second,kval,n,i,0));
    }
    treeq_mo(colors_ord, queries);

    for(auto & q: queries){
        std::cout << q.res << std::endl;
    }

    return 0;
}

