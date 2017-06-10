#include<bits/stdc++.h>
using namespace std;

int n, m;
vector< vector<int> > g(100);
vector<int> in(100);
map<string, int> mp;
map<int, string> mp2;
int ca= 1;
void kanhAlgorithm(){
    priority_queue<int, deque<int>, greater<int> > c;

    for(int i = 0; i < n; i++)
        if(in[i] == 0)
            c.push(i);
    vector<int> ord;
    int curr;
    while(!c.empty()){
        curr = c.top(); c.pop();
        ord.push_back(curr);
        for(int i = 0; i < g[curr].size(); i++){
            in[g[curr][i]]--;
            if(in[g[curr][i]] == 0){
                c.push(g[curr][i]);
            }
        }
    }

    cout << "Case #" << ca++ << ": Dilbert should drink beverages in this order:";
    for(int i = 0; i < n; i++)
        cout << " " << mp2[ord[i]];
    cout << "." << endl;
    cout << endl;

}

int main(){
    string name;
    string n1, n2;
    while(cin >> n){
        mp.clear();
        mp2.clear();
        in.clear();
        for(int i = 0; i < n; i++){
            g[i].clear();
            in[i] = 0;
            cin >> name;
            mp[name] = i;
            mp2[i] = name;
        }

        cin >> m;

        while(m--){
            cin >> n1 >> n2;
            g[mp[n1]].push_back(mp[n2]);
            in[mp[n2]]++;
        }



        kanhAlgorithm();

    }


    return 0;
}
