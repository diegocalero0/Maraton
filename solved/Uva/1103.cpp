#include<bits/stdc++.h>
using namespace std;

string g[200];
int h, w, in, arr[6];
char chs[6];
map<char, string> conv;

void print(int i){
    while(arr[i]--)
        cout << chs[i];
}

void initMap(){
    chs[0] = 'W';
    chs[1] = 'A';
    chs[2] = 'K';
    chs[3] = 'J';
    chs[4] = 'S';
    chs[5] = 'D';
    conv['0'] = "0000";
    conv['1'] = "0001";
    conv['2'] = "0010";
    conv['3'] = "0011";
    conv['4'] = "0100";
    conv['5'] = "0101";
    conv['6'] = "0110";
    conv['7'] = "0111";
    conv['8'] = "1000";
    conv['9'] = "1001";
    conv['a'] = "1010";
    conv['b'] = "1011";
    conv['c'] = "1100";
    conv['d'] = "1101";
    conv['e'] = "1110";
    conv['f'] = "1111";
}

void toHex(string b, int u){
    string hex = "";
    for(int i = 0; i < b.length(); i++){
        hex += conv[b[i]];
    }
    g[u] = hex;
}

void floodfill(char c, char d, int i, int j){
    if(i >= 0 && i < h && j >= 0 && j < w * 4 && g[i][j] == c){
        g[i][j] = d;
        floodfill(c, d, i + 1, j);
        floodfill(c, d, i - 1, j);
        floodfill(c, d, i, j + 1);
        floodfill(c, d, i, j - 1);
    }
}

void cont(int i, int j){
    if(i >= 0 && i < h && j >= 0 && j < w * 4){
        if(g[i][j] == '1'){
            g[i][j] = '*';
            cont(i + 1, j);
            cont(i - 1, j);
            cont(i, j + 1);
            cont(i, j - 1);
        }else if(g[i][j] == '0'){
            in++;
            floodfill('0', '*', i, j);
        }
    }
}

void bg(){
    for(int i = 0; i < w * 4; i++){
        if(g[0][i] == '0')
            floodfill('0', '*', 0, i);
        if(g[h - 1][i] == '0')
            floodfill('0', '*', h - 1, i);
    }
    for(int i = 0; i < h; i++){
        if(g[i][0] == '0')
            floodfill('0', '*', i, 0);
        if(g[i][w * 4 - 1] == '0')
            floodfill('0', '*', i, w * 4 - 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string curr;
    initMap();
    int ca, cj, cd, cs, cw, ck, cases = 0;
    while(cin >> h >> w && h + w){
        for(int i = 0; i < 6; i++)
            arr[i] = 0;
        for(int i = 0; i < h; i++){
            cin >> curr;
            toHex(curr, i);
        }
        bg();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w * 4; j++){
                if(g[i][j] == '1'){
                    in = 0;
                    cont(i, j);
                    arr[in]++;
                }
            }
        }
        cout << "Case " << ++cases << ": ";
        print(1);
        print(5);
        print(3);
        print(2);
        print(4);
        print(0);
        cout << "\n";

    }
    return 0;
}
