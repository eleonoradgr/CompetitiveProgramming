//
// Created by eleonora on 15/11/20.n
//
#include <iostream>
#include <vector>
#include <algorithm>

struct segment{
    long long l;
    long long r;
    segment(long long begin, long long end): l(begin), r(end) {}
};

void perform_prefix( std::vector<long long> &p ){
    for(auto i = 1 ; i < p.size(); ++i ){
        p[i] = p[i] + p[i-1];
    }
}

long long maxsum(std::vector<long long> &array, std::vector<segment> &queries){
    long long maxsum = 0;
    std::vector<long long> prefix(array.size(),0);
    std::sort(array.begin(), array.end());
    for(auto elem : queries){
        prefix[elem.l -1] ++;
        if(elem.r != array.size())
            prefix[elem.r] --;
    }
    perform_prefix(prefix);
    std::sort(prefix.begin(), prefix.end());
    for(auto i = 0; i < array.size(); ++i){
        maxsum += array[i]*prefix[i];
    }

    return maxsum;
}

int main(){
    long long n, q;
    std::cin >> n;
    std::cin >> q;
    std::vector<long long> array;
    array.reserve(n);
    std::vector<segment> queries;

    for(auto i = 0; i < n; ++i){
        long long aus = 0;
        std::cin >> aus;
        array.emplace_back(aus);
    }
    for (auto i = 0; i < q; ++i){
        long long l, r = 0;
        std::cin >> l;
        std::cin >> r;
        queries.emplace_back(segment(l,r));
    }

    long long result = maxsum(array, queries);
    std::cout << result << std::endl;
}
