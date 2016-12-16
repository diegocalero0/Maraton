#include<bits/stdc++.h>
using namespace std;

struct node{int x; int y; int c;};

vector<int> g[10][10];
int visited[10][10];
int movs[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int n;

bool isValid(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < n && visited[y][x] == 0)
        return true;
    return false;
}

void bfs(node src, node dest){
    queue<node> c;
    c.push(src);
    visited[src.y][src.x] = 1;

    while(!c.empty()){
        node curr = c.front(); c.pop();
        if(curr.x == dest.x && curr.y == dest.y){
            cout << curr.c << endl;
            return;
        }

        for(int i = 0; i < 4; i++){
            int x = curr.x + movs[i][0];
            int y = curr.y + movs[i][1];
            if(g[curr.y][curr.x][i] == 1 && isValid(x, y)){
                visited[y][x] = 1;
                node aux = {x, y, curr.c + 1};
                c.push(aux);
            }
        }
    }
    cout << "Impossible" << endl;
}

int main(){
    int a, b, c, d, p;
    while(cin >> n && n){
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                g[i][j].clear();
                cin >> a >> b >> c >> d;
                g[i][j].push_back(a);
                g[i][j].push_back(b);
                g[i][j].push_back(c);
                g[i][j].push_back(d);
            }
        }
        cin >> p;
        while(p--){
            memset(visited, 0, sizeof visited);
            cin >> a >> b >> c >> d;
            node src = {a, b, 0};
            node dest = {c, d, 0};
            bfs(src, dest);
        }
        cout << endl;
    }
    return 0;
}
