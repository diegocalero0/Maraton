#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    double horas;
    double pph;

    cin>>n>>horas>>pph;

    double result = (double)horas*(double)pph;

    cout<<"NUMBER = "<<n<<endl;
    cout<<"SALARY = U$ ";
    printf("%.2f\n", result);
    return 0;
}
