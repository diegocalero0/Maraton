#include<bits/stdc++.h>

using namespace std;

int main(){

    int l;
    int i;
    string num0[2] = {".*","**"};
    string num1[2] = {"*.",".."};
    string num2[2] = {"*.","*."};
    string num3[2] = {"**",".."};
    string num4[2] = {"**",".*"};
    string num5[2] = {"*.",".*"};
    string num6[2] = {"**","*."};
    string num7[2] = {"**","**"};
    string num8[2] = {"*.","**"};
    string num9[2] = {".*","*."};

    char num;
    char opcion;
    string numero;
    string b1;
    string b2;
    string b3;
    string espacio="";
    string auxiliar="";
    while(cin>>l&&l!=0){
        cin>>opcion;
        espacio="";
        switch(opcion){
        case 'S':
            b1="";
            b2="";
            b3="";
            cin>>numero;
            for(i=0;i<l;i++){
                b3+=espacio+"..";
                switch(numero.at(i)-48){
                case 0:
                    b1+=espacio+num0[0];
                    b2+=espacio+num0[1];
                    espacio=" ";
                    break;
                case 1:
                    b1+=espacio+num1[0];
                    b2+=espacio+num1[1];
                    espacio=" ";
                    break;
                case 2:
                    b1+=espacio+num2[0];
                    b2+=espacio+num2[1];
                    espacio=" ";
                    break;
                case 3:
                    b1+=espacio+num3[0];
                    b2+=espacio+num3[1];
                    espacio=" ";
                    break;
                case 4:
                    b1+=espacio+num4[0];
                    b2+=espacio+num4[1];
                    espacio=" ";
                    break;
                case 5:
                    b1+=espacio+num5[0];
                    b2+=espacio+num5[1];
                    espacio=" ";
                    break;
                case 6:
                    b1+=espacio+num6[0];
                    b2+=espacio+num6[1];
                    espacio=" ";
                    break;
                case 7:
                    b1+=espacio+num7[0];
                    b2+=espacio+num7[1];
                    espacio=" ";
                    break;
                case 8:
                    b1+=espacio+num8[0];
                    b2+=espacio+num8[1];
                    espacio=" ";
                    break;
                case 9:
                    b1+=espacio+num9[0];
                    b2+=espacio+num9[1];
                    espacio=" ";
                    break;
                }
            }
            cout<<b1<<endl;
            cout<<b2<<endl;
            cout<<b3<<endl;
            break;
        case 'B':
            string br1[l+1];
            string br2[l+1];
            for(i=0;i<l;i++){
                cin>>auxiliar;
                br1[i]=auxiliar;
            }
            for(i=0;i<l;i++){
                cin>>auxiliar;
                br2[i]=auxiliar;
            }
            for(i=0;i<l;i++){
                cin>>auxiliar;
            }
            numero="";
            for(i=0;i<l;i++){
                if(br1[i]==num0[0]&&br2[i]==num0[1]){
                    numero+="0";
                }
                if(br1[i]==num1[0]&&br2[i]==num1[1]){
                    numero+="1";
                }
                if(br1[i]==num2[0]&&br2[i]==num2[1]){
                    numero+="2";
                }
                if(br1[i]==num3[0]&&br2[i]==num3[1]){
                    numero+="3";
                }
                if(br1[i]==num4[0]&&br2[i]==num4[1]){
                    numero+="4";
                }
                if(br1[i]==num5[0]&&br2[i]==num5[1]){
                    numero+="5";
                }
                if(br1[i]==num6[0]&&br2[i]==num6[1]){
                    numero+="6";
                }
                if(br1[i]==num7[0]&&br2[i]==num7[1]){
                    numero+="7";
                }
                if(br1[i]==num8[0]&&br2[i]==num8[1]){
                    numero+="8";
                }
                if(br1[i]==num9[0]&&br2[i]==num9[1]){
                    numero+="9";
                }
            }
            cout<<numero<<endl;
            break;
        }

    }

}
