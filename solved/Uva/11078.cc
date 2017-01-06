#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c, n, arr[100000], max_v, aux;
    cin >> c;

    while(c--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        max_v = -10000000;
        aux = arr[0];
        for(int i = 0; i < n - 1; i++){
            max_v = max(max_v, arr[i] - arr[i + 1]);
            max_v = max(max_v, aux - arr[i + 1]);
            aux = max(aux, arr[i + 1]);
        }
        cout << max_v << "\n";
    }

    return 0;
}
