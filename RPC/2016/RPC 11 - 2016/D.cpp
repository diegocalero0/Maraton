#include<bits/stdc++.h>
using namespace std;

    int contador;

    long d;
    long nd;
    long m;
    long nm;

int main(){

    long i;
    long n;
    while(cin>> d >> nd >> m >> nm){
        n = -1;

        if(d != nd && m != nm && m % d == 0 && nd != 1){


            for(i=d;i<m;i+=d){


                if(i % d == 0 && i % nd != 0 && m % i ==0 && nm % i != 0){
                    n = i;
                    break;
                }
            }
        }

        cout<<n<<"\n";

    }

    return 0;
}
