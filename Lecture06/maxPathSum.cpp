#include <iostream>
#include <climits>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

std::pair<int, int> maxPathSumRec(Node *node) {
    if (node->right == NULL && node->left == NULL)
        return std::make_pair(INT_MIN, node->data);
    std::pair<int, int> resR, resL = std::make_pair(NULL, NULL);
    if (node->right != NULL)
        resR = maxPathSumRec(node->right);
    if (node->left != NULL)
        resL = maxPathSumRec(node->left);
    int maxsum, partial = 0;
    if (node->right != NULL && node->left != NULL) {
        int path = resR.second + resL.second + node->data;
        maxsum = std::max(std::max(resR.first, resL.first), path);
        partial = std::max(resR.second, resL.second) + node->data;
    } else if (node->right != NULL) {
        maxsum = resR.first;
        partial = resR.second + node->data;
    } else {
        maxsum = resL.first;
        partial = resL.second + node->data;
    }
    return std::make_pair(maxsum,partial);

}

int maxPathSum(Node *root) {
    std::pair<int, int> result = maxPathSumRec(root);
    return result.first;
}
