//
// Created by eleonora on 22/10/20.
//
#include <iostream>
#include <map>
#include <climits>

int main() {

    std::ios_base::sync_with_stdio(false);

    int n;
    std::map<int, int> spells;
    std::cin >> n;
    int doubling = 0;
    int min_doubled = INT_MIN;
    long long damage_base = 0;
    long long damage = damage_base;
    for (int i = 0; i < n; ++i) {
        int tp, d;
        std::cin >> tp >> d;

        if (d > 0) {
            spells.insert(std::make_pair(d, tp));
            if (tp)
                doubling++;
        } else {
            spells.erase(-d);
            if (tp)
                doubling--;
        }
        damage_base += d;

        if(tp == 0 && abs(d) < min_doubled){
            damage += d;
        }else{
            auto l = spells.crbegin();
            int l_used = 0;
            int f_remaining = spells.size() - doubling;
            damage = damage_base;

            for (int j = 0; j < doubling; ++j) {
                if (l->second == 0 || (l->second && l_used < doubling - 1)) {
                    damage += (l->first);
                    min_doubled = l->first;
                } else if (f_remaining > 0) {
                    j--;
                }
                if (l->second) {
                    l_used++;
                } else {
                    f_remaining--;
                }
                l++;
            }
        }

        std::cout << damage << std::endl;
    }
    return 0;
}