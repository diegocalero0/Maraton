#include<bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > vvi;

vvi g(100000);
vector<int> l(100000), p(100000), t(100000);
vector<long long> wp(100000), w(100000);
int n, h, sqrtH;

void buildG(int u){
    int k, v;
    if(l[u] < sqrtH){
        p[u] = 0;
    }else if(l[u] % sqrtH == 0){
        p[u] = t[u];
        wp[u] = w[u];
    }else{
        p[u] = p[t[u]];
        wp[u] = wp[t[u]];
    }
    for(int i = 0; i < g[u].size(); i++){
        buildG(g[u][i]);
    }
}

long long solve(int x, int y){
    long long res = 0;
    while(p[x] != p[y]){
        if(l[x] > l[y]){
            res += wp[x];
            x = p[x];
        }else{
            res += wp[y];
            y = p[y];
        }
    }

    while(x != y){
        if(l[x] > l[y]){
            res += w[x];
            x = t[x];
        }else{
            res += w[y];
            y = t[y];
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, h;

    while(cin >> n && n){

        l[0] = 0;
        h = 0;
        for(int i = 0; i < n; i++){
            g[i].clear();
        }
        for(int i = 1; i < n; i++){
            cin >> t[i];
            cin >> w[i];
            g[t[i]].push_back(i);
            l[i] = l[t[i]] + 1;
            if(l[i] > h)
                h = l[i];
        }

        sqrtH = sqrt(++h);

        cin >> q;
        int s, t;
        for(int i = 0; i < q; i++){
            cin >> s >> t;
            if(i == 0)
                cout << solve(s, t);
            else
                cout << " " << solve(s, t);
        }
        cout << "\n";
    }
    return 0;
}
