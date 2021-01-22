//
// Created by eleonora on 17/01/21.
//

#include <iostream>
#include <vector>
#include <cmath>

template<typename typeV, typename binaryOp>
struct segment_tree {

    struct type_traits {
        typeV invalid;
        binaryOp funct;
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
            int64_t mid = left + (right - left) / 2;
            int64_t lchild = idx * 2 + 1;
            int64_t rchild = idx * 2 + 2;
            build(leaves, left, mid, lchild);
            build(leaves, mid + 1, right, rchild);
            //classic[idx] = tra.funct(classic[lchild],classic[rchild]);
            classic[idx] = tra.invalid;
        }
    }

    segment_tree(int64_t n, type_traits traits) : in_size(n), tra(traits) {
        int64_t m = pow(2, (int64_t) (ceil(log2(n))));
        classic.resize(2 * m - 1, traits.invalid);
        lazy.resize(2 * m - 1, traits.invalid);
    }

    segment_tree(std::vector<typeV> const &leaves, type_traits traits) : tra(traits), in_size(leaves.size()) {
        int64_t m = pow(2, (int64_t) (ceil(log2(in_size))));
        classic.resize(2 * m - 1, traits.invalid);
        lazy.resize(2 * m - 1, traits.invalid);
        build(leaves, 0, leaves.size() - 1, 0);
    }

    void update_rec(int64_t ustart, int64_t uend, typeV val, int64_t leftlim, int64_t rightlim, int64_t idx) {
        if (leftlim > uend || rightlim < ustart || leftlim > rightlim || idx >= classic.size())
            return;
        int64_t lchild = idx * 2 + 1;
        int64_t rchild = idx * 2 + 2;
        if (leftlim >= ustart && rightlim <= uend) {
            lazy[idx] = tra.funct(lazy[idx], val);
            return;
        }
        int64_t mid = leftlim + (rightlim - leftlim) / 2;
        update_rec(ustart, uend, val, leftlim, mid, lchild);
        update_rec(ustart, uend, val, mid + 1, rightlim, rchild);
        //classic[idx] = tra.funct(classic[idx],val);
    }

    typeV sum_rec(int64_t sstart, int64_t send, int64_t leftlim, int64_t rightlim, int64_t idx) {
        int64_t lchild = idx * 2 + 1;
        int64_t rchild = idx * 2 + 2;
        if (lazy[idx] != tra.invalid) {
            typeV toupdate = lazy[idx];
            classic[idx] = tra.funct(classic[idx], toupdate);
            //propagate change to children
            if (leftlim != rightlim) {
                lazy[lchild] = tra.funct(lazy[lchild], lazy[idx]);
                lazy[rchild] = tra.funct(lazy[rchild], lazy[idx]);
            }
            lazy[idx] = tra.invalid;
        }
        if (leftlim >= sstart && rightlim <= send) {
            return classic[idx];
        }
        if (leftlim > send || rightlim < sstart) {
            return tra.invalid;
        }
        int64_t mid = leftlim + (rightlim - leftlim) / 2;
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

struct segment {
    int val;
    int diff;
    int time;

    segment() {}

    segment(int value, int difference, int timestamp) : val(value), diff(difference), time(timestamp) {}
};

bool operator==(const segment &lhs, const segment &rhs) {
    return lhs.val == rhs.val && lhs.diff == rhs.diff && lhs.time == rhs.time;
}

bool operator!=(const segment &lhs, const segment &rhs) {
    return lhs.val != rhs.val || lhs.diff != rhs.diff || lhs.time != rhs.time;
}


template<typename SegType>
struct comp {
    SegType operator()(SegType x, SegType y) {
        return (x.time >= y.time) ? x : y;
    }
};

struct query {
    int type;
    int x;
    int y;
    int k;

    query(int t, int _x, int _y, int _k) : type(t), x(_x), y(_y), k(_k) {}
};

std::vector<int>
array_copy(segment_tree<segment, comp<segment>> &stree, std::vector<int> &a, std::vector<query> &queries) {
    std::vector<int> result;
    result.reserve(queries.size());
    int j = 1;
    for (int i = 0; i < queries.size(); ++i) {
        if (queries[i].type == 2) {
            auto res = stree.sum(queries[i].x, queries[i].x);
            if (res.time == 0) {
                result.push_back(res.val);
            } else {
                result.push_back(a[queries[i].x + res.diff]);
            }
        } else {
            int start_u = queries[i].y;
            int end_u = queries[i].y + queries[i].k;
            if (queries[i].x + queries[i].k < a.size()) {
                if (end_u >= a.size()) {
                    end_u = a.size() - 1;
                }
            } else {
                end_u -= (queries[i].x + queries[i].k) - a.size();
            }
            stree.update(start_u, end_u, segment(-1, queries[i].x - queries[i].y, j++));
        }
    }
    return result;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a;
    a.reserve(n);
    std::vector<segment> b;
    b.reserve(n);
    std::vector<int> result;
    std::vector<query> queries;
    queries.reserve(m);
    segment_tree<segment, comp<segment>>::type_traits traits{};
    traits.invalid = segment(-1, -1, -1);
    traits.funct = comp<segment>{};
    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        a.emplace_back(v);
    }
    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        b.emplace_back(segment(v, -1, 0));
    }
    segment_tree<segment, comp<segment>> stree(b, traits);
    for (int i = 0; i < m; ++i) {
        int t, x, y, k;
        std::cin >> t;
        if (t == 1) {
            std::cin >> x >> y >> k;
            queries.emplace_back(query(t, x, y, k - 1));
        } else {
            std::cin >> x;
            queries.emplace_back(query(t, x, y, k));
        }
    }
    result = array_copy(stree, a, queries);
    for (auto res : result) {
        std::cout << res << std::endl;
    }
}
