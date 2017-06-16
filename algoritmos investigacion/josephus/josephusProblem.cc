#include<bits/stdc++.h>
using namespace std;

/*
Problema: N personas se encuentran formando una circunferencia, y se empieza a matar cada k persona, solo una persona sobrevivie.
Cual?

para n = 4, k = 2:
1 mata a 3
2 mata a 4

*/

/*
Solucion recursiva y eficaz al problema de josephus
*/
int sol(int n, int k){
    if(n == 1)
        return 1;
    return (sol(n - 1, k) + k - 1) % n + 1;
}

/*
Simulacion del problema: complejidad O(n2)
*/
int sol2(int n, int k){
    int i, p;

    bitset<20001> bs;
    if(k != n)
        i = k % n;
    else
        i = k;
    p = n - 1;
    bs[i] = 1;
    int cont;
    while(p >= 1){
        cont = 0;
        while(cont < k){
            i = (i + 1) % (n + 1);
            i = i == 0 ? 1 : i;
            if(bs[i] == 0)
                cont++;
        }
            bs[i] = 1;
            p--;
        }
    return i;
}

int main(){
    int n, k, nc;
    cin >> nc;
    for(int cases = 1; cases <= nc; cases++){
        cin >> n >> k;
        cout << "Case " << cases << ": " << sol2(n, k) << "\n";
    }
    return 0;
}
