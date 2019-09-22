#include <iostream>
#include <vector>

std::vector<int> findReverseLeaders(const std::vector<int>& vect){
    int max = -1;
    std::vector<int> v;
    v.reserve(vect.size());
    for (std::vector<int>::const_reverse_iterator it = vect.rbegin(); it < vect.rend(); ++it){
        if(*it >= max){
            max = *it;
            v.push_back(*it);
        }
    }
    return v;
}

int main() {
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
        std::vector<int> v1;
        v1.reserve(n);
        for( int j = 0; j < n; j++){
            int aux;
            std::cin >> aux;
            v1.push_back(aux);
        }
        std::vector<int> v2 = findReverseLeaders( v1 );

        for (std::vector<int>::reverse_iterator it = v2.rbegin(); it < v2.rend(); ++it ){
            std::cout << *it << " ";
        }
        std::cout <<  "\n";

        v1.clear();


    }
    return 0;
}