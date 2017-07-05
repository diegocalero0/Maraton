#include<bits/stdc++.h>
using namespace std;

int arr[150];
int seen[150];

int cont;

void dfs(int u){
	seen[u] = 1;
	cont++;
	if(!seen[arr[u]]){
		dfs(arr[u]);
	}
}

int main(){

	int n;
	vector<int> numbers;
	cin >> n;

	for(int i = 1; i <= n; i++){
		seen[i] = 0;
		cin >> arr[i];
	}


	for(int i = 1; i <= n; i++){
		cont = 0;
		if(!seen[i]){
 			dfs(i);
			numbers.push_back(cont);
		}
	}

	int res = numbers[0];
	for(int i = 1; i < numbers.size() ;i++){
		res = (res * numbers[i]) / (__gcd(numbers[i], res));
	}
	cout << res << endl;
	return 0;

}
