#include <iostream>

using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

pair<bool,pair<int,int>> checkBST( Node* tree){
    if (tree->right == NULL && tree->left == NULL){
        return make_pair(true, make_pair(tree->data, tree->data));
    }else if(tree->right != NULL && tree->left == NULL){
        pair<bool,pair<int,int>> rsubtree = checkBST(tree->right);
        //check if right subtree is BST and data of current node is smaller than the minimum in right subtree
        bool isbst = rsubtree.first && (tree->data <= rsubtree.second.first);
        pair<int,int> minmax = make_pair(min(rsubtree.second.first, tree->data),max(rsubtree.second.second, tree->data));
        return make_pair(isbst, minmax);
    }else if(tree->right == NULL && tree->left != NULL){
        pair<bool,pair<int,int>> lsubtree = checkBST(tree->left);
        //check if left subtree is BST and data of current node is greater than the maximum in left subtree
        bool isbst = lsubtree.first && (tree->data > lsubtree.second.second);
        pair<int,int> minmax = make_pair(min(lsubtree.second.first, tree->data),max(lsubtree.second.second, tree->data));
        return make_pair(isbst, minmax);
    }else{
        pair<bool,pair<int,int>> rsubtree = checkBST(tree->right);
        pair<bool,pair<int,int>> lsubtree = checkBST(tree->left);
        bool isbst = lsubtree.first && (tree->data > lsubtree.second.second) && rsubtree.first && (tree->data <= rsubtree.second.first);
        pair<int,int> minmax = make_pair(min(min(lsubtree.second.first,rsubtree.second.first), tree->data),
                max(max(lsubtree.second.second,rsubtree.second.second),tree->data));
        return make_pair(isbst, minmax);
    }
}

bool isBST(Node* root) {
    pair<bool,pair<int,int>> result = checkBST( root);
    return result.first;
}

int main(){
    return 0;
}