#include<bits/stdc++.h>
using namespace std;

string maze[30];
string line;

void floodfill(int x, int y){
    if(maze[x][y] == ' ' || maze[x][y] == '*'){
        maze[x][y] = '#';
        floodfill(x + 1, y);
        floodfill(x - 1, y);
        floodfill(x, y + 1);
        floodfill(x, y - 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, pos;
    cin >> t;
    getline(cin, line);
    int x, y;
    while(t--){
        pos = 0;
        while(getline(cin, line) && line[0] != '_')
            maze[pos++] = line;
        for(int i = 0; i < pos; i++)
            for(int j = 0; j < maze[i].length(); j++)
                if(maze[i][j] == '*'){
                    x = i;
                    y = j;
                    break;
                }
        floodfill(x, y);
        for(int i = 0; i < pos; i++){
            for(int j = 0; j < maze[i].length(); j++)
                cout << maze[i][j];
            cout << "\n";
        }
        cout << line << "\n";
    }

    return 0;

}
