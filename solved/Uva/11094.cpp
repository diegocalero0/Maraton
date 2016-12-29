#include<bits/stdc++.h>
using namespace std;

int h, w;
string g[20];
int curr;
int res;
void floodfill(char c, int i, int j){
    if(i >= 0 && i < h && j >= 0 && j < w && g[i][j] == c){
            curr++;
            g[i][j] = '.';
            floodfill(c, i + 1, j);
            floodfill(c, i - 1, j);
            floodfill(c, i, (j + 1) % w);
            floodfill(c, i, (j + w - 1) % w);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    int y, x;
    while(cin >> h >> w){
        res = 0;
        for(int i = 0; i < h; i++)
            cin >> g[i];
        cin >> y >> x;
        c = g[y][x];
        floodfill(c, y, x);
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(g[i][j] == c){
                    curr = 0;
                    floodfill(c, i, j);
                    res = max(res, curr);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
