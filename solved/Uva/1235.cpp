#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector< pair<int, ii> > viii;

viii edgeList;
vector<string> num(501);
int parent[501], rankk[501], add;

int find_(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find_(parent[x]);
}

void make_set(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rankk[i] = 0;
    }
}

void union_(int x, int y){
    int xroot = find_(x);
    int yroot = find_(y);
    if(rankk[xroot] > rankk[yroot]){
        parent[yroot] = xroot;
    }else{
        parent[xroot] = yroot;
        if(rankk[xroot] == rankk[yroot])
            rankk[yroot]++;
    }
}

bool same_set(int x, int y){
    if(find_(x) == find_(y))
        return true;
    return false;
}

void calcW(int u){
    int w;
    for(int i = u - 1; i >= 0; i--){
        w = 0;
        w += min(abs(num[i][0] - num[u][0]), 10 - abs(num[i][0] - num[u][0]));
        w += min(abs(num[i][1] - num[u][1]), 10 - abs(num[i][1] - num[u][1]));
        w += min(abs(num[i][2] - num[u][2]), 10 - abs(num[i][2] - num[u][2]));
        w += min(abs(num[i][3] - num[u][3]), 10 - abs(num[i][3] - num[u][3]));

        if(i != 0)
            edgeList.push_back(make_pair(w, ii(i, u)));
        else
            add = min(add, w);
    }
}

int kruskal(){
    pair<int, ii> v;
    int res = 0;
    for(int i = 0; i < edgeList.size(); i++){
        v = edgeList[i];
        if(!same_set(v.second.first, v.second.second)){
            res += v.first;
            union_(v.second.first, v.second.second);
        }
    }
    return res + add;
}
int main(){
    int n, t;
    cin >> t;

    while(t--){
        cin >> n;
        add = 1000000;
        make_set(n + 1);
        num[0] = "0000";
        for(int i = 1; i <= n; i++){
            cin >> num[i];
            calcW(i);
        }
        sort(edgeList.begin(), edgeList.end());
        cout << kruskal() << "\n";
        edgeList.clear();
    }
    return 0;
}
