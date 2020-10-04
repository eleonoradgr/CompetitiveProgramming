#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

template<typename T>
std::vector<T> getInputs();

int64_t numberOfWays(std::vector<int64_t > const& v);

int main() {
    std::vector<int64_t > v = getInputs<int64_t >();
    int64_t result = numberOfWays(v);
    std::cout<< result;
    v.clear();
    return 0;
}

template<typename T>
std::vector<T> getInputs() {
    int n;
    std::cin >> n;
    std::vector<T> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        T tmp;
        std::cin >> tmp;
        result.push_back(tmp);
    }
    return result;
}

int64_t numberOfWays(std::vector<int64_t > const &v) {

    int64_t sum = std::accumulate(v.begin(), v.end(), .0);
    int64_t result = 0;
    if (sum % 3 == 0){
        std::vector<int64_t > prefixes(v.size()),suffixes(v.size()) ;
        int64_t partial = 0;

        for (int i = v.size()-1; i >= 0; --i){
            partial += v[i];
            if (partial == sum/3){
                suffixes[i] = (i<v.size()-1)? suffixes[i+1]+1 : 1;
            }else{
                suffixes[i] = (i<v.size()-1)? suffixes[i+1] : 0;
            }
        }
        partial = 0;
        for (int i = 0; i< v.size()-2; ++i){
            partial +=v[i];
            if (partial == sum/3) {
                result += suffixes[i + 2];
            }

        }
    }
    return result;

}

