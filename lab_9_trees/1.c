#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct QueueNode {
    struct Node *node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void topView(struct Node* root) {
    if (root == NULL) return;

    struct QueueNode queue[MAX];
    int front = 0, rear = 0;

    int values[MAX] = {0};
    int visited[MAX] = {0};
    int offset = MAX / 2;
    int minHD = 0, maxHD = 0;

    queue[rear++] = (struct QueueNode){root, 0};

    while (front < rear) {
        struct QueueNode current = queue[front++];
        struct Node* node = current.node;
        int hd = current.hd;
        int index = hd + offset;

        if (!visited[index]) {
            values[index] = node->data;
            visited[index] = 1;
        }

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            queue[rear++] = (struct QueueNode){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct QueueNode){node->right, hd + 1};
    }

    for (int hd = minHD; hd <= maxHD; hd++) {
        int index = hd + offset;
        if (visited[index])
            printf("%d ", values[index]);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(6);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(5);

    topView(root);

    return 0;
}