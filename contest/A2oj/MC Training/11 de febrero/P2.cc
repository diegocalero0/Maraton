#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, w[1000];
    string num[1000];
    int cum, newPos;
    string res;
    bool flag;
    while(cin >> n && n){
        cum = 0;
        res = "";
        flag = true;
        for(int i = 0; i < n; i++){
            cin >> num[i];
            cin >> w[i];
            cum += w[i];
        }
        if(cum != 0)
            cout << -1 << "\n";
        else{
            for(int i = 0; i < n; i++){
                while(w[i] != 0){
                   newPos = i + w[i];
                   if(newPos > i){
                        if(newPos + w[newPos] <= i){

                        }
                   }else{
                        if(newPos - w[newPos] <= i){

                        }
                   }
                   if(newPos < 0 || newPos >= n){
                       flag = false;
                       break;
                   }else{
                        if()
                        string temp = num[i];
                        num[i] = num[newPos];
                        num[newPos] = temp;

                        w[i] = w[newPos] + w[i];
                        w[newPos] = 0;
                   }
                }
                if(!flag)
                    break;
                if(i == 0)
                    res = res + num[i];
                else
                    res = res + " " + num[i];
            }
            if(!flag)
                cout << -1 << "\n";
            else
                cout << res << "\n";
        }
    }

    return 0;
}
