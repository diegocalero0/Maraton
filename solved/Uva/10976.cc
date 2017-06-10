#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
priority_queue<ii> res;

int main(){
    int k;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> k){
        for(int i = k + 1; i <= 2 * k; i++){

            if((k * i)%(i - k) == 0)
                res.push(ii((k * i)/(i - k) , i));
        }
        cout << res.size() << "\n";
        while(!res.empty()){
            ii curr = res.top(); res.pop();
            cout << "1/" << k << " = 1/" << curr.first << " + 1/" << curr.second << "\n";
        }
    }

    return 0;
}
