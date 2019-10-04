#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxinSub( std::vector<int> const &v, int k){
    std::vector<int> res;
    res.reserve(v.size()-k+1);
    std::deque< std::pair<int,int> > d;
    for(int i = 0; i < v.size() ; i++ ){

        if (d.size() > 0 ){

            if (i - d.front().second > k ){
                d.pop_front();
            }
            while(d.size() > 0 && v[i] > d.back().first){
                d.pop_back();
            }
        }

        std::pair <int, int> p(v[i],i);
        d.push_back(p);

        if(i >= k-1){
            res.push_back(d.front().first);
        }
    }
    return res;
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
        std::vector<int> res = maxinSub( v, k );
        for(std::vector<int>::const_iterator it = res.begin(); it!= res.end(); it++ ){
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        v.clear();
    }
}

