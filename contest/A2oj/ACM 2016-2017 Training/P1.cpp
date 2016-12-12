#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, pi;
    cin >> n;
    int sol[n];

    for(int i = 0; i < n; i++){
        cin >> pi;
        sol[pi - 1] = i + 1;
    }

    for(int i = 0; i < n; i++){
        if(i == 0)
            cout << sol[i];
        else
            cout << " " << sol[i];
    }
    cout << endl;
    return 0;
}
