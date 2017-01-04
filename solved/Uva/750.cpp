#include<bits/stdc++.h>
using namespace std;

int a, b, pos[8], numSol;

bool isValid(int r, int c){
    for(int i = 0; i < c; i++){
        if(pos[i] == r || abs(pos[i] - r) == abs(i - c))
            return false;
    }
    return true;
}

void sol(int c){
    if(c == 8 && pos[b] == a){
        if(numSol < 10)
            cout << " " << numSol++ << "     ";
        else
           cout << numSol++ << "     ";
        for(int i = 0; i < 8; i++){
            cout << " " << pos[i] + 1;
        }
        cout << "\n";
    }
    for(int i = 0; i < 8; i++){
        if(isValid(i, c)){
            pos[c] = i; sol(c + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> a >> b; a--; b--;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        numSol = 1;
        sol(0);
        if(tc)
            cout << "\n";
    }

    return 0;
}
