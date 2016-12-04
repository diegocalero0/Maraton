#include<bits/stdc++.h>
using namespace std;

int main(){
    int i;
    char arreglo[51];
    bool aux=true;

    while(cin.getline(arreglo,51)){
        aux=true;
        for(i=0;arreglo[i]!='\0';i++){
                if(arreglo[i]==' '){
                    cout<<' ';
                }
            else if(aux){
                if(arreglo[i]>=65&&arreglo[i]<=90){
                    cout<<arreglo[i];
                    aux=false;
                }else{
                    cout<<(char)(arreglo[i]-32);
                    aux=false;
                }
            }else{
                if((arreglo[i]>=97&&arreglo[i]<=122)||arreglo[i]==' '){
                    cout<<arreglo[i];
                    aux=true;
                }else{
                    cout<<(char)(arreglo[i]+32);
                    aux=true;
                }
            }
            if(arreglo[i+1]=='\0'){
                cout<<endl;
            }
        }

    }


    return 0;
}