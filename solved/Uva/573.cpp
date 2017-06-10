#include<bits/stdc++.h>
using namespace std;

int main(){

    double h, d, n, f;
    double pos;
    double dia;
    double reduccion;
    while(cin >> h >> d >> n >> f && ( h && d && n && f )){
        pos = 0;
        dia = 0;
        reduccion = d * f / 100l;
        while(pos >= 0 && pos <= h){
            dia++;
            pos += d;
            if(pos > h) break;
            pos -= n;
            if(pos < 0) break;
            if(d - reduccion >= 0)
                d -= reduccion;
        }
        if(pos >= 0){
            cout << "success on day " << dia << endl;
        }else{
            cout << "failure on day " << dia << endl;
        }
    }

    return 0;
}
