#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, curr, aux1, aux2, num, cont, cases = 0;
    int used[10];
    bool flag, empt;
    while(cin >> n && n){
        if(cases++)
            cout << "\n";
        empt = false;
        for(int i = 1234; i <= 98765 / n; i++){
            cont = 0;
            flag = true;
            num = i * n;
            for(int j = 0; j <= 9; j++)
                used[j] = 0;
            if(i < 10000)
                used[0] = 1, cont++;
            aux1 = i;
            aux2 = num;
            while(aux1){
                if(used[aux1 % 10] == 0){
                    used[aux1 % 10] = 1;
                    aux1 = aux1 / 10;
                    cont++;
                }else{
                    flag = false;
                    break;
                }
            }

            while(aux2 && flag){
                if(used[aux2 % 10] == 0){
                    used[aux2 % 10] = 1;
                    aux2 = aux2 / 10;
                    cont++;
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag && cont == 10)
                printf("%0.5d / %0.5d = %d\n", num, i, n), empt = true;
        }
        if(!empt)
            printf("There are no solutions for %d.\n", n);
    }

    return 0;
}
