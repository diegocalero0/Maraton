#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, arr[50];
    while(cin >> n){
        int cost;
        cin >> cost;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int aux1, aux2;
        aux1 = aux2 = 0;
        for(int i = 0; i < n; i++){
            aux1 = max(0, aux1 + arr[i] - cost);
            if(aux1 > aux2){
                aux2 = aux1;
            }
        }
        cout << aux2 << "\n";
    }

    return 0;
}
