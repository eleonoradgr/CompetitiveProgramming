//
// Created by eleonora on 30/09/20.
// simple implementation, O(n^2)
//
#include <iostream>
#include <set>

int main() {

    std::ios_base::sync_with_stdio(false);

    int n;
    std::set<long long> lightning;
    std::set<long long> fire;
    std::cin >> n;
    int size = 0;
    for (int i = 0; i < n; ++i) {
        int tp,d;
        std::cin >> tp >> d;
        if (d > 0){
            size++;
            if(tp){
                lightning.insert(d);
            }else{
                fire.insert(d);
            }
        }else{
            size--;
            if(tp){
               auto el = lightning.find(-d);
               lightning.erase(el);
            }else{
                auto el = fire.find(-d);
                fire.erase(el);
            }
        }
        long long  damage = 0;
        auto l = lightning.crbegin();
        auto f = fire.crbegin();
        int l_used = 0;
        for (int j = 0; j < lightning.size() ; ++j){
            if( l != lightning.crend() && f != fire.crend()){
                    if (*l > *f && l_used < lightning.size()-1 ){
                        damage += 2*(*l);
                        ++l;
                        ++l_used;
                    }else{
                        damage += 2*(*f);
                        ++f;
                    }
            }else{
                if(f != fire.crend()){
                    damage += 2*(*f);
                    ++f;
                }else{
                    if(l_used < lightning.size()-1){
                        damage += 2*(*l);
                        ++l;
                        ++l_used;
                    }
                }
            }

        }
        while (l != lightning.crend()){
            damage += *l;
            ++l;
        }
        while (f != fire.crend()){
            damage += *f;
            ++f;
        }
        std::cout << damage << std::endl;
    }

}