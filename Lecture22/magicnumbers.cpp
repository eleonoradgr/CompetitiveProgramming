//
// Created by eleonora on 14/01/21.
//

#include <iostream>

int main(){
    long long aus;
    std::cin >> aus;
    int first_4 = 0;
    int second_4 = 0;
    while(aus > 0){
        int elem = aus %10;
        switch (elem) {
            case 1:
                first_4 = 0;
                second_4 = 0;
                break;
            case 4:
                if(first_4 && second_4){
                    std::cout<< "NO" << std::endl;
                    return 0;
                }
                if(first_4){
                    second_4 = 1;
                }else{
                    first_4 = 1;
                }
                break;
            default:
                std::cout<< "NO" << std::endl;
                return 0;
        }
        aus /= 10;
    }
    if(first_4 || second_4){
        std::cout<< "NO" << std::endl;
    }else{
        std::cout<< "YES" << std::endl;
    }
    return 0;
}