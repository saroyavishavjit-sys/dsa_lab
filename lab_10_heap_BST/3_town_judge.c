
#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int a[n],parent[n],visited[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        parent[i]=-1;
        visited[i]=0;
    }

    for(int i=0;i<n;i++){
        if(a[i]!=-1){
            int l=2*i+1;
            int r=2*i+2;

            if(l<n && a[l]!=-1)
                parent[l]=i;

            if(r<n && a[r]!=-1)
                parent[r]=i;
        }
    }

    int s,k;
    scanf("%d%d",&s,&k);

    int start=-1;

    for(int i=0;i<n;i++){
        if(a[i]==s){
            start=i;
            break;
        }
    }

    if(start==-1)
        return 0;

    int q[n],dist[n];
    int front=0,rear=0;

    q[rear]=start;
    dist[rear++]=0;
    visited[start]=1;

    while(front<rear){
        int cur=q[front];
        int d=dist[front];
        front++;

        if(d==k)
            printf("%d ",a[cur]);

        if(d<k){
            int x[3]={parent[cur],2*cur+1,2*cur+2};

            for(int i=0;i<3;i++){
                int v=x[i];

                if(v>=0 && v<n && a[v]!=-1 && !visited[v]){
                    visited[v]=1;
                    q[rear]=v;
                    dist[rear++]=d+1;
                }
            }
        }
    }

    return 0;
}
