#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
vector< pair<double, ii> > edgeList;
vector<ii> points(750);
int parent[750], rankk[750];

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

    if(rankk[xroot] > rankk[yroot])
        parent[yroot] = xroot;
    else{
        parent[xroot] = yroot;
        if(rankk[xroot] == rankk[yroot])
            rankk[yroot]++;
    }
}

bool same_set(int x, int y){
    return find_(x) == find_(y);
}

double dist(int x1, int y1, int x2, int y2){
    return sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
}

void calcW(int u){
    for(int i = u - 1; i >= 0; i--){
        double w = dist(points[u].first, points[u].second, points[i].first, points[i].second);
        edgeList.push_back(make_pair(w, ii(i, u)));
    }
}

void kruskal(){
    priority_queue<ii, deque<ii>, greater<ii> > res;
    for(int i = 0; i < edgeList.size(); i++){
        if(!same_set(edgeList[i].second.first, edgeList[i].second.second)){
            res.push(ii(edgeList[i].second.first + 1, edgeList[i].second.second + 1));
            union_(edgeList[i].second.first, edgeList[i].second.second);
        }

    }
    if(!res.empty())
        while(!res.empty()){
            cout << res.top().first << " " << res.top().second << endl;
            res.pop();
        }
    else
        cout << "No new highways need" << endl;
}

int main(){

    int k, n, x, y, m;
    cin >> k;

    for(int j = 0; j < k; j++){
        edgeList.clear();
        cin >> n;
        make_set(n);
        cin >> x >> y;
        points[0] = ii(x, y);
        for(int i = 1; i < n; i++){
            cin >> x >> y;
            points[i] = ii(x, y);
            calcW(i);
        }

        cin >> m;
        while(m--){
            cin >> x >> y;
            x--;
            y--;
            union_(x, y);
        }

        sort(edgeList.begin(), edgeList.end());
        if(j != 0)
            cout << endl;
        kruskal();

    }

    return 0;
}
