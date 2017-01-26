#include<bits/stdc++.h>
using namespace std;

int main(){
    int ex, p[6], result, res;
    while(1){
        ex = 0;
        for(int i = 0; i < 6; i++){
            cin >> p[i];
            ex += p[i];
        }
        if(!ex)
            break;
        result = p[5];

        if(p[4] != 0){
            result += p[4];
            p[0] -= p[4] * 11;
        }
        if(p[3] != 0){
            result += p[3];
            p[1] -= p[3] * 5;
        }
        if(p[2] != 0){
            result += p[2] / 4;
            if(p[2] % 4 == 3){
                p[1] -= 1;
                p[0] -= 5;
                result++;
            }else if(p[2] % 4 == 2){
                p[1] -= 3;
                p[0] -= 6;
                result++;
            }else if(p[2] % 4 == 1){
                p[1] -= 5;
                p[0] -= 7;
                result++;
            }
        }
        if(p[1] > 0){
           result += p[1] / 9;
           int mod = p[1] % 9;
           if(mod != 0){
                for(int i = 0; i < 36 - (mod * 4) && p[0] > 0; i++){
                    p[0]--;
                }
                result++;
           }
        }else{
            p[0] -= (-p[1] * 4);
        }
        if(p[0] > 0){
            result += p[0] / 36;
            if(p[0] % 36 > 0)
                result++;
        }
        cout << result << "\n";
    }

    return 0;
}
