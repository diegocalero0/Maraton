#include<bits/stdc++.h>
using namespace std;

int mcd(int a,int b){
    if(a%b==0){
        return b;
    }else{
        return mcd(b,a%b);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int aux;
    int n1,n2,d1,d2;
    int casos;
    int num;
    int den;
    int maxcd;
    char a,b,c;
    cin>>casos;
    while(casos--){
        cin >> n1;
        cin >> a;
        cin >> d1;
        cin >> b;
        cin >> n2;
        cin >> c;
        cin >> d2;


        switch(b){
        case '+':
            num = n1*d2+n2*d1;
            den = d1*d2;
            break;
        case '-':
            num = n1*d2-n2*d1;
            den = d1*d2;
            break;
        case '*':
            num = n1*n2;
            den = d1*d2;
            break;
        case '/':
            num = n1*d2;
            den = d1*n2;
            break;
        }
        cout<<num<<"/"<<den<<" = ";
        if(num<den){
            maxcd=mcd(den,num);
        }else{
            maxcd=mcd(num,den);
        }

        if((num>=0&&den>=0)||(num<0&&den<0)){
            cout<<abs(num/maxcd)<<"/"<<abs(den/maxcd)<<"\n";
        }else{
            cout<<"-"<<abs(num/maxcd)<<"/"<<abs(den/maxcd)<<"\n";
        }

    }

    return 0;
}
