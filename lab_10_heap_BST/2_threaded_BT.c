
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
    int lthread,rthread;
};

struct node *prev=NULL;

void convert(struct node *root){
    if(root==NULL)
        return;

    if(root->lthread==0)
        convert(root->left);

    if(root->left==NULL){
        root->left=prev;
        root->lthread=1;
    }

    if(prev!=NULL && prev->right==NULL){
        prev->right=root;
        prev->rthread=1;
    }

    prev=root;

    if(root->rthread==0)
        convert(root->right);
}

struct node *leftmost(struct node *root){
    while(root!=NULL && root->lthread==0)
        root=root->left;

    return root;
}

void inorder(struct node *root){
    struct node *cur=leftmost(root);

    while(cur!=NULL){
        printf("%d ",cur->data);

        if(cur->rthread==1)
            cur=cur->right;
        else
            cur=leftmost(cur->right);
    }
}

int main(){
    int n;
    scanf("%d",&n);

    struct node *a[n];

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);

        if(x==-1)
            a[i]=NULL;
        else{
            a[i]=malloc(sizeof(struct node));
            a[i]->data=x;
            a[i]->left=NULL;
            a[i]->right=NULL;
            a[i]->lthread=0;
            a[i]->rthread=0;
        }
    }

    for(int i=0;i<n;i++){
        if(a[i]!=NULL){
            if(2*i+1<n)
                a[i]->left=a[2*i+1];

            if(2*i+2<n)
                a[i]->right=a[2*i+2];
        }
    }

    struct node *root=a[0];

    convert(root);
    inorder(root);

    return 0;
}
