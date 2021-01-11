#include <vector>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <climits>
#include <sstream>
/*
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
            if(left < in_size)
                classic[idx] = leaves[left];
            else{
                classic[idx] = tra.invalid;
            }
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
        int64_t m = pow(2,(int64_t)(ceil(log2(leaves.size()))));
        classic.resize(2 * m - 1, traits.invalid);
        lazy.resize(2 * m - 1, traits.invalid);
        build(leaves, 0, m-1, 0);
    }

    typeV update_rec(int64_t ustart, int64_t uend,  typeV val, int64_t leftlim, int64_t rightlim,int64_t idx){
        if(idx>=classic.size()){
            return tra.invalid;
        }
        /*if(leftlim > uend || rightlim < ustart || leftlim > rightlim )
            return classic[idx];*//*
        int64_t lchild = idx*2+1;
        int64_t  rchild = idx*2+2;
        if(lazy[idx] != tra.invalid){
            classic[idx] += lazy[idx];
            //propagate change to children
            if(leftlim != rightlim){
                lazy[lchild] = (lazy[lchild]==tra.invalid)? lazy[idx] : lazy[lchild]+lazy[idx];
                lazy[rchild] = (lazy[rchild]==tra.invalid)? lazy[idx] : lazy[rchild]+lazy[idx];
            }
            lazy[idx] = tra.invalid;
        }
        if(leftlim >= ustart && rightlim <= uend){
            classic[idx] += val;
            if(leftlim != rightlim){
                lazy[lchild] = (lazy[lchild]==tra.invalid)?  val : lazy[lchild]+ val;
                lazy[rchild] = (lazy[rchild]==tra.invalid)?  val : lazy[rchild]+ val;
            }
            return classic[idx];
        }
        if(leftlim > uend || rightlim < ustart || leftlim > rightlim ){
            return classic[idx];
        }
        int64_t mid = leftlim + (rightlim - leftlim)/2;
        typeV l = update_rec(ustart, uend, val, leftlim, mid, lchild);
        typeV r = update_rec(ustart, uend, val, mid+1, rightlim, rchild);
        classic[idx] = tra.funct(l,r);
        return classic[idx];
    }

    typeV sum_rec(int64_t sstart, int64_t send, int64_t leftlim, int64_t rightlim,int64_t idx){
        int64_t lchild = idx*2+1;
        int64_t  rchild = idx*2+2;
        if(lazy[idx] != tra.invalid){
            classic[idx] += lazy[idx];
            //propagate change to children
            if(leftlim != rightlim){
                lazy[lchild] = (lazy[lchild]==tra.invalid)? lazy[idx] : lazy[lchild]+lazy[idx];
                lazy[rchild] = (lazy[rchild]==tra.invalid)? lazy[idx] : lazy[rchild]+lazy[idx];
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
}; */


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
            if(left < in_size)
                classic[idx] = leaves[left];
            else{
                classic[idx] = tra.invalid;
            }
        }else{
            int64_t mid = (right + left)/2;
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
        int64_t m = pow(2,(int64_t)(ceil(log2(leaves.size()))));
        classic.resize(2 * m - 1, traits.invalid);
        lazy.resize(2 * m - 1, traits.invalid);
        build(leaves, 0, leaves.size()-1, 0);
    }

    typeV update_rec(int64_t ustart, int64_t uend,  typeV val, int64_t leftlim, int64_t rightlim,int64_t idx){
        if(idx>=classic.size()){
            return tra.invalid;
        }
        /*if(leftlim > uend || rightlim < ustart || leftlim > rightlim )
            return classic[idx];*/
        int64_t lchild = idx*2+1;
        int64_t  rchild = idx*2+2;
        if(lazy[idx] != tra.invalid){
            classic[idx] += lazy[idx];
            //propagate change to children
            if(leftlim != rightlim){
                lazy[lchild] = (lazy[lchild]==tra.invalid)? lazy[idx] : lazy[lchild]+lazy[idx];
                lazy[rchild] = (lazy[rchild]==tra.invalid)? lazy[idx] : lazy[rchild]+lazy[idx];
            }
            lazy[idx] = tra.invalid;
        }
        if(leftlim >= ustart && rightlim <= uend){
            classic[idx] += val;
            if(leftlim != rightlim){
                lazy[lchild] = (lazy[lchild]==tra.invalid)?  val : lazy[lchild]+ val;
                lazy[rchild] = (lazy[rchild]==tra.invalid)?  val : lazy[rchild]+ val;
            }
            return classic[idx];
        }
        if(leftlim > uend || rightlim < ustart || leftlim > rightlim ){
            return classic[idx];
        }
        int64_t mid =(rightlim + leftlim)/2;
        typeV l = update_rec(ustart, uend, val, leftlim, mid, lchild);
        typeV r = update_rec(ustart, uend, val, mid+1, rightlim, rchild);
        classic[idx] = tra.funct(l,r);
        return classic[idx];
    }

    typeV sum_rec(int64_t sstart, int64_t send, int64_t leftlim, int64_t rightlim,int64_t idx){
        int64_t lchild = idx*2+1;
        int64_t  rchild = idx*2+2;
        if(lazy[idx] != tra.invalid){
            classic[idx] += lazy[idx];
            //propagate change to children
            if(leftlim != rightlim){
                lazy[lchild] = (lazy[lchild]==tra.invalid)? lazy[idx] : lazy[lchild]+lazy[idx];
                lazy[rchild] = (lazy[rchild]==tra.invalid)? lazy[idx] : lazy[rchild]+lazy[idx];
            }
            lazy[idx] = tra.invalid;
        }
        if (leftlim >= sstart && rightlim <= send){
            return classic[idx];
        }
        if(leftlim > send || rightlim < sstart){
            return tra.invalid;
        }
        int64_t mid = (rightlim + leftlim)/2;
        return(tra.funct(sum_rec(sstart, send, leftlim, mid, lchild),sum_rec(sstart, send, mid+1, rightlim, rchild)));
    }

    void update(int64_t start, int64_t end, typeV val){
        update_rec(start,end,val,0,in_size-1,0);
    }

    typeV sum(int64_t start, int64_t end){
        return sum_rec(start,end,0,in_size-1,0);
    }
};







