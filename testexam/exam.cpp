//
// Created by eleonora on 19/01/21.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <climits>
#include <vector>

template<typename typeV, typename binaryOp, typename binaryOp2>
struct segment_tree {

    struct type_traits {
        typeV invalid;
        binaryOp funct;
        typeV invalidup;
        binaryOp2 functup;
    };

    std::vector<typeV> classic;
    std::vector<typeV> lazy;
    int64_t in_size;
    type_traits tra;

    void build(std::vector<typeV> const &leaves, int64_t left, int64_t right, int64_t idx) {
        if (left == right) {
            if (left < in_size)
                classic[idx] = leaves[left];
            else {
                classic[idx] = tra.invalid;
            }
        } else {
            int64_t mid = (right + left) / 2;
            int64_t lchild = idx * 2 + 1;
            int64_t rchild = idx * 2 + 2;
            build(leaves, left, mid, lchild);
            build(leaves, mid + 1, right, rchild);
            classic[idx] = tra.funct(classic[lchild], classic[rchild]);
        }
    }

    segment_tree(int64_t n, type_traits traits) : in_size(n), tra(traits) {
        int64_t m = pow(2, (int64_t) (ceil(log2(n))));
        classic.resize(2 * m - 1, traits.invalid);
        lazy.resize(2 * m - 1, traits.invalidup);
    }

    segment_tree(std::vector<typeV> const &leaves, type_traits traits) : in_size(leaves.size()),  tra(traits) {
        int64_t m = pow(2, (int64_t) (ceil(log2(leaves.size()))));
        classic.resize(2 * m - 1, traits.invalid);
        lazy.resize(2 * m - 1, traits.invalidup);
        build(leaves, 0, leaves.size() - 1, 0);
    }

    typeV update_rec(int64_t ustart, int64_t uend, typeV val, int64_t leftlim, int64_t rightlim, int64_t idx) {
        if (idx >= classic.size()) {
            return tra.invalid;
        }
        /*if(leftlim > uend || rightlim < ustart || leftlim > rightlim )
            return classic[idx];*/
        int64_t lchild = idx * 2 + 1;
        int64_t rchild = idx * 2 + 2;
        if (lazy[idx] != tra.invalid) {
            //classic[idx] += lazy[idx];
            classic[idx] = tra.functup(classic[idx],lazy[idx]);
            //propagate change to children
            if (leftlim != rightlim) {
                lazy[lchild] = (lazy[lchild] == tra.invalidup) ? lazy[idx] : tra.functup(lazy[lchild], lazy[idx]);
                lazy[rchild] = (lazy[rchild] == tra.invalidup) ? lazy[idx] : tra.functup(lazy[rchild], lazy[idx]);
            }
            lazy[idx] = tra.invalidup;
        }
        if (leftlim >= ustart && rightlim <= uend) {
            classic[idx] = tra.functup(classic[idx], val);
            if (leftlim != rightlim) {
                lazy[lchild] = (lazy[lchild] == tra.invalid) ? val :  tra.functup(lazy[lchild], val);
                lazy[rchild] = (lazy[rchild] == tra.invalid) ? val :  tra.functup(lazy[rchild], val);
            }
            return classic[idx];
        }
        if (leftlim > uend || rightlim < ustart || leftlim > rightlim) {
            return classic[idx];
        }
        int64_t mid = (rightlim + leftlim) / 2;
        typeV l = update_rec(ustart, uend, val, leftlim, mid, lchild);
        typeV r = update_rec(ustart, uend, val, mid + 1, rightlim, rchild);
        classic[idx] = tra.funct(l, r);
        return classic[idx];
    }

    typeV sum_rec(int64_t sstart, int64_t send, int64_t leftlim, int64_t rightlim, int64_t idx) {
        int64_t lchild = idx * 2 + 1;
        int64_t rchild = idx * 2 + 2;
        if (lazy[idx] != tra.invalidup) {
            classic[idx] = tra.functup(classic[idx], lazy[idx]);
            //propagate change to children
            if (leftlim != rightlim) {
                lazy[lchild] = (lazy[lchild] == tra.invalidup) ? lazy[idx] : tra.functup(lazy[lchild], lazy[idx]);
                lazy[rchild] = (lazy[rchild] == tra.invalidup) ? lazy[idx] : tra.functup(lazy[rchild], lazy[idx]);
            }
            lazy[idx] = tra.invalidup;
        }
        if (leftlim >= sstart && rightlim <= send) {
            return classic[idx];
        }
        if (leftlim > send || rightlim < sstart) {
            return tra.invalid;
        }
        int64_t mid = (rightlim + leftlim) / 2;
        return (tra.funct(sum_rec(sstart, send, leftlim, mid, lchild),
                          sum_rec(sstart, send, mid + 1, rightlim, rchild)));
    }

    void update(int64_t start, int64_t end, typeV val) {
        update_rec(start, end, val, 0, in_size - 1, 0);
    }

    typeV sum(int64_t start, int64_t end) {
        return sum_rec(start, end, 0, in_size - 1, 0);
    }
};

template<typename IntType>
struct max {
    IntType operator()(IntType x, IntType y) {
        return std::max(x, y);
    }
};

template<typename IntType>
struct min {
    IntType operator()(IntType x, IntType y) {
        return std::min(x, y);
    }
};

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int64_t> leaves(n, 0);
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        std::cin >> tmp;
        leaves[i] = tmp;
    }
    segment_tree<int64_t, max<int64_t>, min<int64_t>>::type_traits traits{};
    traits.invalid = INT_MIN;
    traits.funct = max<int64_t>{};
    traits.invalidup = INT_MAX;
    traits.functup = min<int64_t>{};
    segment_tree<int64_t, max<int64_t>, min<int64_t>> stree(leaves, traits);

    std::vector<int64_t> result;
    result.reserve(m);
    for (int i = 0; i < m; i++) {
        int type, left, right, up;
        std::cin >> type;
        if(type){
            std::cin >> left >> right;
            result.push_back(stree.sum(left-1,right-1));
        }else{
            std::cin >> left >> right >> up;
            stree.update(left-1,right-1, up);
        }
    }
    for (auto res : result){
        std::cout<< res << std::endl;
    }
}