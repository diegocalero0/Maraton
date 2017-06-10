#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int w, l, c;
    string t;
    int cont, lines, chars;

    while(cin >> w >> l >> c){
        lines = 0;
        chars = 0;
        cont = 1;
        for(int i = 0; i < w; i++){
            cin >> t;
            if(chars == 0){
                chars += t.length();
                lines++;
            }else{
                if(chars + t.length() + 1 > c){
                    chars = t.length();
                    lines++;
                    if(lines > l){
                        lines = 1;
                        cont++;
                    }
                }else{
                    chars += (t.length() + 1);
                }
            }
        }
        cout << cont << "\n";
    }

    return 0;

}
