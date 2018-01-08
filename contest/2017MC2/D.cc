#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e3 + 7;
const int INF = 1e9;
typedef pair<int, int> ii;

vector<vector<ii> > g1(N), g2(N);

int d1[N], d2[N];

void dt(int s, bool o){
    d1[s] = d2[s] = 0;
    priority_queue<ii, deque<ii>, greater<ii> > q;
    q.push(ii(s, 0));

    while(!q.empty()){
        ii curr = q.top(); q.pop();
        int d = curr.second; int u = curr.first;
        if(o){
            if(d > d1[u]) continue;
            for(int i = 0; i < g1[u].size(); i++){
                ii v = g1[u][i];
                if(d1[u] + v.second < d1[v.first]){
                    d1[v.first] = d1[u] + v.second;
                    q.push(ii(v.first, d1[v.first]));
                }
            }
        }else{
            if(d > d2[u]) continue;
            for(int i = 0; i < g2[u].size(); i++){
                ii v = g2[u][i];
                if(d2[u] + v.second < d2[v.first]){
                    d2[v.first] = d2[u] + v.second;
                    q.push(ii(v.first, d2[v.first]));
                }
            }
        }
    }
}

int main(){

    int n, m, x, u, v, w;
    cin >> n >> m >> x;

    x--;
    for(int i = 0; i < n; i++)
        d1[i] = d2[i] = INF;

    while(m--){
        cin >> u >> v >> w;
        u--; v--;
        g1[u].push_back(ii(v, w));
        g2[v].push_back(ii(u, w));
    }

    int res = 0;
    dt(x, 0); dt(x, 1);
    for(int i = 0; i < n; i++){
        res = max(res, d1[i] + d2[i]);
    }

    cout << res << endl;

    return 0;
}
