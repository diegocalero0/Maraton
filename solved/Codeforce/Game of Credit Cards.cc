#include<bits/stdc++.h>
using namespace std;

int sd[10], md[10];

int find_min(int a){
	for(int i = a; i < 10; i++)
		if(md[i] > 0){
			md[i]--;
			return 1;
		}
	return -1;
}

int find_max(int a){
	for(int i = a + 1; i < 10; i++)
		if(md[i] > 0){
			md[i]--;
			return 1;
		}
	return -1;
}

int main(){
	int n, res_min = 0, res_max = 0;
	for(int i = 0; i < 10; i++)
		sd[i] = md[i] = 0;
	string s, m;
	cin >> n >> s >> m;
	for(int i = 0; i < n; i++){
		sd[s[i] - 48]++;
		md[m[i] - 48]++;
	}
	for(int i = 0; i < n; i++)
		if(find_max(s[i] - 48) != -1)
			res_max++;
	for(int i = 0; i < 10; i++)
		sd[i] = md[i] = 0;
	for(int i = 0; i < n; i++){
		sd[s[i] - 48]++;
		md[m[i] - 48]++;
	}
	for(int i = 0; i < n; i++)
		if(find_min(s[i] - 48) == -1)
			res_min++;
	cout << res_min << endl;
	cout << res_max << endl;

	return 0;
}