#include<bits/stdc++.h>
using namespace std;
typedef pair<double, double> dd;

class compare{
public:
    bool operator()(dd one, dd two){
        if(one.first != two.first)
            return one.first > two.first;
        return one.second < two.second;
    }
};

priority_queue<dd, deque<dd>, compare> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double n, l, w, x, r, dx, moreR, moreL;
    while(cin >> n >> l >> w){
        w /= 2.0;
        moreR = 0;
        for(int i = 0; i < n; i++){
            cin >> x >> r;
            dx = sqrt(r * r - w * w);
            if(r > w)
                pq.push(dd(x - dx, x + dx));
        }

        int cont = 0;
        while(!pq.empty()){
            dd curr = pq.top(); pq.pop();
            while(!pq.empty() && pq.top().first <= moreR){
                if(pq.top().second > curr.second){
                    curr = pq.top();
                    pq.pop();
                }else{
                    pq.pop();
                }
            }
            if(curr.first <= moreR && curr.second >= moreR){
                cont++;
                moreR = curr.second;
                if(moreR >= l)
                    break;
            }
        }
        if(moreR >= l)
            cout << cont << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}
