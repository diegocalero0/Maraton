#include<bits/stdc++.h>
using namespace std;

int main(){

    int inter;
    int grei;
    int f;
    int GanInter=0;
    int GanGrei=0;
    int empatados=0;
    int n=0;
    while(true){
        cout<<"Novo grenal (1-sim 2-nao)"<<endl;
        n++;
        cin>>inter;
        cin>>grei;
        if(inter>grei){
            GanInter++;
        }else if(grei>inter){
            GanGrei++;
        }else{
            empatados++;
        }
        cin>>f;
        if(f!=1){
            break;
        }
    }
    int aux=n;
    cout<<aux<< " grenais"<<endl;
    cout<<"Inter:"<<GanInter<<endl;
    cout<<"Gremio:"<<GanGrei<<endl;
    cout<<"Empates:"<<empatados<<endl;
    if(GanGrei>GanInter){
        cout<<"Gremio venceu mais"<<endl;
    }else if(GanInter>GanGrei){
        cout<<"Inter venceu mais"<<endl;
    }else{
        cout<<"Nao houve vencedor"<<endl;
    }


    return 0;
}