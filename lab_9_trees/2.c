#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int maxSum = 0;

struct Info {
    int isBST;
    int sum;
    int min;
    int max;
};

struct Info findMaxSumBST(struct Node* root) {
    if (root == NULL) {
        struct Info temp = {1, 0, INT_MAX, INT_MIN};
        return temp;
    }

    struct Info left = findMaxSumBST(root->left);
    struct Info right = findMaxSumBST(root->right);

    struct Info curr;

    if (left.isBST && right.isBST &&
        root->data > left.max &&
        root->data < right.min) {

        curr.isBST = 1;
        curr.sum = left.sum + right.sum + root->data;

        curr.min = root->left ? left.min : root->data;
        curr.max = root->right ? right.max : root->data;

        if (curr.sum > maxSum)
            maxSum = curr.sum;
    } else {
        curr.isBST = 0;
        curr.sum = 0;
        curr.min = INT_MIN;
        curr.max = INT_MAX;
    }

    return curr;
}

int main() {
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(12);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(10);

    findMaxSumBST(root);

    printf("Maximum Sum BST = %d\n", maxSum);

    return 0;
}