#include<bits/stdc++.h>
using namespace std;

int r, c, res, i;
string lakes[100];

void floodfill(int x, int y){
    if(x >= 0 && x < c && y >= 0 && y < r && lakes[y][x] == '0'){
        lakes[y][x] = 1;
        res++;
        floodfill(x + 1, y);
        floodfill(x - 1, y);
        floodfill(x, y + 1);
        floodfill(x, y - 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, x, y;
    string line;
    cin >> t;

    string jump = "";
    while(t--){
        res = 0;
        r = 0;
        cin >> y >> x;
        y--;
        x--;
        getline(cin, line);
        while(getline(cin, line) && line != ""){
            lakes[r++] = line;
        }
        c = lakes[0].length();
        floodfill(x, y);
        cout << jump;
        jump = "\n";
        cout << res << "\n";
    }

    return 0;
}
