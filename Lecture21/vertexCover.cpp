#include <iostream>
#include <vector>

//
// Created by eleonora on 08/12/20.
//
struct node{
    int father;
    int colored;
    int is_leaf;
    node(int f, int c, int il): father(f), colored(c), is_leaf(il){};
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
        tree.emplace_back(-1, 0, 1);
    }
    for (int i = 0; i < n - 1; i++) {
        int father;
        int child;
        std::cin >> father;
        std::cin >> child;
        if (child < father) std::swap(father, child);
        tree[child - 1].father = father - 1;
        tree[father - 1].is_leaf = 0;
    }
    for ( int i = n; i > 0; i--){
        if(tree[i].is_leaf && tree[i].father != -1){
            tree[tree[i].father].colored = 1;
        }else{
            if(!tree[i].colored && tree[i].father != -1){
                tree[tree[i].father].colored = 1;
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
