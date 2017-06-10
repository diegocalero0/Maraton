#include<bits/stdc++.h>
using namespace std;

int main(){
		long i;
		int casos;
		cin>>casos;
		long n;
		long k;
		long long suma;
		while(casos--){
			i=1;
			suma=0;
			cin>>n;
			cin>>k;
			while(i<=sqrt(n)){
				if(k==1){
					break;
				}
				if(n%i==0){
					if(i%k!=0){
						suma+=i;
					}
					if((n/i)%k!=0&&(n/i)!=i){
						suma+=n/i;
					}
				}
				i++;
			}
			cout<<suma<<endl;
		}

    return 0;
}
