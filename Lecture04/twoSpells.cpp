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
        int damage = 0;
        auto l = lightning.crbegin();
        auto f = fire.crbegin();
        bool doubling = false;
        for (int j = 0; j<size; ++j){
            if(l != lightning.crend() && f != fire.crend()){
                if (doubling){
                    if (*l > *f){
                        doubling = true;
                        damage += 2*(*l);
                        ++l;
                    }else{
                        doubling = false;
                        damage += 2*(*f);
                        ++f;
                    }
                }else{
                    doubling = true;
                    damage += (*l);
                    ++l;
                }
            }else{
                if(l != lightning.crend()){
                    if(doubling){
                        damage += 2*(*l);
                    }else{
                        damage += (*l);
                    }
                    doubling = true;
                    ++l;
                }else{
                    if(doubling){
                        damage += 2*(*f);
                    }else{
                        damage += (*f);
                    }
                    doubling = false;
                    ++f;
                }
            }
        }
        std::cout << damage << std::endl;
    }

}