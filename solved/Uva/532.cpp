#include<bits/stdc++.h>
using namespace std;

struct state
{
    int x;
    int y;
    int z;
    int c;
};
string m[30][30];
int l, r, c, movs[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

bool isValid(int x, int y, int z){
    if(x >= 0 && x < l && y >= 0 && y < r && z >= 0 && z < c && m[x][y][z] != '#'){
        if(m[x][y][z] != 'E')
            m[x][y][z] = '#';
        return true;
    }
    return false;
}

int bfs(state e){
    m[e.x][e.y][e.z] = '#';
    queue<state> q;
    q.push(e);

    while(!q.empty()){
        state curr = q.front();
        q.pop();
        int x = curr.x, y = curr.y, z = curr.z;
        if(m[x][y][z] == 'E')
            return curr.c;
        for(int i = 0; i < 6; i++){
            x += movs[i][0];
            y += movs[i][1];
            z += movs[i][2];
            if(isValid(x, y, z)){
                state temp = {x, y, z, curr.c + 1};
                q.push(temp);
            }
            x -= movs[i][0];
            y -= movs[i][1];
            z -= movs[i][2];
        }

    }
    return -1;
}

int main(){

    int x, y, z;

    while(cin >> l >> r >> c && l + r + c){
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                cin >> m[i][j];
                for(int k = 0; k < c; k++){
                    if(m[i][j][k] == 'S'){
                        x = i;
                        y = j;
                        z = k;
                    }
                }
            }
        }

        state e = {x, y, z, 0};

        int result = bfs(e);
        if(result == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << result << " minute(s).\n";
    }
    return 0;
}
