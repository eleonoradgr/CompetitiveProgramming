#include <iostream>
#include <vector>

int missingNumber(std::vector<int> const &vect) {
    int n = vect.size() + 1;
    int sum = n * (n + 1) / 2;
    for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); ++it ){
        sum -= *it;
    }
    return sum;
}

int main() {
    int t, n;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::vector<int> v;
        v.reserve(n - 1);

        for (int j = 0; j < n - 1; j++) {
            int aux;
            std::cin >> aux;
            v.push_back(aux);
        }

        int res = missingNumber( v );
        std::cout << res << std::endl;

    }
}

