#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector< vector<ii> > vvi;

vector< pair<int, ii> > edgeList;
int n;

int parent[1000000], rankk[1000000];

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
        if(rankk[xroot] == rankk[yroot]){
            rankk[yroot]++;
        }
    }
}

bool same_set(int x, int y){
    if(find_(x) == find_(y))
        return true;
    return false;
}

long mst(){
    long result = 0;
    for(int i = 0; i < edgeList.size(); i++){
        pair<int, ii> aux = edgeList[i];
        if(!same_set(aux.second.first, aux.second.second)){
            result += aux.first;
            union_(aux.second.first, aux.second.second);
        }
    }
    return result;
}

int main(){
    int s, t, w, k, case_ = 0;
    long ans1, ans2;
    while(cin >> n){
        make_set(n);
        ans1 = 0;
        edgeList.clear();
        for(int i = 0; i < n - 1; i++){
            cin >> s >> t >> w;
            ans1 += w;
        }
        cin >> k;
        while(k--){
            cin >> s >> t >> w;
            s--;
            t--;
            edgeList.push_back(make_pair(w, make_pair(s, t)));
        }
        cin >> k;
        while(k--){
            cin >> s >> t >> w;
            s--;
            t--;
            edgeList.push_back(make_pair(w, make_pair(s, t)));
        }
        sort(edgeList.begin(), edgeList.end());
        ans2 = mst();
        if(case_++ != 0)
            cout << endl;
        cout << ans1 << endl << ans2 << endl;
    }
    return 0;
}
