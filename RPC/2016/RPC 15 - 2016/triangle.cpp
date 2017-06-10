#include<bits/stdc++.h>

using namespace std;

int main(){

    int t1[3];
    int t2[3];

    cin >> t1[0];
    cin >> t1[1];
    cin >> t1[2];

    cin >> t2[0];
    cin >> t2[1];
    cin >> t2[2];
    bool bandera = false;
    for(int i = 0; i < 3; i++){
        bandera = false;
        for(int j = 0; j < 3; j++){
            if(t1[i] == t2[j]){
                bandera = true;
                break;
            }
        }

        if(!bandera){
            break;
        }

    }

    if(bandera){

        if(( t1[0]*t1[0] + t1[1]*t1[1] == t1[2]*t1[2] || t1[0]*t1[0] + t1[2]*t1[2] == t1[1]*t1[1] || t1[1]*t1[1] + t1[2]*t1[2] == t1[0]*t1[0] ) && ( t2[0]*t2[0] + t2[1]*t2[1] == t2[2]*t2[2] || t2[0]*t2[0] + t2[2]*t2[2] == t2[1]*t2[1] || t2[1]*t2[1] + t2[2]*t2[2] == t2[0]*t2[0] ) ){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }else{
        cout << "NO" << endl;
    }

    return 0;
}
