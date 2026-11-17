
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data,size;
    struct node *left,*right;
    int lthread,rthread;
};

struct node *prev=NULL;

struct node *insert(struct node *root,int x){
    if(root==NULL){
        struct node *temp=malloc(sizeof(struct node));
        temp->data=x;
        temp->size=1;
        temp->left=NULL;
        temp->right=NULL;
        temp->lthread=0;
        temp->rthread=0;
        return temp;
    }

    if(x<root->data)
        root->left=insert(root->left,x);
    else if(x>root->data)
        root->right=insert(root->right,x);

    return root;
}

int getSize(struct node *root){
    if(root==NULL)
        return 0;

    root->size=1+getSize(root->left)+getSize(root->right);

    return root->size;
}

void convert(struct node *root){
    if(root==NULL)
        return;

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

    convert(root->right);
}

struct node *search(struct node *root,int x){
    while(root!=NULL){
        if(root->data==x)
            return root;

        if(x<root->data){
            if(root->lthread==1)
                return NULL;

            root=root->left;
        }
        else{
            if(root->rthread==1)
                return NULL;

            root=root->right;
        }
    }

    return NULL;
}

struct node *leftmost(struct node *root){
    while(root!=NULL && root->lthread==0)
        root=root->left;

    return root;
}

struct node *rightmost(struct node *root){
    while(root!=NULL && root->rthread==0)
        root=root->right;

    return root;
}

struct node *next(struct node *root){
    if(root==NULL)
        return NULL;

    if(root->rthread==1)
        return root->right;

    return leftmost(root->right);
}

struct node *prevNode(struct node *root){
    if(root==NULL)
        return NULL;

    if(root->lthread==1)
        return root->left;

    return rightmost(root->left);
}

struct node *kth(struct node *root,int k){
    if(root==NULL || k<=0 || k>root->size)
        return NULL;

    while(root!=NULL){
        int l=0;

        if(root->lthread==0)
            l=root->left->size;

        if(k==l+1)
            return root;

        if(k<=l)
            root=root->left;
        else{
            k=k-l-1;

            if(root->rthread==1)
                return NULL;

            root=root->right;
        }
    }

    return NULL;
}

void range(struct node *root,int l,int r){
    struct node *cur=NULL;

    while(root!=NULL){
        if(root->data>=l){
            cur=root;

            if(root->lthread==1)
                break;

            root=root->left;
        }
        else{
            if(root->rthread==1){
                root=NULL;
                break;
            }

            root=root->right;
        }
    }

    while(cur!=NULL && cur->data<=r){
        printf("%d ",cur->data);
        cur=next(cur);
    }

    printf("\n");
}

int main(){
    struct node *root=NULL;
    int n,q,x;
    char cmd[20];

    scanf("%s",cmd);

    if(strcmp(cmd,"BUILD")==0){
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",&x);
            root=insert(root,x);
        }
    }

    getSize(root);

    scanf("%s",cmd);

    if(strcmp(cmd,"CONVERT")==0){
        prev=NULL;
        convert(root);

        if(prev!=NULL && prev->right==NULL)
            prev->rthread=1;
    }

    scanf("%d",&q);

    while(q--){
        scanf("%s",cmd);

        if(strcmp(cmd,"NEXT")==0){
            scanf("%d",&x);

            struct node *temp=next(search(root,x));

            if(temp==NULL)
                printf("NULL\n");
            else
                printf("%d\n",temp->data);
        }

        else if(strcmp(cmd,"PREV")==0){
            scanf("%d",&x);

            struct node *temp=prevNode(search(root,x));

            if(temp==NULL)
                printf("NULL\n");
            else
                printf("%d\n",temp->data);
        }

        else if(strcmp(cmd,"RANGE")==0){
            int l,r;
            scanf("%d%d",&l,&r);
            range(root,l,r);
        }

        else if(strcmp(cmd,"KTH")==0){
            scanf("%d",&x);

            struct node *temp=kth(root,x);

            if(temp==NULL)
                printf("NULL\n");
            else
                printf("%d\n",temp->data);
        }
    }

    return 0;
}
