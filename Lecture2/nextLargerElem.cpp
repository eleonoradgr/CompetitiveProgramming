#include <iostream>
#include <vector>
#include <deque>


std::vector< long long> nextLargerElement(std::vector< long long> const& v){
    std::vector< long long> result(v.size());
    std::deque< std::pair< long long,int> > d;
    for( int i = 0; i < v.size(); i++){
        while (d.size() > 0 && v[i] > d.back().first) {
            result[d.back().second] = v[i];
            d.pop_back();
        }
        std::pair <long long, int> p(v[i],i);
        d.push_back(p);
    }
    while (d.size() > 0){
        result[ d.front().second] = -1;
        d.pop_front();
    }
    return result;
}

int main(){
    int t,n;
    std::cin >> t;
    for (int i = 0; i < t; ++i){
        std::cin >> n;
        std::vector< long long> v;
        v.reserve(n);
        for (int j = 0; j < n; j++){
             long long aus;
            std::cin >> aus;
            v.push_back(aus);
        }
        std::vector< long long> res(nextLargerElement(v));
        for (std::vector< long long>::iterator iter = res.begin(); iter != res.end(); ++iter){
            std::cout << *iter << " ";
        }
        std::cout <<  std::endl;

        v.clear();

    }

}
