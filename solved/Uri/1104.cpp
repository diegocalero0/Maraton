#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, n, ac[100000], bc[100000], temp;
    int resa;
    int resb;
    while(cin >> a >> b && a + b){
        resa = 0;
        resb = 0;
        n = 0;
        for(int i = 0; i < 100000; i++){
            ac[i] = -1;
            bc[i] = -1;
        }
        for(int i = 0; i < a; i++){
            cin >> temp;
            n = max(n, temp);
            ac[--temp] = 1;
        }

        for(int i = 0; i < b; i++){
            cin >> temp;
            n = max(n, temp);
            bc[--temp] = 1;
        }
        for(int i = 0; i < n; i++){
            if(ac[i] == 1 && bc[i] == -1)
                resa++;
            if(ac[i] == -1 && bc[i] == 1)
                resb++;
        }
        cout << min(resa, resb) << "\n";
    }

    return 0;
}
