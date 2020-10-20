//
// Created by eleonora on 30/09/20.
//
#include <iostream>
#include <set>

int main() {

    std::ios_base::sync_with_stdio(false);

    int n;
    std::multiset<int> lightning;
    std::multiset<int> fire;
    std::cin >> n;
    int size = 0;
    for (int i = 0; i < n; ++i) {
        int tp,d;
        std::cin >> tp;
        std::cin >> d;
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
        unsigned long int damage = 0;
        auto l = lightning.crbegin();
        auto f = fire.crbegin();
        int doubling = (fire.size() == 0 )? lightning.size() - 1 : lightning.size();
        for (int j = 0; j < doubling ; ++j){
            if( l != lightning.crend() && f != fire.crend()){
                    if (*l >= *f && lightning.size()> 1 ){
                        damage += 2*(*l);
                        ++l;
                    }else{
                        damage += 2*(*f);
                        ++f;
                    }
            }else{
                if(f != fire.crend()){
                    damage += 2*(*f);
                    ++f;
                }else{
                    damage += 2*(*l);
                    ++l;
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