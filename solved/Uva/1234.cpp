#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

priority_queue< pair<int, ii> > edgeList;
int m, parent[10000], rankk[10000], cost;

void make_set(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rankk[i] = 0;
    }
}

int find_(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find_(parent[x]);
}

int union_(int x, int y){
    int xroot = find_(x);
    int yroot = find_(y);

    if(rankk[xroot] > rankk[yroot]){
        parent[yroot] =  xroot;
    }else{
        parent[xroot] = yroot;
        if(rankk[xroot] == rankk[yroot])
            rankk[yroot]++;
    }
}

bool same_set(int x, int y){
    return find_(x) == find_(y);
}

void kruskal(){
    int maxST = 0;
    while(!edgeList.empty()){
        pair<int, ii> v = edgeList.top(); edgeList.pop();
        if(!same_set(v.second.first, v.second.second)){
            maxST += v.first;
            union_(v.second.first, v.second.second);
        }
    }
    cost -= maxST;
}

int main(){
    int k, n, s, t, w;
    cin >> k;
    while(k--){
        cin >> n >> m;
        make_set(n);
        cost = 0;
        while(m--){
            cin >> s >> t >> w;
            s--;
            t--;
            cost += w;
            edgeList.push(make_pair(w, ii(s, t)));
        }
        kruskal();
        cout << cost << endl;
    }
    cin >> k;
    return 0;
}
