#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<pair<ii, string> > database;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, q, p, l, h, cont;
    string m;
    cin >> t;
    while(t--){

        cin >> n;
        database.clear();
        for(int i = 0; i < n; i++){
            cin >> m >> l >> h;
            database.push_back(make_pair(ii(l, h), m));
        }
        cin >> q;
        string res;
        while(q--){
            cin >> p;
            cont = 0;
            for(int i = 0; i < n; i++){
                pair<ii, string> curr = database[i];
                if(curr.first.first <= p && curr.first.second >= p){
                    cont++;
                    res = curr.second;
                    if(cont > 1){
                        cont = -1;
                        break;
                    }
                }
            }
            if(cont <= 0)
                cout << "UNDETERMINED\n";
            else
                cout << res << "\n";
        }
        if(t)
            cout << "\n";
    }

    return 0;
}
