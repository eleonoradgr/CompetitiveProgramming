#include <iostream>
#include <vector>

struct node{
    int father;
    int res_child;
    int res_gchild;
    int is_leaf;
    node(int f, int rc, int rgc, int il): father(f), res_child(rc), res_gchild(rgc), is_leaf(il){};
};

int main(){
    int n;
    std::cin >> n;
    if (n == 0){
        std::cout<< 1<< std::endl;
        return 0;
    }
    std::vector<node> tree;
    tree.reserve(n);
    for(int i = 0; i<n; i++){
        tree.emplace_back(-1,0,0,1);
    }
    for(int i = 0; i<n-1; i++){
        int father;
        int child;
        std::cin >> father;
        std::cin >> child;
        if(child < father) std::swap(father, child);
        tree[child-1].father = father-1;
        tree[father-1].is_leaf = 0;
    }
    for(int i = n-1; i > 0; i--){
        int res = 0;
        if(tree[i].is_leaf){
           res = 1;
        }else{
            res = std::max(tree[i].res_child, tree[i].res_gchild +1);
        }
        if(tree[i].father != -1){
            tree[tree[i].father].res_child += res;
            if(tree[tree[i].father].father != -1){
                tree[tree[tree[i].father].father].res_gchild += res;
            }
        }
    }
    std::cout << std::max(tree[0].res_child, tree[0].res_gchild +1) << std::endl;
}
