#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, word;
    char first;
    bool flag;
    char a = 's';
    while(getline(cin, s) && s != "*"){
        flag = true;
        stringstream ss(s);
        ss >> word;
        first = word[0];
        while(ss >> word){
            if(word[0] != first && word[0] + 32 != first && word[0] - 32 != first){
                flag = !flag;
                break;
            }
        }
        if(flag)
            cout << "Y\n";
        else
            cout << "N\n";
    }


    return 0;
}
