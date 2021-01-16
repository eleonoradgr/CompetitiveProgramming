#include <cstdint>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct frog {
    int64_t start;
    int64_t end;
    int64_t idx;
    int64_t eaten;

    frog(int64_t s, int64_t e, int64_t i, int64_t v) : start(s), end(e), idx(i), eaten(v) {}
};

struct mosquito {
    int64_t pos;
    int64_t val;

    mosquito(int64_t p, int64_t v) : pos(p), val(v) {}
};

void
check_new_to_eat(std::map<int64_t, frog>::iterator p, std::vector<frog> &frogs, std::map<int64_t, frog> &frog_tree,
                 std::multimap<int64_t, int64_t> &mos_tree) {
    auto mos = mos_tree.lower_bound(p->first);
    if (mos != mos_tree.end() && p->second.end >= mos->first) {
        p->second.end += mos->second;
        frogs[p->second.idx].end += mos->second;
        frogs[p->second.idx].eaten++;
        mos_tree.erase(mos);
        auto n = std::next(p);
        auto delete_next = 1;
        while (delete_next) {
            delete_next = 0;
            if (n != frog_tree.end()) {
                if (n->first <= p->second.end) {
                    if (n->second.end <= p->second.end) {
                        frog_tree.erase(n);
                        n = std::next(p);
                        delete_next = 1;
                    } else {
                        frog newf = frog(p->second.end + 1, n->second.end, n->second.idx, n->second.eaten);
                        frog_tree.erase(n);
                        frog_tree.insert(std::make_pair(newf.start, newf));
                    }
                }
            }
        }

        return check_new_to_eat(p, frogs, frog_tree, mos_tree);
    }
}

void frogandmos(std::vector<frog> &frogs, std::vector<mosquito> &mos) {
    std::map<int64_t, frog> frog_tree; //bst for frogs
    std::multimap<int64_t, int64_t> mos_tree; //bst for uneaten mosquitoes
    std::sort(frogs.begin(), frogs.end(), [&](frog &i, frog &j) { return i.start < j.start; });
    frog_tree.insert(std::make_pair(frogs[0].start, frogs[0]));
    //build the tree that contains frogs as not overlapping segment
    auto prec = frogs[0].end;
    for (int i = 1; i < frogs.size(); ++i) {
        if (frogs[i].start > prec) {
            frog_tree.insert(std::make_pair(frogs[i].start, frogs[i]));
            prec = frogs[i].end;
        } else {
            if (frogs[i].end > prec) {
                frog newf(prec + 1, frogs[i].end, frogs[i].idx, frogs[i].eaten);
                frog_tree.insert(std::make_pair(newf.start, newf));
                prec = frogs[i].end;
            }
        }
    }
    std::sort(frogs.begin(), frogs.end(), [&](frog &i, frog &j) { return i.idx < j.idx; });
    for (int i = 0; i < mos.size(); ++i) {
        auto f = frog_tree.upper_bound(mos[i].pos);
        auto p = std::prev(f);
        if (p == frog_tree.end()) {
            mos_tree.insert(std::make_pair(mos[i].pos, mos[i].val));
        } else {
            mos_tree.insert(std::make_pair(mos[i].pos, mos[i].val));
            check_new_to_eat(p, frogs, frog_tree, mos_tree);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<frog> frogs;
    frogs.reserve(n);
    std::vector<mosquito> mos;
    mos.reserve(m);
    for (int i = 0; i < n; ++i) {
        int64_t start, len;
        std::cin >> start >> len;
        frogs.push_back(frog(start, start + len, i, 0));
    }
    for (int i = 0; i < m; ++i) {
        int64_t pos, value;
        std::cin >> pos >> value;
        mos.push_back(mosquito(pos, value));
    }
    frogandmos(frogs, mos);
    for (auto &f : frogs) {
        std::cout << f.eaten << " " << f.end - f.start << std::endl;
    }
}