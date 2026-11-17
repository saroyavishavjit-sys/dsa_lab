#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void kthSmallest(struct Node* root, int k, int* count, int* ans) {
    if (root == NULL) return;

    kthSmallest(root->left, k, count, ans);

    (*count)++;
    if (*count == k) {
        *ans = root->data;
        return;
    }

    kthSmallest(root->right, k, count, ans);
}

void kthLargest(struct Node* root, int k, int* count, int* ans) {
    if (root == NULL) return;

    kthLargest(root->right, k, count, ans);

    (*count)++;
    if (*count == k) {
        *ans = root->data;
        return;
    }

    kthLargest(root->left, k, count, ans);
}

int main() {
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    int k = 3, count = 0, ans = -1;

    kthSmallest(root, k, &count, &ans);
    printf("%dth smallest: %d\n", k, ans);

    count = 0;
    ans = -1;
    kthLargest(root, k, &count, &ans);
    printf("%dth largest: %d\n", k, ans);

    return 0;
}