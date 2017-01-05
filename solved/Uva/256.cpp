#include<bits/stdc++.h>
using namespace std;

vector< vector<string> > sol(4);

void calculate(){
    string s(2, '*');
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if((i + j) * (i + j) == i * 10 + j){
                s[0] = i + 48;
                s[1] = j + 48;
                sol[0].push_back(s);
            }
        }
    }
    string ss(4, '*');
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if((i + j) * (i + j) == i * 100 + j){
                ss[0] = i / 10 + 48;
                ss[1] = i % 10 + 48;
                ss[2] = j / 10 + 48;
                ss[3] = j % 10 + 48;
                sol[1].push_back(ss);
            }
        }
    }

    string sss(6, '*');
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            if((i + j) * (i + j) == i * 1000 + j){
                sss[0] = i / 100 + 48;
                sss[1] = i % 100 / 10 + 48;
                sss[2] = i % 10 + 48;
                sss[3] = j / 100 + 48;
                sss[4] = j % 100 / 10 + 48;
                sss[5] = j % 10 + 48;
                sol[2].push_back(sss);
            }
        }
    }

    string ssss(8, '*');
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < 10000; j++){
            if((i + j) * (i + j) == i * 10000 + j){
                ssss[0] = i / 1000 + 48;
                ssss[1] = i % 1000 / 100 + 48;
                ssss[2] = ((i % 1000) % 100) / 10 + 48;
                ssss[3] = i % 10 + 48;
                ssss[4] = j / 1000 + 48;
                ssss[5] = j % 1000 / 100 + 48;
                ssss[6] = ((j % 1000) % 100) / 10 + 48;
                ssss[7] = j % 10 + 48;

                sol[3].push_back(ssss);
            }
        }
    }

}

int main(){

    int d;
    calculate();
    while(cin >> d){
        if(d == 2)
            for(int i = 0; i < sol[0].size(); i++)
                cout << sol[0][i] << "\n";
        if(d == 4)
            for(int i = 0; i < sol[1].size(); i++)
                cout << sol[1][i] << "\n";
        if(d == 6)
            for(int i = 0; i < sol[2].size(); i++)
                cout << sol[2][i] << "\n";
        if(d == 8)
            for(int i = 0; i < sol[3].size(); i++)
                cout << sol[3][i] << "\n";

    }

    return 0;
}
