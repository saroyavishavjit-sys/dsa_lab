
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *insert(struct node *root,int x){
    if(root==NULL){
        struct node *temp=malloc(sizeof(struct node));
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }

    if(x<root->data)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);

    return root;
}

void inorder(struct node *root,int a[],int *i){
    if(root==NULL)
        return;

    inorder(root->left,a,i);
    a[(*i)++]=root->data;
    inorder(root->right,a,i);
}

int main(){
    int n;
    scanf("%d",&n);

    struct node *root=NULL;

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        root=insert(root,x);
    }

    int a[n],i=0;
    inorder(root,a,&i);

    int q;
    scanf("%d",&q);

    while(q--){
        int k;
        scanf("%d",&k);

        if(k<=0 || k>n)
            printf("-1\n");
        else
            printf("%d\n",a[k-1]);
    }

    return 0;
}
