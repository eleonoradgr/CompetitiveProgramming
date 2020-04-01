#include <iostream>
#include <vector>


std::pair<int, int> divideChocolate(std::vector<int> &v, int sum) {
    int i = 0;
    while (v[i] <= sum) {
        sum -= v[i];
        i++;
        if (i< v.size())
            v[i] += v[i-1];
        else break;
    }
    if (i > 0 && i < v.size()-1 && v[i - 1] > sum + v[i]) i--;

    return std::make_pair(i,(v.size()-i));
}


int main() {
    int n;
    std::cin >> n;
    int sum = 0;
    std::vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        std::cin >>  tmp;
        v.push_back(tmp);
        sum += v[i];
    }
    std::pair<int, int> result= divideChocolate(v, sum);
    std::cout << result.first << " " << result.second;
}