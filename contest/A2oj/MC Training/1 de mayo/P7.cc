#include<bits/stdc++.h>
using namespace std;

int main(){

	string alf, line;
	bool flag;
	while(cin >> alf){
		cin.ignore();
		getline(cin, line);
		int res = 0;
		for(int i = 0; i < line.length(); i++){
			flag = true;
			for(int j = 0; j < alf.length() && flag; j++){
				if(line[i] == alf[j]){
					res++;
					flag = false;
				}
			}
		}
		cout << res << endl;
	}

	return 0;
}