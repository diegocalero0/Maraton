#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;
    int a, b, c, d, posa, posb, posc, posd;
    a = 0; b = 0; c = 0; d = 0;
    int arr[4], arr2[4];
    for(int i = 0; i < 4; i++)
        arr2[i] = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '!'){
            arr2[i % 4]++;
        }else{
            if(s[i] == 'R'){
                posa = i % 4;
            }
            if(s[i] == 'B'){
                posb = i % 4;
            }
            if(s[i] == 'Y'){
                posc = i % 4;
            }
            if(s[i] == 'G'){
                posd = i % 4;
            }
        }
    }
    arr[0] = arr2[posa];
    arr[1] = arr2[posb];
    arr[2] = arr2[posc];
    arr[3] = arr2[posd];

    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl;
    return 0;
}
