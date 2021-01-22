#include <iostream>
#include <vector>

//
// Created by eleonora on 08/12/20.
//
struct node {
    int res_is_part;
    int res_is_not_part;
    std::vector<int> children;

    node() {
        res_is_part = -1;
        res_is_not_part = -1;
    }
};

int vertex_cover_rec(std::vector<node> &tree, int i, int p, bool is_part) {
    int res = (is_part) ? 1 : 0;
    if (!is_part) {// the element is not part of cover set
        if (tree[i].res_is_not_part == -1) {
            for (int j : tree[i].children) {//all its children must be part of it
                if (j != p) {//it is not his parent
                    res += vertex_cover_rec(tree, j, i, true);
                }
            }
            tree[i].res_is_not_part = res;
        } else {
            res = tree[i].res_is_not_part;
        }

    } else {
        if (tree[i].res_is_part == -1) {
            for (int j : tree[i].children) {//all its children must could be or not part of it
                if (j != p) {//it is not his parent
                    res += std::min(vertex_cover_rec(tree, j, i, true), vertex_cover_rec(tree, j, i, false));
                }
            }
            tree[i].res_is_part = res;
        } else {
            res = tree[i].res_is_part;
        }
    }
    return res;
}

int vertex_cover(std::vector<node> &tree) {
    int res = std::min(vertex_cover_rec(tree, 0, -1, true), vertex_cover_rec(tree, 0, -1, false));
    return res;
}


int main() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 1 << std::endl;
        return 0;
    }
    std::vector<node> tree(n);

    for (int i = 0; i < n - 1; i++) {
        int from;
        int to;
        std::cin >> from >> to;
        tree[from - 1].children.push_back(to - 1);
        tree[to - 1].children.push_back(from - 1);
    }
    int colored = vertex_cover(tree);
    std::cout << colored << std::endl;
}
