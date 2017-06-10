#include<bits/stdc++.h>
using namespace std;

int n;
long long points[50], prizes[5], res[5];
long long sum, cont;

void solve(int u){
    for(int i = u; i >= 0; i--){
        if(prizes[i] <= sum){
            cont = sum / prizes[i];
            sum -= prizes[i] * cont;
            res[i] += cont;
        }
    }
}

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> points[i];
    }

    for(int i = 0; i < 5; i++){
        cin >> prizes[i];
        res[i] = 0;
    }
    sum = 0;
    for(int i = 0; i < n; i++){
        sum += points[i];
        if(sum >= prizes[0])
            solve(4);
    }
    for(int i = 0; i < 5; i++){
        if(i != 0)
            cout << " ";
        cout << res[i];
    }
    cout << endl << sum << endl;
    return 0;
}
