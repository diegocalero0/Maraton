#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double d, vf, vg, hyp;
    while(cin >> d >> vf >> vg){
        hyp = sqrt(d * d + 12 * 12);
        if(12 / vf >= hyp / vg)
            cout << "S\n";
        else
            cout << "N\n";
    }

    return 0;
}
