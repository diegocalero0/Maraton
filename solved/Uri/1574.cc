#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	int n;
	string ins;
	cin >> t;
	int pos;
	int ord;
	while(t--){
		cin >> n;
		pos = 0;
		vector<string> instrucciones;
		for(int i = 1; i <= n; i++){
			cin >> ins;
			if(ins == "LEFT"){
				instrucciones.push_back(ins);
				pos--;
			}else if(ins == "RIGHT"){
				instrucciones.push_back(ins);
				pos++;
			}else{
				cin >> ins;
				cin >> ord;
				ord--;
				ins = instrucciones[ord];
				if(ins == "LEFT"){
					pos--;
				}else{
					pos++;
				}
				instrucciones.push_back(ins);
			}
		}
		cout << pos << endl;
	}

	return 0;
}