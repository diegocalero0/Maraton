#include <bits/stdc++.h>

using namespace std;

int a[100000];

const int INF = 2000000000;


int getMid(int s, int e) {
    return  (e +s)/2;
}

int getRMQ(int *st, int ss, int se, int qs, int qe, int si)
{
    //Total Overlap
    if (qs <= ss && qe >= se)
        return st[si];

    //No overLap
    if (se < qs || ss > qe)
        return INF;

    int mid = getMid(ss, se);
    return min(getRMQ(st, ss, mid, qs, qe, 2*si+1), getRMQ(st, mid+1, se, qs, qe, 2*si+2) );
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = getMid(ss, se);
    st[si] =  min(constructSTUtil(arr, ss, mid, st, si*2+1),
              constructSTUtil(arr, mid+1, se, st, si*2+2) );
    return st[si];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));

    int max_size = 2*(int)pow(2, x) - 1;

    int *st = new int[max_size];

    constructSTUtil(arr, 0, n-1, st, 0);

    return st;
}

int main(){

    int t,caseno=1;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",a+i);
        }

        int *st = constructST(a,n);

        priority_queue<int, vector<int>, greater<int> > pq;

        int sizeq=0;
        for(int i=0;i<n-1;i++){
            int r= getRMQ(st,0,n-1,i+1,n-1,0);
            if(r<a[i]){
                pq.push(a[i]);
                sizeq++;
            }
        }


        printf("%d\n",sizeq);
        while(!pq.empty()){
            printf("%d\n",pq.top());
            pq.pop();
        }
    }
    return 0;
}
