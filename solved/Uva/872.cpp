#include<bits/stdc++.h>
using namespace std;

int dfs_num[20], inMap, g[20][20];
priority_queue<string, deque<string>, greater<string> > res;
map<char, int> ma;
map<int, char> ma2;

void sol(int u, string curr){
    curr += ma2[u];
    dfs_num[u] = 1;
    for(int i = 0; i < inMap; i++){
        if(dfs_num[i] != -1 && g[u][i] == 1){
            dfs_num[u] = -1;
            return;
        }
    }
    if(curr.length() == inMap){
        res.push(curr);
    }else{
        for(int i = 0; i < inMap; i++){
            if(dfs_num[i] == -1 && (g[u][i] == 1 || ( g[u][i] == 0 && g[i][u] == 0 ))){
                sol(i, curr);
            }
        }
    }
    dfs_num[u] = -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    int k = 0;
    char character, s, t, w;
    cin >> cases;
    string line;
    cin.ignore();
    while(cases--){
        inMap = 0;
        ma.clear();
        ma2.clear();
        cin.ignore();
        getline(cin, line);
        stringstream ss1(line);
        while(ss1 >> character){
            ma[character] = inMap;
            ma2[inMap++] = character;
        }
        for(int i = 0; i < inMap; i++){
            dfs_num[i] = -1;
            for(int j = 0; j < inMap; j++)
                g[i][j] = 0;
        }
        getline(cin, line);
        stringstream ss2(line);
        while(ss2 >> s){
            ss2 >> w;
            ss2 >> t;
            g[ma[s]][ma[t]] = 1;
        }
        for(int i = 0; i < inMap; i++){
            sol(i, "");
        }

        if(k++ != 0)
            cout << "\n";
        bool flag = true;
        while(!res.empty()){
            flag = false;
            string s = res.top(); res.pop();
            cout << s[0];
            for(int i = 1; i < s.length(); i++){
                cout << " " <<s[i];
            }
            cout << "\n";
        }
        if(flag)
            cout << "NO\n";
    }

    return 0;
}
