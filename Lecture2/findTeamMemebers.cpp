#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

struct team {
    uint16_t i;
    uint16_t j;
    int strenght;

    team(uint16_t i, uint16_t j, int s) : i{i}, j{j}, strenght{s} {}
};

bool compareTeam(team const &t1, team const &t2){
    return ( t1.strenght < t2.strenght);
}

std::vector<uint16_t> findTeam(int n, std::vector<team> &vector) {
    std::vector<uint16_t> couples(2*n);
    sort (vector.begin(), vector.end(), compareTeam);
    for(std::vector<team>::const_reverse_iterator it = vector.rbegin(); it != vector.rend(); ++it){
        if(couples[ (it->i)-1 ] == 0 && couples[(it->j)-1] == 0){
            couples[(it->i)-1] = it->j;
            couples[(it->j)-1] = it->i;
        }
    }
    return couples;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<team> teams;
    teams.reserve(n * (n - 1) / 2);
    for (uint16_t i = 2; i <= 2 * n; i++) {
        for (uint16_t j = 1; j < i; j++) {
            int aus;
            std::cin >> aus;
            teams.push_back(team(i, j, aus));
        }
    }
    std::vector<uint16_t> result (findTeam( n, teams));
    for (auto &it : result){
        std::cout << it << " ";
    }
}


