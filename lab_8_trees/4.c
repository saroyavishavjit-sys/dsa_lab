
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int x) {
    if (root == NULL) {
        struct Node* temp = malloc(sizeof(struct Node));
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int arr[] = {8, 3, 5, 1, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = NULL;

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Sorted array: ");
    inorder(root);

    return 0;
}
