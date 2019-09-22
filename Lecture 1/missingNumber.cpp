#include <iostream>
#include <vector>

int missingNumber(const std::vector<int> &vect){

}

int main(){
    int t,n;
    std::cin >> t;
    for (int i = 0; i<t ; ++i){
        std::cin >> n;
        std::vector<int> v;
        v.reserve(n-1);
        for (int j = 0; j<n-1; j++){
            int aux;
            std::cin >> aux;
            v.push_back(aux);
        }

    }
}

