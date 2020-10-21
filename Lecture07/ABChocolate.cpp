#include <iostream>
#include <vector>


std::pair<int, int> divideChocolate(std::vector<int> &v, int sum) {
    int i = 1;
    sum -= v[0];
    while(i < v.size() && v[i]+v[i-1] <= sum){
        sum -= v[i];
        v[i] += v[i-1];
        i++;
    }

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