#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector< pair<int, ii> > edges;

int parent[10000], rankk[10000], cost, airports;

int find_(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find_(parent[x]);
}


void build_set(int n){
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
    return find_(x) == find_(y);
}

void kruskal(int a){
    for(int i = 0; i < edges.size(); i++){
        pair<int, ii> v = edges[i];
        if(v.first < a){
            if(!same_set(v.second.first, v.second.second)){
                cost = cost + v.first - a;
                airports--;
                union_(v.second.first, v.second.second);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k, m, n, s, t, w, a;
    cin >> k;
    for(int cases = 1; cases <= k; cases++){
        cin >> n >> m >> a;
        edges.clear();
        build_set(n);
        while(m--){
            cin >> s >> t >> w;
            s--; t--;
            edges.push_back(make_pair(w, ii(s, t)));
        }
        sort(edges.begin(), edges.end());
        cost = n * a;
        airports = n;
        kruskal(a);
        cout << "Case #" << cases << ": " << cost << " " << airports << "\n";

    }

    return 0;
}
