#include<bits/stdc++.h>
using namespace std;

char teams[]="RGB";
bool verificar(char gol,char per){
    int i;
    for(i=0;i<3;i++){
        if(teams[i]==gol){
            if((i+1)<=2){
                    if(teams[i+1]==per){
                        return false;
                    }else{
                        return true;
                    }
            }else{
                    if(teams[0]==per){
                        return false;
                    }else{
                        return true;
                    }
            }
        }
    }
}
int main(){
    int red=0;
    int green=0;
    int blue=0;

    int casos;
    char gol;
    char per;
    int n;
    cin>>casos;
    while(casos--){
        green=0;
        red=0;
        blue=0;

        cin>>n;
        while(n--){

        cin>>gol;
        cin>>per;
        if(verificar(gol,per)){
            switch(gol){
        case 'R':
            red++;
            break;
        case 'G':
            green++;
            break;
        case 'B':
            blue++;
            break;
        }
        }else{
            switch(gol){
        case 'R':
            red+=2;
            break;
        case 'G':
            green+=2;
            break;
        case 'B':
            blue+=2;
            break;
        }
        }
        }



        if(red>blue&&red>green){
            cout<<"red"<<endl;
        }else if(green>red&&green>blue){
            cout<<"green"<<endl;
        }else if(blue>red&&blue>green){
            cout<<"blue"<<endl;
        }else if(red==blue&&blue==green){
            cout<<"trempate"<<endl;
        }else if(red==blue||red==green||green==blue){
            cout<<"empate"<<endl;
        }
    }



    return 0;
}