#include<bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;

vvi g(1000000);
int in[1000000];

int n, m;

void solution(){
    queue<int> c;

    for(int i = 0; i < n; i++)
        if(in[i] == 0)
            c.push(i);
    int cont = 0, curr;
    queue<int> res;
    while(!c.empty()){
        curr = c.front(); c.pop();
        cont++;
        res.push(curr);
        for(int  i = 0; i < g[curr].size(); i++){
            in[g[curr][i]]--;
            if(in[g[curr][i]] == 0)
                c.push(g[curr][i]);
        }

    }

    if(cont == n){
        while(!res.empty()){
            cout << res.front() + 1 << endl;
            res.pop();
        }
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}

int main(){

    int r, s;

    while(cin >> n >> m && (n + m)){

        for(int i = 0; i < n; i++){
            g[i].clear();
            in[i] = 0;
        }

        while(m--){
            cin >> r >> s;
            r--;
            s--;
            in[s]++;
            g[r].push_back(s);
        }

        solution();

    }

    return 0;
}
