#include<bits/stdc++.h>
using namespace std;

string resolver(string a, string b){

    for(int i = 0; i < a.length(); i++){
        for(int j = 0; j < b.length(); j++){
            if(a[i] == b[j])
                return resolver(a.substr(i + 1, a.length() - i - 1), b.substr(0, j)) + resolver(a.substr(i + 1, a.length() - i - 1), b.substr(j + 1, b.length() - 1 - j))+a.at(i);
        }
    }
    return "";
}

int main(){

    string preord;
    string inord;

    while(cin >> preord >> inord){
        cout << resolver(preord, inord) << endl;
    }

    return 0;
}
