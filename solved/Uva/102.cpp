#include<bits/stdc++.h>
using namespace std;

#define INF 2147483649

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, string> m;
    m[0] = "B";
    m[1] = "G";
    m[2] = "C";
    string ord;
    long aux;
    while(cin >> aux){
        ord = "ZZZ";
        int sol[3] = {0, 1, 2};
        long long res = INF;
        long long b1, b2, b3, b[9];
        b1 = 0, b2 = 0, b3 = 0;
        b[0] = aux;
        b1 += aux;
        for(int i = 1; i < 3; i++){
            cin >> b[i];
            b1 += b[i];
        }
        for(int i = 3; i < 6; i++){
            cin >> b[i];
            b2 += b[i];
        }
        for(int i = 6; i < 9; i++){
            cin >> b[i];
            b3 += b[i];
        }
        do{
            long long temp = b1 - b[sol[0]] + b2 - b[sol[1] + 3] + b3 - b[sol[2] + 6];
            string stemp;
            if(temp <= res){
                stemp = m[sol[0]] + m[sol[1]] + m[sol[2]];
                if(temp == res)
                    ord = min(ord, stemp);
                else
                    ord = stemp;
                res = temp;
            }
        }while(next_permutation(sol, sol + 3));
        cout << ord << " " << res << "\n";
    }

    return 0;
}
