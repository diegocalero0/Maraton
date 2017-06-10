#include<bits/stdc++.h>

using namespace std;

int main(){

    bool jack;
    bool marck;
    int n;
    int aux;
    cin>>n;
    int arreglo[10];
    while(n--){
            jack=false;
            marck=false;
        for(int i=0;i<10;i++){
                cin>>aux;
            arreglo[i]=aux;
            if(arreglo[i]==17){
                jack=true;
            }else if(arreglo[i]==18){
                marck=true;
            }
        }

        for(int i=0;i<10;i++){
            if(i==0){
                cout<<arreglo[i];
            }else{
                cout<<" "<<arreglo[i];
            }
        }
        cout<<endl;
        if(jack&&marck){
                cout<<"both"<<endl;
        }else if(jack){
                cout<<"zack"<<endl;
        }else if(marck){
            cout<<"mack"<<endl;
        }else{
            cout<<"none"<<endl;
        }

    }


}
