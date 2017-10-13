#include<bits/stdc++.h>

using namespace std;

vector<int> sec;
int matrix[1005][20];
int n;


int procede(int k){
    int j;
    for(int i = 0; i < n; i++){
        j = (i + 1)%n;
        matrix[k][i] = abs(matrix[k - 1][i] - matrix[k - 1][j]);     
    }

    bool zero = true;
    for(int i = 0; i < n; i++){
        if(matrix[k][i] != 0){
            zero = false;
            break;
        }
    }

    if(zero)
        return 2;
    return 0;

}

int top;

int main(){
    int t;
    cin >> t;
    while(t--){
        top = 1000;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> matrix[0][i];
        }
        
        int aux = 0;
        for(int i = 1; i <= top; i++){
            int o = procede(i);
            if(o == 2){
                cout << "ZERO" << endl;
                aux = 1;
                break;
            }
        }
        if(!aux)
            cout << "LOOP" << endl;
    }

    return 0;
}
