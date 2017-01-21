#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, y, mat[100][100];
    long long k, in = 0, ex = 0, max_, min_, pos, total, rxr;
    bool up = true;
    cin >> n >> m >> k >> x >> y;
    x--;
    y--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mat[i][j] = 0;
    rxr = 2 * (n - 1);
    total = rxr * m;
    if(k >= total){
        ex = n == 1 ? 0: k / total;
        in = ex * 2;
        if(n == 1)
            ex = k / m, in = 0;
        k = n == 1 ? k - ex * m : k - ((ex * m) * 2) - ((in * m) * (n - 2));
    }
    int i = 0;
    while(k > 0){
        for(int j = 0; j < m && k > 0; j++){
            mat[i][j]++;
            k--;
        }
        if(up){
            i++;
            if(i == n){
                i = n - 2;
                up = false;
            }
        }else{
            i--;
            if(i == -1){
                i = 1;
                up = true;
                if(n == 1)
                    i = 0;
            }
        }
    }
    max_ = -1;
    min_ = LONG_LONG_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n - 1){
                max_ = max(max_, mat[i][j] + ex);
                min_ = min(min_, mat[i][j] + ex);
                if(i == x && j == y)
                    pos = mat[i][j] + ex;
            }else{
                max_ = max(max_, mat[i][j] + in);
                min_ = min(min_, mat[i][j] + in);
                if(i == x && j == y)
                    pos = mat[i][j] + in;
            }
        }
    }
    cout << max_ << " " << min_ << " " << pos << endl;
    return 0;
}
