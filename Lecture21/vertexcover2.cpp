#include <iostream>
#include <vector>
#include <algorithm>

//
// Created by eleonora on 08/12/20.
//
struct node{
    std::vector<int> connected;
    int colored;
    int is_leaf;
    node(int c, int il): colored(c), is_leaf(il){};
};

int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 1 << std::endl;
        return 0;
    }
    std::vector <node> tree;
    tree.reserve(n);
    for (int i = 0; i < n; i++) {
        tree.emplace_back( 0, 1);
    }
    for (int i = 0; i < n - 1; i++) {
        int elem1;
        int elem2;
        std::cin >> elem1;
        std::cin >> elem2;
        tree[elem1 - 1].connected.push_back(elem2-1);
        if(tree[elem1-1].connected.size() > 1)
            tree[elem1-1].is_leaf = 0;
        tree[elem2 - 1].connected.push_back(elem1-1);
        if(tree[elem2-1].connected.size() > 1)
            tree[elem2-1].is_leaf = 0;
    }
    int con = 1;
    while(con){
        con = 0;
        for(int i = 0; i<n; i++){
            if (tree[i].is_leaf && !tree[i].connected.empty() && tree[i].connected[0] != -1){
                tree[tree[i].connected[0]].colored = 1;
                auto del = find(tree[tree[i].connected[0]].connected.begin(),tree[tree[i].connected[0]].connected.end(), i);
                tree[tree[i].connected[0]].connected.erase(del);
                tree[i].connected[0] = -1;
            }
        }
        for (int i = 0; i < n; i++){
            if(tree[i].colored &&  tree[i].connected[0] != -1){
                for (auto elem : tree[i].connected){
                    auto del = find(tree[elem].connected.begin(),tree[elem].connected.end(), i);
                    if(del != tree[elem].connected.end())tree[elem].connected.erase(del);
                }
            }
        }
        for(int i = 0; i< n; i++){
            if(! tree[i].colored && tree[i].connected.size() == 1 && tree[i].connected[0] != -1){
                    tree[i].is_leaf = 1;
                    con = 1;
            }
        }
    }

    int colored = 0;
    for (int i = 0; i <n; i++){
        if(tree[i].colored)
            colored++;
    }
    std:: cout << colored << std::endl;
}


