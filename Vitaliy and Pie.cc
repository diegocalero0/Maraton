#include<bits/stdc++.h>
using namespace std;

int cont[30];

int main(){

	int n;
	string s;
	cin >> n >> s;

	int res = 0;

	for(int i = 0; i < (n - 1) * 2; i+=2){
		cont[s[i] - 'a']++;
		
		if(cont[tolower(s[i + 1]) - 'a'] == 0)
			res++;
		else
			cont[tolower(s[i + 1]) - 'a']--;
		
	}

	cout << res << endl;

	return 0;
}