#include<bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > vvi;

vvi g(750000);
long n, sqrtH = 0, t[750000], w[750000], l[750000], h = 0, v, p[750000], realK;

void high(long u, long p){
    if(p > h)
        h = p;
    l[u] = p;
    for(int i = 0; i < g[u].size(); i++){
        v = g[u][i];
        high(v, p + 1);
    }
}

void solve(int u){
    if(l[u] < sqrtH){
        p[u] = 0;
    }else{
        if(l[u] % sqrtH == 0)
            p[u] = t[u];
        else
            p[u] = p[t[u]];
    }
    for(int i = 0; i < g[u].size(); i++){
        solve(g[u][i]);
    }
}

long lca(int x, int y){
    vector<long> res;
    while(x != y){
        if(l[x] > l[y]){
            res.push_back(w[x]);
            x = t[x];
        }else{
            res.push_back(w[y]);
            y = t[y];
        }
    }
    if(res.size() < realK)
        return -1;
    else{
        sort(res.begin(), res.end());
        return res[realK - 1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b, k, q, realA, realB;
    int lastAns = 0;

    cin >> n;
    w[0] = 0;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b >> k;
        a--;
        b--;
        if(b > a)
            swap(a, b);
        g[b].push_back(a);
        t[a] = b;
        w[a] = k;
    }

    high(0, 0);
    sqrtH = sqrt(++h);

    cin >> q;
    lastAns = 0;
    while(q--){
        cin >> a >> b >> k;
        realA = ((a - 1) + lastAns) % n + 1;
        realB = ((b - 1) + (2 * lastAns)) % n + 1;
        realK = ((k - 1) + (3 * lastAns)) % n + 1;
        realA--;
        realB--;
        lastAns = lca(realA, realB);
        cout << lastAns << "\n";
        if(lastAns == -1)
            lastAns = 0;
    }
    return 0;
}
