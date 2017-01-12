#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, cont;
    string curr, aux;
    cin >> t;
    string v[2000];
    bitset<26> bs;
    while(t--){
        cin >> n >> k;
        priority_queue< pair<int, int>, deque< pair<int, int> >, greater< pair<int, int> > > pq;
        for(int i = 0; i < n; i++){
            cin >> curr;
            v[i] = curr;
            cont = 0;
            bs.reset();
            for(int j = 0; j < curr.length(); j++){
                curr[j] = tolower(curr[j]);
                if(bs[curr[j]] == 0 && (curr[j] == 'l' || curr[j] == 'i' || curr[j] == 't' || curr[j] == 'e'
                                        || curr[j] == 'j' || curr[j] == 'h' || curr[j] == 'o')){
                  bs[curr[j]] = 1;
                  cont++;
                }
            }
            pq.push(make_pair(cont, i));
        }
        cout << v[pq.top().second];
        pq.pop();
        while(--k){
            cout << " " <<v[pq.top().second];
            pq.pop();
        }
        cout << "\n";
    }

    return 0;
}
