#include<bits/stdc++.h>
using namespace std;

//For meyito with all my heart

int main(){

    priority_queue< int, deque<int>, greater<int> > mejores;

    long total = 0;
    int n, k, t, maxActual;
    cin >> n >> k;
    int valores[n];

    for(int i = 0;i < n; i++){
        cin >> valores[i];
        total += valores[i];
    }


    t = 2 * k + 1;
    maxActual = 1;
    for(int i = k; i < n; i++){
        if(i == t){
            t += (k + 1);
            maxActual++;
        }

        if(mejores.size() == maxActual){
            if(valores[i] > mejores.top()){
                mejores.pop();
                mejores.push(valores[i]);
            }
        }else{
            mejores.push(valores[i]);
        }
    }

    long resta = 0;

    while(!mejores.empty()){
        resta += mejores.top();
        mejores.pop();
    }

    cout << total - resta << endl;

    return 0;
}
