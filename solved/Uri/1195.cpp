#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vii bst(500);
map<int, int> ma;
int n;

void pre(int u){
    cout << " " << ma[u];
    if(bst[u].first != -1) pre(bst[u].first);
    if(bst[u].second != -1) pre(bst[u].second);
}

void in(int u){
    if(bst[u].first != -1) in(bst[u].first);
    cout << " " << ma[u];
    if(bst[u].second != -1) in(bst[u].second);
}

void pos(int u){
    if(bst[u].first != -1) pos(bst[u].first);
    if(bst[u].second != -1) pos(bst[u].second);
    cout << " " << ma[u];
}

void add(int u, int i){
    if(ma[u] < ma[i]){
        if(bst[i].first == -1)
            bst[i].first = u;
        else
            add(u, bst[i].first);
    }else{
        if(bst[i].second == -1)
            bst[i].second = u;
        else
            add(u, bst[i].second);
    }
}

int main(){

    int c;
    cin >> c;
    for(int t = 1; t <= c; t++){
        cin >> n;
        ma.clear();
        for(int i = 0; i < n; i++){
            bst[i] = ii(-1, -1);
            cin >> ma[i];
            if(i != 0)
                add(i, 0);
        }

        cout << "Case " << t << ":" << endl;
        cout << "Pre.:";
        pre(0);
        cout << endl <<"In..:";
        in(0);
        cout << endl <<"Post:";
        pos(0);
        cout << endl << endl;
    }
    return 0;
}
