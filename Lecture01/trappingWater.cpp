#include <iostream>
#include <vector>

int trappingWater( std::vector<int> const &v){
    std::vector<int>  vMaxl;
    std::vector<int> vMaxr;
    std::vector<int> res;
    vMaxl.reserve(v.size());
    vMaxr.reserve(v.size());
    res.reserve(v.size());
    int max = 0;
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > max){
            max = v[i];
            vMaxl[i] = v[i];
        }else{
            vMaxl[i] = max;
        }
    }
    max = 0;
    for(int i = v.size()-1; i >= 0; i--){
        if(v[i] > max){
            max = v[i];
            vMaxr[i] = v[i];
        }else{
            vMaxr[i] = max;
        }
    }

    for(int i = 0; i < v.size(); i++){
       sum += ((vMaxl[i] - vMaxr[i] < 0)? vMaxl[i] : vMaxr[i]) - v[i];
    }
    return sum;

}

int main(){
    int t, n;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> n;
        std::vector<int> v;
        v.reserve( n );
        for (int j = 0; j < n ; j++) {
            int aux;
            std::cin >> aux;
            v.push_back(aux);
        }
        int res = trappingWater( v );
        std::cout << res << std::endl;
        v.clear();
    }
}

