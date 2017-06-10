#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
int main(){

	int b, arr[20100];
	cin >> b;
	ofstream cou("output.o");
	for(int k = 1; k <= b; k++){
		cin >> arr[0];
		for(int i = 0; i < arr[0] - 1; i++)
			cin >> arr[i + 1];
		int a = 1, z = 1;
		int indexi = 1, indexd = 1;
		int ans = 0, sum = 0;
		for(int i = 1; i < arr[0]; i++){
			sum += arr[i];
			if(sum >= ans){
				z = i;
				if(sum == ans){
					if(z - a > indexd - indexi){
						indexi = a;
						indexd = z;
					}
				}else{
					indexi = a;
					indexd = z;
				}
				ans = sum;
			}
			if(sum < 0){
				sum = 0;
				a = i + 1;
				z = i + 1;
			}
		}
		
		if(ans > 0)
			cout << "The nicest part of route " << k << " is between stops " << indexi << " and " << indexd + 1 << endl;
		else
			cout << "Route " << k <<" has no nice parts" << endl;
	}
	return  0;
}