#include<bits/stdc++.h>
using namespace std;
typedef vector< pair<int, int> > vii;

vii bst(500);
int n;
map<int, int> ma;

void bfs(int i){
    queue<int> c;
    c.push(i);
    int t = 0;
    while(!c.empty()){
        int u = c.front(); c.pop();
        if(t++ == 0)
            cout << ma[u];
        else
            cout << " " << ma[u];
        if(bst[u].first != -1)
            c.push(bst[u].first);
        if(bst[u].second != -1)
            c.push(bst[u].second);
    }

}

void insert_(int u, int i){
    if(ma[u] > ma[i]){
        if(bst[i].second == -1)
            bst[i].second = u;
        else
            insert_(u, bst[i].second);
    }else{
        if(bst[i].first == -1)
            bst[i].first = u;
        else
            insert_(u, bst[i].first);
    }
}

int main(){

    int c, u, t = 1;
    cin >> c;
    while(c--){
        ma.clear();
        bst.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> u;
            bst[i] = make_pair(-1, -1);
            ma[i] = u;
            if(i != 0)
                insert_(i, 0);
        }

        cout << "Case " << t++ << ":" << endl;
        bfs(0);
        cout << endl << endl;
    }
    return 0;
}
