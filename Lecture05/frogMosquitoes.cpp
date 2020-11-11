//
// Created by eleonora on 04/10/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct frog{
    int number;
    int pos;
    int length;
};


bool myfunction(frog &i, frog &j){
    return i.pos < j.pos;
}
int find (std::vector<frog> &frogs, int l, int r, int pos){
    while ( l <= r ){
        int p = l + ( l -r )/ 2;
        if ( frogs[p].pos == pos)
            return p;
        if (frogs[p].pos < pos )
            l = p+1;
        else
            r = r-1;
    }
    return -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n = 0;
    int m = 0;
    std::cin >> n;
    std::cin >> m;
    // frog data: frog.number-> i-th frog, frog.pos-> initial position of frog, first.lenght-> original length of its tongue
    std::vector<frog> frog_data;
    // first -> mosquitoes eaten by the ith frog, second -> length of the tongue
    std::vector<std::pair<int, int>> eaten;
    frog_data.reserve(n);
    eaten.reserve(n);
    // frogs are seen as non overlapping segments,
    std::map<int, frog> frogs;
    // bst to keep track of uneaten mosquitoes
    std::map<int, int> mosquitoes;
    for (int i = 0; i < n; ++i) {
        frog f;
        f.number = i;
        f.pos = 0;
        f.length = 0;
        std::cin >> f.pos;
        std::cin >> f.length;
        frog_data.emplace_back(f);
        eaten.emplace_back(std::make_pair(0, f.length));
    }
    std::sort(frog_data.begin(), frog_data.end(), myfunction);
    // creation of bbst where frog
    for (int i = 0; i < n; ++i) {
        if (frogs.empty()) {
            frogs.insert(std::make_pair(frog_data[i].pos, frog_data[i]));
        } else {
            auto pred = std::prev(frogs.lower_bound(frog_data[i].pos));
            if (pred->first + pred->second.length < frog_data[i].pos) {
                frogs.insert(std::make_pair(frog_data[i].pos, frog_data[i]));
            } else if (pred->first + pred->second.length  < frog_data[i].pos + frog_data[i].length) {
                frogs.insert(std::make_pair(pred->first + pred->second.length +1 ,frog_data[i]));
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        int pos = 0;
        int val =0;
        std::cin >> pos;
        std::cin >> val;
        auto eater = frogs.lower_bound(pos);
        int new_m = 1;
        while (new_m == 1) {
            // bigger than last frog tongue or smaller than the first frog
            int start_first = frogs.begin()->first;
            int end_last = frogs.rbegin()->first + frogs.rbegin()->second.length;
            if (end_last < pos || start_first > pos) {
                mosquitoes.insert(std::make_pair(pos, val));
                new_m = 0;
            } else {
                if (eater == frogs.end() || eater->first > pos) {
                    eater = std::prev(eater);
                }
                if(eater->first + eater->second.length < pos){
                    mosquitoes.insert(std::make_pair(pos, val));
                    break;
                }
                eaten[eater->second.number].first += 1;
                eaten[eater->second.number].second += val;
                eater->second.length += val;
                auto next = frogs.upper_bound(eater->first);
                while (next != frogs.end() && next->first <= eater->first + eater->second.length) {
                    if (next->first +next->second.length <= eater->first + eater->second.length) {
                        frogs.erase(next->first);
                    } else {
                        frog newf;
                        newf.pos = eater->first + eater->second.length + 1;
                        newf.length = next->second.length - (eater->first + eater->second.length + 1 - next->first);
                        newf.number = next->second.number;
                        auto elem = std::make_pair(eater->first + eater->second.length + 1, newf);
                        frogs.erase(next->first);
                        frogs.insert(elem);
                    }
                    next = frogs.upper_bound(eater->first);
                }
                auto new_mos = mosquitoes.lower_bound(eater->first);
                if (new_mos != mosquitoes.cend() && new_mos->first <= eater->first + eater->second.length){
                    pos = new_mos->first;
                    val = new_mos->second;
                    mosquitoes.erase(new_mos->first);
                }else{
                    new_m = 0;
                }
            }
        }
    }

    for (auto & elem : eaten) {
        std::cout << elem.first << " " << elem.second << std::endl;
    }
}

