//
// Created by eleonora on 04/10/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


bool myfunction(std::pair<int, int> i, std::pair<int, int> j){
    return i.first < j.first;
}

int main() {
    //std::ios_base::sync_with_stdio(false);

    int n = 0;
    int m = 0;
    std::cin >> n;
    std::cin >> m;
    // frog data: first.first-> initial position of frog, first.second-> original length of its tongue
    // second the ith frog
    std::vector<std::pair<int, int>> frog_data;
    // mosquitoes eaten by the ith frog, length of the tongue
    std::vector<std::pair<int, int>> eaten;
    frog_data.reserve(n);
    eaten.reserve(n);
    // frogs are seen as non overlapping segments,
    // to keep the value of the frog another map is used
    std::map<int, int> frogs;
    std::map<int, int> key_val;
    // bst to keep track of uneaten mosquitoes
    std::map<int, int> mosquitoes;
    for (int i = 0; i < n; ++i) {
        int start = 0;
        int length = 0;
        std::cin >> start;
        std::cin >> length;
        frog_data.emplace_back(std::make_pair(start, length));
        key_val.insert(std::make_pair(start, i));
        eaten.emplace_back(std::make_pair(0, length));
    }
    std::sort(frog_data.begin(), frog_data.end(), myfunction);
    for (int i = 0; i < n; ++i) {
        if (frogs.empty()) {
            frogs.insert(std::make_pair(frog_data[i].first, frog_data[i].first + frog_data[i].second));
        } else {
            auto pred = (frogs.lower_bound(frog_data[i].first))--;
            if (pred->second < frog_data[i].first) {
                frogs.insert(std::make_pair(frog_data[i].first, frog_data[i].first + frog_data[i].second));
            } else if (pred->second - frog_data[i].first < frog_data[i].second) {
                frogs.insert(std::make_pair(pred->second + 1, frog_data[i].first + frog_data[i].second));
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        int pos = 0;
        int b =0;
        std::cin >> pos;
        std::cin >> b;
        auto eater = frogs.lower_bound(pos);
        int new_m = 1;
        while (new_m == 1) {
            if (frogs.rbegin()->second < pos) {
                mosquitoes.insert(std::make_pair(pos, b));
                new_m = 0;
            } else {
                if (eater == frogs.end() || eater->first > pos) {
                    --eater;
                }
                if(eater->second < pos){
                    mosquitoes.insert(std::make_pair(pos, b));
                    break;
                }
                auto ipos = key_val.find(eater->first)->second;
                eaten[ipos].first += 1;
                eaten[ipos].second += b;
                eater->second += b;
                auto next = frogs.upper_bound(eater->first);
                while (next != frogs.end() && next->first <= eater->second) {
                    if (next->second < eater->second) {
                        frogs.erase(next->first);
                    } else {
                        auto elem = std::make_pair(eater->second + 1, next->second);
                        frogs.erase(next->first);
                        frogs.insert(elem);
                    }
                    next = frogs.upper_bound(eater->first);
                }
                auto new_mos = mosquitoes.upper_bound(eater->first);
                if (new_mos != mosquitoes.cend() && new_mos->first <= eater->second){
                    pos = new_mos->first;
                    b = new_mos->second;
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

