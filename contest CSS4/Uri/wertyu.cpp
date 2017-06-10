#include<bits/stdc++.h>
using namespace std;

int main(){

    map<char,char> mapa;
    mapa['W']='Q';
    mapa['E']='W';
    mapa['R']='E';
    mapa['T']='R';
    mapa['Y']='T';
    mapa['U']='Y';
    mapa['I']='U';
    mapa['O']='I';
    mapa['P']='O';
    mapa['[']='P';
    mapa[']']='[';
    mapa['\92']=']';

    mapa['S']='A';
    mapa['D']='S';
    mapa['F']='D';
    mapa['G']='F';
    mapa['H']='G';
    mapa['J']='H';
    mapa['K']='J';
    mapa['L']='K';
    mapa[';']='L';
    mapa['\39']=';';

    mapa['X']='Z';
    mapa['C']='X';
    mapa['V']='C';
    mapa['B']='V';
    mapa['N']='B';
    mapa['M']='N';
    mapa[',']='M';
    mapa['.']=',';
    mapa['/']='.';

    mapa[' ']=' ';

    mapa['1']='`';
    mapa['2']='1';
    mapa['3']='2';
    mapa['4']='3';
    mapa['5']='4';
    mapa['6']='5';
    mapa['7']='6';
    mapa['8']='7';
    mapa['9']='8';
    mapa['0']='9';

    mapa['-']='0';
    mapa['=']='-';

    char a[1000000];

    int i;
    string res="";
    string coma="'";
    string backslash="\\";
    while(cin.getline(a,1000000)){
        res="";
    for(i=0;a[i]!='\0';i++){
        if(a[i]==coma.at(0))
            res+=';';
        else if(a[i]==backslash.at(0))
            res+=']';
        else
            res+=mapa[a[i]];
    }
    cout<<res<<endl;
    }

    return 0;
}
