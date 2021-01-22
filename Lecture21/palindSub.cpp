//
// Created by eleonora on 07/12/20.
//
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    //code
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string c;
        std::cin >> c;
        int table[c.length() + 1][c.length() + 1];
        std::memset(table, 0, sizeof table);
        for (int j = 1; j <= c.length(); j++) {
            for (int z = 1; z <= c.length(); z++) {
                if (c[z - 1] == c[c.length() - j]) {
                    table[z][j] = std::max(table[z - 1][j], std::max(table[z][j - 1], table[z - 1][j - 1] + 1));;
                } else {
                    table[z][j] = std::max(table[z - 1][j], std::max(table[z][j - 1], table[z - 1][j - 1]));
                }
            }
        }
        std::cout << table[c.length()][c.length()] << std::endl;
    }

    return 0;
}
