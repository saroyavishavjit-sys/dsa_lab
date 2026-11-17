#include <stdio.h>
#include <stdlib.h>

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

struct Node *first = NULL, *middle = NULL;
struct Node *last = NULL, *prev = NULL;

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);

    if (prev != NULL && root->data < prev->data) {
        if (first == NULL) {
            first = prev;
            middle = root;
        } else {
            last = root;
        }
    }

    prev = root;

    inorder(root->right);
}

void recoverBST(struct Node* root) {
    inorder(root);

    if (first != NULL && last != NULL) {
        int temp = first->data;
        first->data = last->data;
        last->data = temp;
    } else if (first != NULL && middle != NULL) {
        int temp = first->data;
        first->data = middle->data;
        middle->data = temp;
    }
}

void printInorder(struct Node* root) {
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    struct Node* root = createNode(6);
    root->left = createNode(10);
    root->right = createNode(2);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(7);
    root->right->right = createNode(12);

    printf("Before recovery: ");
    printInorder(root);

    recoverBST(root);

    printf("\nAfter recovery: ");
    printInorder(root);

    return 0;
}