#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n, m;
	cin >> t;
	int cases = 1;


	int matrix[50][50];

	while(t--){

		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}

		for(int j = 0; j < m; j++){
			for(int i = 0; i < n; i++){
				if(i == n - 1 && j == m - 1){
					cout << "Case #" << cases++ << ": " << (matrix[n - 1][m - 1] == 0 ? "YES" : "NO") << endl << endl;
				}
				if(i != n - 1){
					matrix[i + 1][j] += (matrix[i][j] * -1);
					matrix[i][j] = 0;
				}else{
					matrix[i][j + 1] += (matrix[i][j] * -1);
				}
			}
		}
		
	}

	return 0;
}
