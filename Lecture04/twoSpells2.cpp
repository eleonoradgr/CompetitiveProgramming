//
// Created by eleonora on 22/10/20.
//
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
    /*std::vector<std::pair<int, int>> input;
    input.reserve(n);
    for (int i = 0; i < n; ++i) {
        int tp, d;
        std::cin >> tp >> d;
        input.push_back(std::make_pair(d, tp));
    }*/
    // doubling.size numero di elementi effettivamnte raddoppiati
    int doubled = 0;// numero di elementi che possono essere raddoppiati
    int l_doubled = 0;// numero di elementi lightrning raddoppiati
    long long damage_base = 0;
    long long damage = 0;
    for (int i = 0; i < n; ++i) {
        int tp, d;
        std::cin >> tp >> d;
        std::pair<int,int> elem = std::make_pair(d,tp);
        /*d = input[i].first;
        tp = input[i].second;*/

        if (d > 0) {
            if (tp) {
                doubled++;
                if (doubling.empty() || d < doubling.cbegin()->first) {
                    damage += d;
                    spells.insert(elem);
                    if (l_doubled < doubled - 1) {//posso raddoppiare un lightnening
                        doubling.insert(*spells.rbegin());
                        damage += spells.rbegin()->first;
                        if (spells.rbegin()->second) l_doubled++;
                        spells.erase(spells.rbegin()->first);
                    } else {//posso raddoppiare solo un fire
                        auto it = spells.rbegin();
                        while (it != spells.rend()) {
                            if (it->second == 0) {
                                damage += it->first;
                                doubling.insert(*it);
                                spells.erase(it->first);
                                break;
                            }
                            ++it;
                        }
                    }
                } else {
                    if (l_doubled < doubled - 1) {//posso raddoppiare lo stesso che sto inserendo
                        /*damage += 2 * d;
                        doubling.insert(elem);
                        l_doubled++;*/
                        damage += d;
                        spells.insert(elem);
                        doubling.insert(*spells.rbegin());
                        damage += spells.rbegin()->first;
                        if (spells.rbegin()->second) l_doubled++;
                        spells.erase(spells.rbegin()->first);
                    } else {
                        auto it = spells.rbegin();
                        while (it != spells.rend()) {
                            if (it->second == 0) {
                                damage += it->first;
                                doubling.insert(*it);
                                spells.erase(it->first);
                                break;
                            }
                            ++it;
                        }
                    }
                }
            } else {
                //primo fire in assoluto oppure fire che non devono essere raddoppiati.
                if ((doubling.empty() && doubled == 0) ||
                    (doubling.size() == doubled && d < doubling.cbegin()->first)) {
                    damage += d;
                    spells.insert(elem);
                } else {
                    damage += 2 * d;
                    if (doubling.size() < doubled) { //inserimento fire quando non posso inserire solo lightrninig
                        doubling.insert(elem);
                    } else { // inserimento di fire maggiore dell'ultimo raddoppiato
                        damage -= doubling.cbegin()->first;
                        spells.insert(*doubling.cbegin());
                        if (doubling.cbegin()->second) l_doubled--;
                        doubling.erase(doubling.cbegin()->first);
                        doubling.insert(elem);
                    }
                }
            }
        } else {
            if (tp) {
                doubled--;
                if (spells.find(-d) != spells.end()) {
                    damage -= -d;
                    spells.erase(-d);
                    if(!doubling.empty()){
                        damage -= doubling.begin()->first;
                        spells.insert(*doubling.begin());
                        if (doubling.cbegin()->second) l_doubled--;
                        doubling.erase(doubling.begin()->first);
                    }
                } else {
                    damage -= 2 * -d;
                    doubling.erase(-d);
                    l_doubled--;
                }
            } else {
                if (spells.find(-d) != spells.end()) {
                    damage -= -d;
                    spells.erase(-d);
                } else {
                    damage -= 2 * -d;
                    doubling.erase(-d);
                    if (l_doubled < doubled - 1) {
                        doubling.insert(*spells.rbegin());
                        damage += spells.rbegin()->first;
                        if (spells.rbegin()->second) l_doubled++;
                        spells.erase(spells.rbegin()->first);
                    } else {
                        auto it = spells.rbegin();
                        while (it != spells.rend()) {
                            if (it->second == 0) {
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
        }
        std::cout << damage << std::endl;
    }
    return 0;
}