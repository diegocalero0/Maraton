#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        bool solved = false;
        for(int i = -100; i <= 100 && !solved; i++)
            for(int j = i + 1; j <= 100 && !solved && i * i <= c; j++)
                for(int k = j + 1; k <= 100 && !solved && i * i + j * j <= c; k++)
                    if(i != j && j != k && i != k && i + j + k == a && i * j * k == b && i * i + j * j + k * k == c){
                        solved = true;
                        cout << i << " " << j << " " << k << "\n";
                    }
        if(!solved)
            cout << "No solution.\n";
    }

    return 0;
}
