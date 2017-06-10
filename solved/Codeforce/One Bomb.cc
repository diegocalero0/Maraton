#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

string matriz[1005], matriz1[1005], matriz2[1005], matriz3[1005];
ii par;


int main(){

	int n, m;
	int left[2] = {5000, 5000}, rigth[2] = {-1, -1}, top[2] = {5000, 5000}, bottom[2] = {-1, -1};
	cin >> n >> m;
	int cont = 0;
	for(int i = 0; i < n; i++){
		cin >> matriz[i];
		matriz1[i] = matriz2[i] = matriz3[i] = matriz[i];
		for(int j = 0; j < m; j++){
			if(matriz[i][j] == '*'){
				cont++;
				if(j < left[1]){
					left[0] = i;
					left[1] = j;
				}
				if(j > rigth[1]){
					rigth[0] = i;
					rigth[1] = j;
				}
				if(i < top[0]){
					top[0] = i;
					top[1] = j;
				}
				if(i > bottom[0]){
					bottom[0] = i;
					bottom[1] = j;
				}
			}
		}
	}

	bool flag = false;
	if(cont == 0){
		cout << "YES" << endl;
		cout << 1 << " " << 1 << endl;
		return 0;
	}

	//first
	int ast = cont;
	for(int i = left[1]; i <= rigth[1]; i++){
		if(matriz[left[0]][i] == '*')
			ast--;
		matriz[left[0]][i] = '.';
	}
	for(int i = top[0]; i <= bottom[0]; i++)
		if(matriz[i][top[1]] == '*')
			ast--;
	if(ast == 0){
		par = ii(left[0] + 1, top[1] + 1);
		//cout << par.first << " ---1 " << par.second << endl;
		flag = true;
	}

	//second
	ast = cont;
	for(int i = rigth[1]; i >= left[1]; i--){
		if(matriz1[rigth[0]][i] == '*')
			ast--;
		matriz1[rigth[0]][i] = '.';
	}
	for(int i = top[0]; i <= bottom[0]; i++)
		if(matriz1[i][top[1]] == '*')
			ast--;
	if(ast <= 0){
		par = ii(rigth[0] + 1, top[1] + 1);
		//cout << par.first << " ---2 " << par.second << endl;
		flag = true;
	}

	//thirth
	ast = cont;
	for(int i = rigth[1]; i >= left[1]; i--){
		if(matriz2[rigth[0]][i] == '*')
			ast--;
		matriz2[rigth[0]][i] = '.';
	}
	for(int i = bottom[0]; i >= top[0]; i--)
		if(matriz2[i][bottom[1]] == '*')
			ast--;
	if(ast <= 0){
		par = ii(rigth[0] + 1, bottom[1] + 1);
		//cout << par.first << " ---3 " << par.second << endl;
		flag = true;
	}

	//fourth
	ast = cont;
	for(int i = left[1]; i <= rigth[1]; i++){
		if(matriz3[left[0]][i] == '*')
			ast--;
		matriz3[left[0]][i] = '.';
	}
	for(int i = bottom[0]; i >= top[0]; i--)
		if(matriz3[i][bottom[1]] == '*')
			ast--;
	if(ast <= 0){
		par = ii(left[0] + 1, bottom[1] + 1);
		//cout << par.first << " ---4 " << par.second << endl;
		flag = true;
	}

	if(flag){
		cout << "YES" << endl;
		cout << par.first << " " << par.second << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
