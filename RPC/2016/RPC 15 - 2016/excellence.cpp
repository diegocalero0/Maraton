#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    priority_queue<int> colaMayor;
    priority_queue<int, deque<int>, greater<int> > colaMenor;
    int aux;
    while(n--){
        cin >> aux;
        colaMayor.push(aux);
        colaMenor.push(aux);
    }

    int x = INT_MAX;

    while(!colaMayor.empty()){
        if(colaMayor.top() + colaMenor.top() < x){
            x = colaMayor.top() + colaMenor.top();
        }
        colaMayor.pop();
        colaMenor.pop();
    }

    cout << x << endl;

    return 0;
}
