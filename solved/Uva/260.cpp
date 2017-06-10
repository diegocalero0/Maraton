#include<bits/stdc++.h>
using namespace std;

string game[200];
int n;

bool white;


void win(int i, int j, char p){

    if(p == 'w' && j == n - 1 && game[i][j] == 'w'){
        white = true;
        return;
    }

    if(i < 0 ||j < 0 || j == n || i == n || game[i][j] != p){
        return;
    }
    game[i][j] = 'W';
    win(i - 1, j - 1, p);
    win(i - 1, j, p);
    win(i, j - 1, p);
    win(i, j + 1, p);
    win(i + 1, j, p);
    win(i + 1, j + 1, p);

}

int main(){

    int c = 0;
    while(cin >> n && n){

        white = false;

        for(int i = 0; i < n; i++){
            cin >> game[i];
        }

        for(int i = 0; i < n; i++){
            if(game[i][0] == 'w')
                win(i, 0, 'w');
        }

        if(white)
            cout << ++c << " " << "W" << endl;
        else
            cout << ++c << " " << "B" << endl;

    }

    return 0;
}