template<typename IntType>
struct min {
    IntType operator()(IntType x, IntType y) {
        return std::min(x,y);
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >>n;
    std::vector<int64_t> leaves(n,0);
    for(int i = 0; i <n; ++i){
        int tmp = 0;
        std::cin >> tmp;
        leaves[i] =tmp;
    }
    segment_tree<int64_t, min<int64_t>>::type_traits traits{};
    traits.invalid= INT_MAX;
    traits.funct = min<int64_t>{};
    segment_tree<int64_t, min<int64_t>> stree(leaves,traits);
    int q;
    std::cin>> q;
    std::vector<int64_t> result;
    result.reserve(q);
    for(int i =0; i<q; i++){
        std::string S, T;
        std::getline(std::cin >> std::ws, S);
        std::stringstream X(S);
        std::vector<int> array;
        array.reserve(6);
        while (getline(X, T, ' ')) {
           array.push_back(std::stoi(T));
        }
        if(array.size() == 2){
            if(array[0] <= array[1]){
                result.push_back(stree.sum(array[0],array[1]));
            }else{
                int begin = stree.sum(array[0],n-1);
                int end = stree.sum(0, array[1]);
                result.push_back(traits.funct(begin,end));
            }
        }else{
            if(array[2] != 0){
                if(array[0] <= array[1]){
                    stree.update(array[0],array[1],array[2]);
                }else{
                    stree.update(array[0],n-1,array[2]);
                    stree.update(0,array[1],array[2]);
                }
            }
        }
    }
    for(auto elem : result){
        std::cout << elem <<std::endl;
    }
    return 0;
}
