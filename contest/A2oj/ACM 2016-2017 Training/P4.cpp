#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m, a, max_value = 0, min_value = 0;
    priority_queue<int> dec;
    priority_queue<int, deque<int>, greater<int> > cre;

    cin >> n >> m;
    while(m--){
        cin >> a;
        dec.push(a);
        cre.push(a);
    }

    while(n--){
        a = dec.top(), dec.pop();
        max_value += a;
        a--;
        if(a > 0)
            dec.push(a);
        a = cre.top(), cre.pop();
        min_value += a;
        a--;
        if(a > 0)
            cre.push(a);
    }

    cout << max_value << " " << min_value << endl;

    return 0;
}
