#include<bits/stdc++.h>
using namespace std;
#define here cout << "entro" << endl;
#define debug(x) cout << #x << " = " << x << endl;
struct sofa
{
	int x1, y1, x2, y2;
	sofa(int a, int b, int c, int d){x1 = a, y1 = b, x2 = c, y2 = d;}; 
};

int main(){

	int d, n, m, l, r, t, b, x1, y1, x2, y2;

	cin >> d >> n >> m;

	vector<int> lr(100010, 0);
	vector<int> rl(100010, 0);
	vector<int> tb(100010, 0);
	vector<int> bt(100010, 0);
	vector<sofa> sofas;
	for(int i = 0; i < d; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		sofas.push_back(sofa(x1, y1, x2, y2));
	}

	cin >> l >> r >> t >> b;

	for(int i = 0; i < d; i++){
		sofa curr = sofas[i];
		lr[min(curr.x1, curr.x2)] += 1;
		rl[max(curr.x1, curr.x2)] += 1;
		tb[min(curr.y1, curr.y2)] += 1;
		bt[max(curr.y1, curr.y2)] += 1;
	}

	for(int i = 1; i <= n; i++){
		lr[i] = lr[i - 1] + lr[i];
	}
	
	for(int i = n - 1; i >= 0; i--){
		rl[i] = rl[i + 1] + rl[i];
	}
	
	for(int i = 1; i <= m; i++){
		tb[i] = tb[i - 1] + tb[i];
	}
	
	for(int i = m - 1; i >= 0; i--){
		bt[i] = bt[i + 1] + bt[i];
	}

	for(int i = 0; i < d; i++){
		sofa curr = sofas[i];
		int laux, raux, taux, baux;

		laux = lr[max(curr.x1, curr.x2) - 1] - (curr.x1 != curr.x2 ? 1 : 0);
		raux = rl[min(curr.x1, curr.x2) + 1] - (curr.x1 != curr.x2 ? 1 : 0);
		taux = tb[max(curr.y1, curr.y2) - 1] - (curr.y1 != curr.y2 ? 1 : 0);
		baux = bt[min(curr.y1, curr.y2) + 1] - (curr.y1 != curr.y2 ? 1 : 0);
		
		if(laux == l && raux == r && taux == t && baux == b){
			cout << i + 1 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}
