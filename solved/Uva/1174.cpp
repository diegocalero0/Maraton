#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector< pair<int, ii> > edgeList;

int parent[2000], rankk[2000];

void make_set(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rankk[i] = 0;
    }
}

int find_(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find_(parent[x]);
}

void union_(int x, int y){
    int xroot = find_(x);
    int yroot = find_(y);

    if(rankk[xroot] > rankk[yroot]){
        parent[yroot] = xroot;
    }else{
        parent[xroot] = yroot;
        if(rankk[xroot] == rankk[yroot])
            rankk[yroot]++;
    }
}

bool same_set(int x, int y){
    if(find_(x) == find_(y))
        return true;
    return false;
}

long MST(){
    long res = 0;
    for(int i = 0; i < edgeList.size(); i++){
        pair<int, ii> aux = edgeList[i];
        if(!same_set(aux.second.first, aux.second.second)){
            res += aux.first;
            union_(aux.second.first, aux.second.second);
        }
    }
    return res;
}

int main(){

    int t, n, m, inMap, w, ri, si, num = 0;
    string r, s;
    cin >> t;

    while(t--){
        cin >> m;
        edgeList.clear();
        make_set(m);
        inMap = 0;
        cin >> n;
        map<string, int> ma;
        while(n--){
            cin >> r >> s >> w;

            if(ma.find(r) == ma.end()){
                ma[r] = inMap;
                ri = inMap++;
            }else{
                ri = ma[r];
            }

            if(ma.find(s) == ma.end()){
                ma[s] = inMap;
                si = inMap++;
            }else{
                si = ma[s];
            }
            edgeList.push_back(make_pair(w, make_pair(ri, si)));
        }
        sort(edgeList.begin(), edgeList.end());
        if(num++ != 0)
            cout << endl;
        cout << MST() << endl;;
    }
    return 0;
}
