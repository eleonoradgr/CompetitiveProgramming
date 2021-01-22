#include <vector>
#include <cstdint>
#include <cmath>
#include <unordered_set>
#include <iostream>
#include <numeric>

template <typename typeV,typename binaryOp >
struct segment_tree {

    struct type_traits {
        std::unordered_set<typeV> invalid;
        binaryOp funct;
    };

    std::vector<std::unordered_set<typeV>> classic;
    int64_t in_size;
    type_traits tra;

    void build(std::vector<std::unordered_set<typeV>> const& leaves,int64_t left, int64_t right, int64_t idx){
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
    }
    segment_tree(std::vector<std::unordered_set<typeV>> const& leaves, type_traits traits):tra(traits),in_size(leaves.size()){
        int64_t m = pow(2,(int64_t)(ceil(log2(in_size))));
        classic.resize(2 * m - 1, traits.invalid);
        build(leaves, 0, leaves.size()-1, 0);
    }

    void update_rec(int64_t ustart, int64_t uend,  typeV val, int64_t leftlim, int64_t rightlim,int64_t idx){
        if(leftlim > uend || rightlim < ustart || leftlim > rightlim || idx>=classic.size())
            return;
        int64_t lchild = idx*2+1;
        int64_t  rchild = idx*2+2;
        int64_t mid = leftlim + (rightlim - leftlim)/2;
        update_rec(ustart, uend, val, leftlim, mid, lchild);
        update_rec(ustart, uend, val, mid+1, rightlim, rchild);
        //classic[idx] = tra.funct(classic[idx],val);
        classic[idx].insert(val);
    }

    typeV sum_rec(int64_t sstart, int64_t send, int64_t leftlim, int64_t rightlim,int64_t idx){
        int64_t lchild = idx*2+1;
        int64_t  rchild = idx*2+2;
        if (leftlim >= sstart && rightlim <= send){
            return classic[idx];
        }
        if(leftlim > send || rightlim < sstart){
            return tra.invalid;
        }
        int64_t mid = leftlim + (rightlim - leftlim)/2;
        return(tra.funct(sum_rec(sstart, send, leftlim, mid, lchild),sum_rec(sstart, send, mid+1, rightlim, rchild)));
    }

    bool find_rec(int64_t sstart, int64_t send, typeV k, int64_t leftlim, int64_t rightlim,int64_t idx){
        int64_t lchild = idx*2+1;
        int64_t  rchild = idx*2+2;
        if (leftlim >= sstart && rightlim <= send){
            auto f = classic[idx].find(k);
            return (f != classic[idx].end());
        }
        if(leftlim > send || rightlim < sstart){
            return false;
        }
        int64_t mid = leftlim + (rightlim - leftlim)/2;
        return(find_rec(sstart, send, k, leftlim, mid, lchild) || find_rec(sstart, send, k,mid+1, rightlim, rchild));
    }

    void update(int64_t start, int64_t end, typeV val){
        update_rec(start,end,val,0,in_size-1,0);
    }

    typeV sum(int64_t start, int64_t end){
        return sum_rec(start,end,0,in_size-1,0);
    }

    bool find(int64_t start, int64_t end, typeV k){
        return find_rec(start,end,k,0,in_size-1,0);
    }
};

struct query{
    int l;
    int r;
    int k;
    query(int left, int right,int key): l(left),r(right),k(key){}
};

template<typename IntType>
struct mergeset {
    std::unordered_set<IntType> operator()(std::unordered_set<IntType> x, std::unordered_set<IntType> y) {
        x.insert(y.begin(),y.end());
        return x;
    }
};

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> segments(n+1,0);
    std::vector<query> queries;
    queries.reserve(m);
    for(int i = 0; i<n; ++i){
        int l, r;
        std::cin >> l >> r;
        segments[l]++;
        segments[r+1]--;
    }
    std::partial_sum(segments.begin(), segments.end(), segments.begin());
    segment_tree<int64_t, mergeset<int64_t>>::type_traits traits{};
    traits.invalid= std::unordered_set<int64_t>();
    traits.funct = mergeset<int64_t>{};
    //segment_tree<int64_t, mergeset<int64_t>> stree(n,traits);
    //for(int i = 0; i<n; ++i){
    //   stree.update(i,i,segments[i]);
    //}
    std::vector<std::unordered_set<int64_t>> leaves(n,std::unordered_set<int64_t>());
    for(int i = 0; i<n; ++i){
           leaves[i].insert(segments[i]);
    }
    segment_tree<int64_t, mergeset<int64_t>> stree(leaves,traits);
    for(int i = 0; i<m; ++i){
        int l, r, k;
        std::cin >> l >> r >> k;
        queries.push_back(query(l,r,k));
        std::cout<< stree.find(l,r,k) <<std::endl;
    }

    return 0;
}




