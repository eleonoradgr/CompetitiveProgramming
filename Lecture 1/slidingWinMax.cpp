#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> maxinSub( std::vector<int> const &v, int k){
    std::vector<int> max;
    max.reserve( )
    std::make_heap(v.begin(), v.begin()+k );
    for(int i = k-1; i < n; i++ ){

    }
}

int main(){
    int t, n, k;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::cin >> k;
        std::vector<int> v;
        v.reserve( n );
        for (int j = 0; j < n ; j++) {
            int aux;
            std::cin >> aux;
            v.push_back(aux);
        }
        int res = maxinSub( v,k );
        std::cout << res << std::endl;
        v.clear();
    }
}

