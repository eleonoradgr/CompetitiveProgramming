#include <iostream>
#include <map>
#include <climits>
#include <vector>

int main() {

    std::ios_base::sync_with_stdio(false);

    int n;
    std::map<int, int> spells;
    std::map<int, int> doubling;
    std::cin >> n;
    std::vector<std::pair<int, int>> input;
    input.reserve(n);
    for (int i = 0; i < n; ++i) {
        int tp, d;
        std::cin >> tp >> d;
        input.push_back(std::make_pair(d, tp));
    }
    // doubling.size numero di elementi effettivamnte raddoppiati
    int doubled = 0;// numero di elementi che possono essere raddoppiati
    int l_doubled = 0;// numero di elementi lightrning raddoppiati
    long long damage = 0;
    for (int i = 0; i < n; ++i) {
        int d = input[i].first;
        int tp = input[i].second;
        std::pair<int, int> elem = input[i];

        if (d > 0) {
            if (tp) doubled++;
            damage += d;
            //il problema è il caso in cui ho uno spell l quando ho un fire nei doubling e un altro light più grandre negli spells
            // ho aggiunto la condizionr  d > spells.rbegin()->first
            if (!doubling.empty() && d > doubling.begin()->first && (tp == 0 || (l_doubled < doubled - 1 && d > spells.rbegin()->first))) {
                damage += d;
                doubling.insert(elem);
                if (tp) l_doubled++;
                spells.insert(*doubling.begin());
                damage -= doubling.begin()->first;
                if (doubling.begin()->second) l_doubled--;
                doubling.erase(doubling.begin()->first);
            } else {
                spells.insert(elem);
            }
            if (doubled > doubling.size()) {
                auto it = spells.rbegin();
                while (it != spells.rend()) {
                    if (it->second && l_doubled < doubled - 1) {
                        damage += it->first;
                        doubling.insert(*it);
                        spells.erase(it->first);
                        l_doubled++;
                        break;
                    } else if (it->second == 0) {
                        damage += it->first;
                        doubling.insert(*it);
                        spells.erase(it->first);
                        break;
                    }
                    ++it;
                }
            }
        } else {
            if (spells.find(-d) != spells.end()) {
                damage += d;
                spells.erase(-d);
                if (tp) {
                    doubled--;
                    if(!doubling.empty()){
                        if(l_doubled > 0 && l_doubled > doubled-1){
                            auto it = doubling.begin();
                            while (it != doubling.end()) {
                                if(it->second){
                                    spells.insert(*it);
                                    damage -= it->first;
                                    l_doubled--;
                                    doubling.erase(it->first);
                                    break;
                                }
                                ++it;
                            }
                        }else{
                            spells.insert(*doubling.begin());
                            damage -= doubling.begin()->first;
                            if (doubling.begin()->second) l_doubled--;
                            //qui prima spells.begin()->first
                            doubling.erase(doubling.begin()->first);
                        }
                    }
                }
            } else {
                damage += 2 * d;
                doubling.erase(-d);
                if (tp) {
                    doubled--;
                    l_doubled--;
                } else {
                    auto it = spells.rbegin();
                    while (it != spells.rend()) {
                        if (it->second && l_doubled < doubled - 1) {
                            damage += it->first;
                            doubling.insert(*it);
                            spells.erase(it->first);
                            l_doubled++;
                            break;
                        } else if (it->second == 0) {
                            damage += it->first;
                            doubling.insert(*it);
                            spells.erase(it->first);
                            break;
                        }
                        ++it;

                    }
                }
            }
        }
        std::cout << damage << std::endl;
    }

}