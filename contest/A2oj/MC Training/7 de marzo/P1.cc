#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string m[150];
	ofstream cou("output.o");
	while(cin >> n){
		if(n % 2 == 0 && n != 2)
			n--;
		if(n != 2){
			int k = 0;
			for(int i = 0; i < (n / 2) + 1; i++){
				for(int j = 0; j < n; j++){
					if(j > (int)(n / 2) + k){
						break;
					}
					if(j >= (int)(n / 2) - k && j <= (int)(n / 2) + k)
						cout << "*";
					else
						cout << " ";

				}
				cout << endl;
				k++;
			}
			k = 0;
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < n; j++){
					if(j > (int)(n / 2) + k){
						break;
					}
					if(j >= (n / 2) - k && j <= (n / 2) + k)
						cout << "*";
					else
						cout << " ";
				}
				k++;
				cout << endl;
			}
		}else{
			cout << " * " << endl;
			cout << " * " << endl;
			cout << "***" << endl;
		}
		cout << endl;
	}

	return 0;
}
