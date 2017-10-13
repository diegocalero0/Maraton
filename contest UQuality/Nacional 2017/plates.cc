#include<bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl;
int main(){


	int t, n, pos1, pos2, pos3;
	string s;
	cin >> t;
	vector<string> v;
	string aux = "***";
	
	for(int i = 'A'; i <= 'Z'; i++){
		aux[0] = i;
		for(int j = 'A'; j <= 'Z'; j++){
			aux[1] = j;
			for(int k = 'A'; k <= 'Z'; k++){
				aux[2] = k;
				v.push_back(aux);
			}
		}
	}


	while(t--){
		int cont = 0;
		cin >> s;
		n = s.length();


		int m[n][30];
		int fo[30];
		for(int i = 0; i < 26; i++)
			fo[i] = -1;
		for(int i = 0; i < n; i++){
			if(fo[s[i] - 'A'] == -1)
				fo[s[i] - 'A'] = i;
		}
	
		for(int i = 0; i < 26; i++)
			m[n - 1][i] = -1;
		for(int i = n - 2; i >= 0; i--){
			for(int j = 0; j < 26; j++){
				if(s[i + 1] == j + 'A'){
					m[i][j] = i + 1;
				}else{
					m[i][j] = m[i + 1][j];
				}
				
			}
		}


		for(int i = 0; i < v.size(); i++){
			aux = v[i];
			pos1 = fo[aux[0] - 'A'];
			
			if(pos1 == -1)
				continue;
			pos2 = m[pos1][aux[1] - 'A'];
			if(pos2 == -1)
				continue;
			pos3 = m[pos2][aux[2] - 'A'];
			if(pos3 == -1)
				continue;
			cont++;
		}
		for(int i = 0; i < n; i++){
			cout << s[i] << "| ";
			for(int j = 0; j < 26; j++){
				cout << m[i][j] << " ";
			}
			cout << endl;
		}

		cout << cont << endl;

	}

	return 0;
}