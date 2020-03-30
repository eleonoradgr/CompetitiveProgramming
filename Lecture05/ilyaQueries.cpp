#include <iostream>
#include <vector>

std::vector<int> buildSuffixSum(std::string str){
    std::vector<int> v;
    v.reserve( str.size() );
    v[0] = 0;
    for (int i = 1; i<str.size(); i++){
        if (str[i] == str[i-1]){
            v[i] = v[i-1]+1;
        }else{
            v[i]=v[i-1];
        }
    }
    return v;
}



int main(){
    int n;
    std::string str;
    std::cin >> str;

    std::vector<int> v = buildSuffixSum(str);

    std::cin >> n;
    for (int i = 0; i<n; i++){
        int x,y;
        std::cin >> x;
        std::cin >> y;
        std::cout << v[y-1]-v[x-1] << std::endl;
    }

}