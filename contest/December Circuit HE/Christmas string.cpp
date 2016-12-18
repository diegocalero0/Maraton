#include<bits/stdc++.h>
using namespace std;

int main(){

    string s, t, ws[3000];
    int n, cont, res, dif[3000], cant[3000];

    cin >> s >> n;
    res = 0;
    cont = n;

    for(int i = 0; i < n ;i++){
        dif[i] = -2;
        cin >> ws[i];
    }

    for(int i = 0; i < s.length(); i++){
        cant[i] = 0;
        if(s[i] != '*')
            for(int j = 0; j < n; j++){
                if(ws[j][i] != s[i]){
                    if(dif[j] == -2){
                        cont--;
                        dif[j] = i;
                        cant[i]++;
                    }else if(dif[j] != -1){
                        cant[dif[j]]--;
                        dif[j] = -1;
                    }
                }
            }
    }

    res = cant[0];
    for(int i = 1; i < s.length(); i++){
        if(cant[i] > res)
            res = cant[i];
    }
    cout << res + cont << endl;
    return 0;
}
