#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, curr, min = INT_MAX, pos;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> curr;
		if(curr < min){
			min = curr;
			pos = i;
		}
	}
	cout << "Menor valor: " << min << endl;
	cout << "Posicao: " << pos << endl;
	return 0;
}