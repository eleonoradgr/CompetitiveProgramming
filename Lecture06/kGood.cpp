//
// Created by eleonora on 20/10/20.
//
#include <stdio.h>
#include <vector>
#include <unordered_map>

std::vector<std::pair<int,int>> kGoodSegment(std::vector<int> &a, int k) {
    int i = 0;
    int j = 0;
    int local_len = 0;
    int max_len = 0;
    std::unordered_map<int,int> um;
    std::vector<std::pair<int,int>> result;
    while(j < a.size()){
        auto found = um.find(a[j]);
        if(found == um.end()){
            //new element
            um.insert(std::make_pair(a[j],1));
            if(um.size() <= k){
                // still k good
                local_len = j - i;
                if(local_len == max_len){
                    //same length of the best
                    result.push_back(std::make_pair(i,j));
                }else{
                    if(local_len > max_len){
                        //longest one
                        result.clear();
                        result.push_back(std::make_pair(i,j));
                        max_len = local_len;
                    }
                }
            }else{

                //more than k different elements
                int deleted = 0;
                while(deleted == 0){
                    auto k_del = um.find(a[i]);
                    k_del->second--;
                    if(k_del->second == 0){
                        um.erase(k_del);
                        deleted = 1;
                    }
                    ++i;
                }
                local_len = j-i;

            }
        }else{
            //already seen element
            found->second += 1;
            local_len = j - i;
            if(local_len == max_len){
                //same length of the best
                result.push_back(std::make_pair(i,j));
            }else{
                if(local_len > max_len){
                    //longest one
                    result.clear();
                    result.push_back(std::make_pair(i,j));
                    max_len = local_len;
                }
            }
        }
        ++j;
    }
    return result;
}

int main(){
    int n, k;
    scanf("%d",&n);
    scanf("%d",&k);
    std::vector<int> a;
    a.reserve(n);
    for(auto i = 0; i<n; ++i){
        int aus;
        scanf("%d",&aus);
        a.push_back(aus);
    }
    std::vector<std::pair<int,int>> result = kGoodSegment(a,k);
    printf("%d ", result[0].first+1);
    printf("%d ", result[0].second+1);
    printf("\n");
    /*for(auto i = 0; i< result.size(); ++i){
        printf("%d ", result[i].first+1);
        printf("%d ", result[i].second+1);
        printf("\n");
    }*/
}
