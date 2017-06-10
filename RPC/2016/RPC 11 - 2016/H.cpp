#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string b){
    if(b.length()==0||b.length()==1){
        return true;
    }else{
        if(b.at(0)==b.at(b.length()-1))
            return isPalindrome(b.substr(1,b.length()-2));
        else
            return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    int i;
    string b;
    while(cin>>a){
        b="";
        for(i=0;i<a.length();i++){
            if(a.at(i)=='a'||a.at(i)=='e'||a.at(i)=='i'||a.at(i)=='o'||a.at(i)=='u'){
                b+=a.at(i);
            }
        }

        if(isPalindrome(b))
            cout<<"S\n";
        else
            cout<<"N\n";
    }

    return 0;
}
