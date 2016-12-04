#include <bits/stdc++.h>

using namespace std;
int cont=-1;
int suma=0;
int fibonacci(int a){
    cont++;
    if(a==1){
        suma++;
    }else if(a!=0){
        fibonacci(a-1);
        fibonacci(a-2);
    }
}

int main(){
int casos;
int a;
cin>>casos;
while(casos--){
        cont=-1;
        suma=0;
cin>>a;
fibonacci(a);
cout<<"fib("<<a<<")"<<" = "<< cont <<" calls = "<<suma<<endl;
}
return 0;
}