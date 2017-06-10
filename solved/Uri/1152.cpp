#include <bits/stdc++.h>
using namespace std;

#define edge pair< int, int >
vector< pair< int, edge > > g;
long long parent[200000];
long long findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

long long kruskal(bool check) {
    long long total =0;

    long i, pu, pv;
    sort(g.begin(), g.end()); // increasing weight

    if(check==1)reverse(g.begin(),g.end());

    for(i=total=0; i<g.size(); i++) {
        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);

        if(pu != pv) {
            total += g[i].first;
            parent[pu] = parent[pv];
        }
    }
    return total;
}

int main(){

    long long v,e,x,y,z,i;
    long long pesoTotal;
    long long pesoMinimo;
    while(cin >> v >> e && v !=0 && e != 0){
        g.clear();
        pesoTotal = 0;
        while(e--){
            cin >> x >> y >> z;
            pesoTotal+=z;
            edge arista(x,y);
            g.push_back(make_pair(z,arista));
        }

        for(i=0;i<v;i++){
            parent[i]=i;
        }
        pesoMinimo = kruskal(false);
        long long res = pesoTotal-pesoMinimo;
        cout<<res<<endl;
    }

    return 0;
}
