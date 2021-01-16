#include <iostream>
#include <map>
#include <vector>

std::vector<long long> twoTypesSpell(std::vector<std::pair<int, int>> &input) {
    //BBST to keep the spells whose damage is not doubled
    std::map<int, int> spells;
    //BBST to keep the spells whose damage is doubled
    std::map<int, int> doubling;
    // number of elements that can be doubled
    int doubled = 0;
    // number of elements lightning doubled
    int l_doubled = 0;
    long long damage = 0;
    std::vector<long long> result;
    result.reserve(input.size());
    for (int i = 0; i < input.size(); ++i) {
        // >0 insertion <0 deletion
        int d = input[i].first;
        // 1 if ligthning 0 if fire spell
        int tp = input[i].second;
        std::pair<int, int> elem = input[i];

        if (d > 0) {
            if (tp) doubled++;
            damage += d;
            // add the element to the doubling tree if it is bigger than the smallest element and remove it
            // special case to check with cond (d > spells.rbegin()->first) if the new spells is a lightning and there is another lightning bigger
            // than d in the spells tree that must be doubled before it.
            if (!doubling.empty() && d > doubling.begin()->first &&
                (tp == 0 || (l_doubled < doubled - 1 && d > spells.rbegin()->first))) {
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
            // check if after the insertion you can double another element
            // always keeping attention to the limit for the lightning
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
                // remove element in spell tree
                damage += d;
                spells.erase(-d);
                if (tp) {
                    // it was a lightning so move the minimum of doubling to spell tree
                    doubled--;
                    if (!doubling.empty()) {
                        if (l_doubled > 0 && l_doubled > doubled - 1) {
                            auto it = doubling.begin();
                            while (it != doubling.end()) {
                                if (it->second) {
                                    spells.insert(*it);
                                    damage -= it->first;
                                    l_doubled--;
                                    doubling.erase(it->first);
                                    break;
                                }
                                ++it;
                            }
                        } else {
                            spells.insert(*doubling.begin());
                            damage -= doubling.begin()->first;
                            if (doubling.begin()->second) l_doubled--;
                            doubling.erase(doubling.begin()->first);
                        }
                    }
                }
            } else {
                // remove element in doubling tree
                damage += 2 * d;
                doubling.erase(-d);
                if (tp) {
                    doubled--;
                    l_doubled--;
                } else {
                    //the deleted was a fire, add a new elem in doubling tree
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
        result.emplace_back(damage);
    }
    return result;
}

int main() {

    std::ios_base::sync_with_stdio(false);

    int n;

    std::cin >> n;
    std::vector<std::pair<int, int>> input;
    input.reserve(n);
    for (int i = 0; i < n; ++i) {
        int tp, d;
        std::cin >> tp >> d;
        input.push_back(std::make_pair(d, tp));
    }
    std::vector<long long> result = twoTypesSpell(input);
    for (auto damage : result) {
        std::cout << damage << std::endl;
    }

}

