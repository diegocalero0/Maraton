#include<bits/stdc++.h>
using namespace std;

int w, h;

bool bounds(int x, int y){
    if(x >= 0 && x <= w && y >= 0 && y <= h)
        return true;
    return false;
}

int main(){
    int x, y;
    char o;
    string line;
    cin >> w >> h;
    bool out;
    int m[w + 1][h + 1];
    for(int i = 0; i <= w; i++)
        for(int j = 0; j <= h; j++)
            m[i][j] = 0;

    while(cin >> x >> y){
        cin >> o >> line;
        out = false;
        for(int i = 0; i < line.length(); i++){
            if(line[i] == 'L'){
                if(o == 'N')
                    o = 'W';
                else if(o == 'W')
                    o = 'S';
                else if(o == 'S')
                    o = 'E';
                else if(o == 'E')
                    o = 'N';
            }else if(line[i] == 'R'){
                if(o == 'N')
                    o = 'E';
                else if(o == 'E')
                    o = 'S';
                else if(o == 'S')
                    o = 'W';
                else if(o == 'W')
                    o = 'N';
            }else if(line[i] == 'F'){
                if(o == 'N'){
                    y++;
                    if(!bounds(x, y)){
                        y--;
                        if(m[x][y] == 0){
                            out = true;
                            break;
                        }
                    }
                }
                if(o == 'W'){
                    x--;
                    if(!bounds(x, y)){
                        x++;
                        if(m[x][y] == 0){
                            out = true;
                            break;
                        }
                    }
                }
                if(o == 'S'){
                    y--;
                    if(!bounds(x, y)){
                        y++;
                        if(m[x][y] == 0){
                            out = true;
                            break;
                        }
                    }
                }
                if(o == 'E'){
                    x++;
                    if(!bounds(x, y)){
                        x--;
                        if(m[x][y] == 0){
                            out = true;
                            break;
                        }
                    }
                }

            }
        }

        cout << x << " " << y << " " << o;

        if(out){
            m[x][y] = 1;
            cout << " LOST";
        }

        cout << endl;

    }

    return 0;
}
