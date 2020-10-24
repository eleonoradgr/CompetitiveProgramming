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
    long long damage_base = 0;
    long long damage = 0;
    for (int i = 0; i < n; ++i) {
        int tp = input[i].second;
        int d = input[i].first;
        std::pair<int, int> elem = input[i];

        if (d > 0) {
            if (tp) doubled++;
            damage += d;
            if (!doubling.empty() && d > doubling.begin()->first && (tp == 0 || l_doubled < doubled - 1)) {
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
                    spells.insert(*doubling.begin());
                    damage -= doubling.begin()->first;
                    if (doubling.begin()->second) l_doubled--;
                    doubling.erase(spells.begin()->first);
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