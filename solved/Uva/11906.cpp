#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int r, c, m, n, visited[100][100];
int movs[4][2] = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
int movs2[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int odd, even, cont;

bool check(int x, int y){
    if(x >= 0 && x < r && y >= 0 && y < c && visited[x][y] != -1){
        cont++;
        if(visited[x][y] == 0){
            visited[x][y] = 1;
            return true;
        }
    }
    return false;
}

void bfs(){
    queue<ii> q;
    q.push(ii(0, 0));
    visited[0][0] = 1;

    while(!q.empty()){
        cont = 0;
        ii curr = q.front(); q.pop();
        if(n != 0 && m != 0){
            for(int i = 0; i < 4; i++)
                if(check(curr.first + m * movs[i][0], curr.second + n * movs[i][1]))
                    q.push(ii(curr.first + m * movs[i][0], curr.second + n * movs[i][1]));
            if(n != m)
                for(int i = 0; i < 4; i++)
                    if(check(curr.first + n * movs[i][0], curr.second + m * movs[i][1]))
                        q.push(ii(curr.first + n * movs[i][0], curr.second + m * movs[i][1]));
        }else{
            n = max(n, m);
            m = 0;
            for(int i = 0; i < 4; i++)
                if(check(curr.first + n * movs2[i][0], curr.second + n * movs2[i][1]))
                    q.push(ii(curr.first + n * movs2[i][0], curr.second + n * movs2[i][1]));
        }
        if(cont % 2 == 0)
            even++;
        else
            odd++;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, ca = 1, a, b, w;
    cin >> t;

    while(t--){
        odd = 0;
        even = 0;
        memset(visited, 0, sizeof visited);
        cin >> r >> c >> m >> n >> w;
        while(w--){
            cin >> a >> b;
            visited[a][b] = -1;
        }

        bfs();
        cout << "Case " << ca++ << ": " << even << " " << odd << "\n";
    }
    return 0;
}
