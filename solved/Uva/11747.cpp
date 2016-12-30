#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

vector< pair<int, ii> > edges;
int parent[1000], rankk[1000];

void build_set(int n){
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

void union_(int x, int y){
    int xroot = find_(x);
    int yroot = find_(y);

    if(rankk[xroot] > rankk[yroot]){
        parent[yroot] = xroot;
    }else{
        parent[xroot] = yroot;
        if(rankk[xroot] == rankk[yroot]){
            rankk[yroot]++;
        }
    }
}

bool same_set(int x, int y){
    return find_(x) == find_(y);
}

void kruskal(){
    priority_queue<int, deque<int>, greater<int> > res;
    for(int i = 0; i < edges.size(); i++){
        pair<int, ii> v = edges[i];
        if(!same_set(v.second.first, v.second.second)){
            union_(v.second.first, v.second.second);
        }else{
            res.push(v.first);
        }
    }
    if(res.empty()){
        cout << "forest\n";
    }else{
        cout << res.top();
        res.pop();
        while(!res.empty()){
            cout << " " << res.top();
            res.pop();
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e, s, t, w;
    while(cin >> v >> e && v + e){
        edges.clear();
        build_set(v);
        while(e--){
            cin >> s >> t >> w;
            edges.push_back(make_pair(w, ii(s, t)));
        }
        sort(edges.begin(), edges.end());
        kruskal();
    }

    return 0;
}
