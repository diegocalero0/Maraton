#include<bits/stdc++.h>
using namespace std;

int main(){

	string voc, s;

	while(cin >> voc){
		cin.ignore();
		getline(cin, s);
		int res = 0;
		for(int i = 0; i < s.length(); i++){
			for(int j = 0; j < voc.length(); j++)
				if(s[i] == voc[j])
					res++;
		}
		cout << res << endl;

	}

	return 0;
}