#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector< pair<int, ii> > contr(20);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, t, w, cont;
    bool sol;
    while(cin >> n >> m && (n + m)){
        cont = 0;
        for(int i = 0; i < m; i++){
            cin >> s >> t >> w;
            contr[i] = make_pair(w, ii(s, t));
        }
        int perm[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        do{
            sol = true;
            for(int i = 0; i < m && sol; i++){
                pair<int, ii> curr = contr[i];
                if(curr.first < 0){
                    if(abs( perm[curr.second.first] - perm[curr.second.second]) < -curr.first)
                        sol = false;
                }else{
                    if(abs( perm[curr.second.first] - perm[curr.second.second]) > curr.first)
                        sol = false;
                }
            }
            if(sol)
                cont++;
        }while(next_permutation(perm, perm + n));
        cout << cont << "\n";
    }

    return 0;
}
