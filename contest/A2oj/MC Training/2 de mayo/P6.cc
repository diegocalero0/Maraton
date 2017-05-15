#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main(){

	int n, res = 0, aux = 0;
	bool flag = true;
	string m[110];
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> m[i];
	for(int i = 0; i < n; i++){
		if(flag){
			for(int j = 0; j < n; j++){
				if(m[i][j] == 'o'){
					aux++;
				}
				if(m[i][j] == 'A'){
					res = max(res, aux);
					aux = 0;
				}
			}
		}else{
			for(int j = n - 1; j >= 0; j--){
				if(m[i][j] == 'o'){
					aux++;
				}
				if(m[i][j] == 'A'){
					res = max(res, aux);
					aux = 0;
				}
			}
		}
		flag = !flag;
	}
	res = max(res, aux);
	cout << res << endl;
	return 0;
}