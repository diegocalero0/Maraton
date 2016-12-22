#include<bits/stdc++.h>
using namespace std;

typedef pair<double, double> ii;
typedef vector< pair<double, ii> > viii;

viii edgeList;
vector<ii> points(100);
int parent[100], rankk[100], n;

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

int union_(int x, int y){
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
    return find_(x) == find_(y);
}

double dist(double x1, double y1, double x2, double y2){
    return sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double kruskal(){
    double res = 0;
    for(int i = 0; i < edgeList.size(); i++){
        if(!same_set(edgeList[i].second.first, edgeList[i].second.second)){
            res += edgeList[i].first;
            union_(edgeList[i].second.first, edgeList[i].second.second);
        }
    }
    return res;
}

void calc(int u){
    ii v;
    double w;
    for(int i = u - 1; i >= 0; i--){
        v = points[i];
        w = dist(v.first, v.second, points[u].first, points[u].second);
        edgeList.push_back(make_pair(w, ii(u, i) ));
    }
}

int main(){

    int t;
    double x, y;
    cin >> t;

    for(int k = 0; k < t; k++){
        edgeList.clear();
        cin >> n;
        make_set(n);
        cin >> x >> y;
        points[0] = ii(x, y);
        for(int i = 1; i < n; i++){
            cin >> x >> y;
            points[i] = ii(x, y);
            calc(i);
        }
        sort(edgeList.begin(), edgeList.end());
        if(k != 0)
            cout << endl;
        double res = kruskal();
        printf("%.2f\n",res);
    }

    return 0;
}
