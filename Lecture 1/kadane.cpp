#include <iostream>
#include <vector>
#include <limits>

int kadane( const std::vector<int> &vect ){
    int max = std::numeric_limits<int>::min();
    int sum = 0;
    for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); ++it ){

        if (sum >= 0)
            sum += *it;
        else
            sum =*it;

        if (sum > max)
            max = sum;
    }
    return max;
}

int main(){
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i){
        int n;
        std::cin >> n;
        std::vector<int> v;
        v.reserve(n);
        for(int j = 0; j < n; ++j){
            int aux;
            std::cin >> aux;
            v.push_back(aux);
        }
        int res = kadane( v );
        std::cout << res << "\n";
    }
}
