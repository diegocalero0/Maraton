#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector< pair<int, ii> > vvii;
int n;
int adj[30][30], parent[30], rankk[30];
priority_queue< pair<int, ii>, deque<pair<int, ii> >, greater<pair<int, ii> > > res;
vvii g;

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

bool same_component(int x, int y){
    if(find_(x) == find_(y))
        return true;
    return false;
}

void kruskal(){
    for(int i = 0; i < g.size(); i++){
        pair<int, ii> u = g[i];
        if(!same_component(u.second.first, u.second.second)){
            res.push(u);
            union_(u.second.first, u.second.second);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, case_ = 1;
    char w;
    cin >> t;

    while(t--){
        cin >> n;
        make_set(n);
        g.clear();
        for(int i = 0; i < n; i++){
            cin >> adj[i][0];
            for(int j = 1; j < n; j++){
                cin >> w;
                cin >> adj[i][j];
                if(i < j && adj[i][j] != 0){
                    g.push_back(make_pair(adj[i][j], ii(i, j)));
                }
            }
        }
        sort(g.begin(), g.end());
        kruskal();
        cout << "Case " << case_++ << ":" << endl;
        while(!res.empty()){
            pair<int, ii> aux = res.top();
            res.pop();
            cout << char(aux.second.first + 65) << "-" << char(aux.second.second + 65) << " " << aux.first << endl;
        }
    }

    return 0;
}
