#include <iostream>


int main() {
    unsigned int t, n = 0;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        unsigned int result, tmp = 0;
        unsigned int sum = 1;
        std::cin >> n;
        //xor all the element from 1 to n
        for(int j = 2; j <= n; ++j){
            sum = sum ^ j;
        }
        std::cin >> result;
        //xor all the element of the sequence
        for(int j = 0; j < n-2; ++j){
            std::cin >> tmp;
            result = result ^ tmp;
        }
        //considering x ^ x = 0 the remaining value is the missing number
        std::cout << (int)(result ^ sum) << std::endl;
    }

}
