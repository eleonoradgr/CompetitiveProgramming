#include <vector>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <algorithm>

template <typename typeV,typename binaryOp >
struct segment_tree {

    struct type_traits {
        typeV invalid;
        binaryOp funct;
    };

    std::vector<typeV> classic;
    std::vector<typeV> lazy;
    int64_t in_size;
    type_traits tra;

    void build(std::vector<typeV> const& leaves,int64_t left, int64_t right, int64_t idx){
        if (left == right){
            classic[idx] = leaves[idx];
        }else{
            int64_t mid = left + (right - left)/2;
            int64_t lchild = idx*2+1;
            int64_t  rchild = idx*2+2;
            build(leaves,left,mid,lchild);
            build(leaves,mid+1,right,rchild);
            classic[idx] = tra.funct(classic[lchild],classic[rchild]);
        }
    }
    segment_tree(int64_t n,type_traits traits):in_size(n),tra(traits){
        int64_t m = pow(2,(int64_t)(ceil(log2(n))));
        classic.resize(2 * m - 1, traits.invalid);
        lazy.resize(2 * m - 1, traits.invalid);
    }
    segment_tree(std::vector<typeV> const& leaves, type_traits traits):tra(traits),in_size(leaves.size()){
        int64_t m = pow(2,(int64_t)(ceil(log2(in_size))));
        classic.resize(2 * m - 1, traits.invalid);
        lazy.resize(2 * m - 1, traits.invalid);
        build(leaves, 0, in_size - 1, 0);
    }

    void update_rec(int64_t ustart, int64_t uend,  typeV val, int64_t leftlim, int64_t rightlim,int64_t idx){
        if(leftlim > uend || rightlim < ustart || leftlim > rightlim || idx>=classic.size())
            return;
        int64_t lchild = idx*2+1;
        int64_t  rchild = idx*2+2;
        if(leftlim >= ustart && rightlim <= uend){
            lazy[idx] = tra.funct(lazy[idx],val);
        }
        int64_t mid = leftlim + (rightlim - leftlim)/2;
        update_rec(ustart, uend, val, leftlim, mid, lchild);
        update_rec(ustart, uend, val, mid+1, rightlim, rchild);
        classic[idx] = tra.funct(classic[idx],val);
    }

    typeV sum_rec(int64_t sstart, int64_t send, int64_t leftlim, int64_t rightlim,int64_t idx){
        int64_t lchild = idx*2+1;
        int64_t  rchild = idx*2+2;
        if(lazy[idx] != tra.invalid){
            typeV toupdate = lazy[idx];
            classic[idx]= tra.funct(classic[idx],toupdate);
            //propagate change to children
            if(leftlim != rightlim){
                lazy[lchild] = tra.funct(lazy[lchild],lazy[idx]);
                lazy[rchild] = tra.funct(lazy[rchild],lazy[idx]);
            }
            lazy[idx] = tra.invalid;
        }
        if (leftlim >= sstart && rightlim <= send){
            return classic[idx];
        }
        if(leftlim > send || rightlim < sstart){
            return tra.invalid;
        }
        int64_t mid = leftlim + (rightlim - leftlim)/2;
        return(tra.funct(sum_rec(sstart, send, leftlim, mid, lchild),sum_rec(sstart, send, mid+1, rightlim, rchild)));
    }

    void update(int64_t start, int64_t end, typeV val){
        update_rec(start,end,val,0,pow(2,(int64_t)(ceil(log2(in_size))))-1,0);
    }

    typeV sum(int64_t start, int64_t end){
        return sum_rec(start,end,0,pow(2,(int64_t)(ceil(log2(in_size))))-1,0);
    }
};

struct segment{
    int begin;
    int end;
    int ind;
    segment(int l, int r,int i) : begin(l), end(r), ind(i){}
};

template<typename IntType>
struct sum {
        IntType operator()(IntType x, IntType y) {
        return x+y;
    }
};

bool my_function(segment i, segment j){
    return i.end < j.end;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<segment> segments;
    std::vector<int> remap;
    std::vector<int> result(n,0);
    segments.reserve(n);
    remap.reserve(n);
    std::vector<int> sa(n * 2, 0);
    segment_tree<int, sum<int>>::type_traits traits{};
    traits.invalid=0;
    traits.funct = sum<int>{};
    segment_tree<int, sum<int>> stree(n * 2,traits);
    for(int i = 0; i < n; ++i){
        int l,r;
        std::cin >> l;
        std::cin >> r;
        segments.emplace_back(segment(l,r,i));
        remap.emplace_back(l);
        remap.emplace_back(r);
    }
    std::sort(segments.begin(), segments.end(), my_function);
    std::sort(remap.begin(),remap.end());
    for(int i = 0; i< n; ++i){
        auto li = std::lower_bound(remap.begin(),remap.end(),segments[i].begin);
        int l = (li-remap.begin());
        auto ri = std::lower_bound(remap.begin(),remap.end(),segments[i].end);
        int r = (ri-remap.begin());
        result.at(segments[i].ind) = stree.sum(l,r);
        stree.update(l,l,1);
    }
    for(int i = 0; i < n; ++i){
        std::cout << result[i] << std::endl;
    }
    return 0;
}