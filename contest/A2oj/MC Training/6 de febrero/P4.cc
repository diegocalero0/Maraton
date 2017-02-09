#include<bits/stdc++.h>
using namespace std;
bitset<25000> bset;

void calcFib(){
    bset[1] = 1;
    bset[2] = 1;
    int f1 = 1, f2 = 2, temp;
    while(f1 + f2 < 25000){
        bset[f1 + f2] = 1;
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
}

int main(){
    int n;
    int x, temp;
    int res;
    cin >> n;
    calcFib();
    while(n--){
        cin >> x;
        temp = x;
        res = 0;
        int i;
        for(i = x; x > 0; i--){
            if(i <= x && bset[i] == 1){
                x -= i;
                i--;
                while(i >= 0 && !bset[i]){i--;}
                res += i;
                if(i < 0){
                    x = temp;
                    temp--;
                    i = x;
                    res = 0;
                }
                i++;
            }
        }
        cout << res << "\n";
    }

    return 0;
}
