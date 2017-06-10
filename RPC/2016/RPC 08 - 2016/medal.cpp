#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;

    int contUsa;
    int contRusia;
    int usa[3];
    int rusia[3];
    int aux;
    bool cont;
    bool colors;
    while(n--){
        cont=false;
        colors=false;
        contUsa=0;
        contRusia=0;
        for(int i=0;i<3;i++){
            cin>>aux;
            contUsa+=aux;
            usa[i]=aux;
        }

        for(int i=0;i<3;i++){
            cin>>aux;
            contRusia+=aux;
            rusia[i]=aux;
        }

        if(contUsa>contRusia){
            cont=true;
        }

        if(usa[0]>rusia[0]){
            colors=true;
        }else if(usa[1]>rusia[1]&&usa[0]==rusia[0]){
            colors=true;
        }else if(usa[2]>rusia[2]&&usa[1]==rusia[1]&&usa[0]==rusia[0]){
            colors=true;
        }

        for(int i=0;i<3;i++){
            if(i==0){
                cout<<usa[i];
            }else
            cout<<" "<<usa[i];
        }

        for(int i=0;i<3;i++){

            cout<<" "<<rusia[i];
        }

        cout<<endl;

        if(cont&&colors){
                cout<<"both"<<endl;
        }else if(cont){
                cout<<"count"<<endl;
        }else if(colors){
                cout<<"color"<<endl;
        }else{
                cout<<"none"<<endl;
        }

    }

}
