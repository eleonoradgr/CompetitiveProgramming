#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

std::string largestEvenNumber(std::vector<uint8_t> &v, int lenght){
    int even = -1;
    int i = 0;
    std::string result;
    result.reserve(lenght);
    while( even == -1 && i< v.size()-1){
        if(v[i] > 0){
            even = i;
            v[i]--;
        }
        i+=2;
    }
    for( i = v.size()-1 ; i>=0; i--){
        while(v[i] > 0){
            result.append(std::to_string(i));
            v[i]--;
        }
    }
    if(even>0){
        result.append(std::to_string(even));
    }
    return result;

}

int main(){
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++ ){
        std::string number;
        std::cin >> number;

        std::vector<uint8_t> v(10,0);
        for(std::string::iterator it = number.begin(); it != number.end(); ++it){
            int index = int(*it - '0');
            v[index] ++;
        }
        std::string result = largestEvenNumber(v, number.length());
        std::cout << result << std::endl;
        v.clear();
    }
}

