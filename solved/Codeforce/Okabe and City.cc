#include<bits/stdc++.h>
using namespace std;
#define debug(x, y, z) cout << #x << " = " << x << " --- " << #y << " = " << y << " --- " << #z << " = " << z << endl;
#define here cout << "here" << endl;
struct state
{
	int r, c, cc;
	state(){r = 0; c = 0; cc = 0;};
	state(int a, int b, int c):r(a), c(b), cc(c){};
	bool operator <(state other) const{
		return cc > other.cc;
	}

};

typedef vector<state> vi;
typedef vector<vi> vvi;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m, k;
bool adj[10000][10000];
bool seenAdj[10000][10000], seenRow[10000], seenColumn[10000];
bool flag = false;

vvi inColumns(10000);
vvi inRows(10000);

bool isAdj(int r, int c){
	if(r >= 0 && r < n && c >= 0 && c < m && seenAdj[r][c] == 0 && adj[r][c] == 1){
		seenAdj[r][c] = 1;
		return true;
	}
	return false;
}

bool isValid(int r, int c){
	if(r == -1){
		if(c >= 0 && c < m && seenColumn[c] == 0){
			seenColumn[c] = 1;
			return true;
		}
	}
	if(c == -1){
		if(r >= 0 && r < n && seenRow[r] == 0){
			seenRow[r] = 1;
			return true;
		}
	}
	return false;
}

int solve(){
	priority_queue<state> pq;
	pq.push(state(0, 0, 0));
	seenAdj[0][0] = 1;
	while(!pq.empty()){
		state curr = pq.top(); pq.pop();
		if(curr.r == n - 1 && curr.c == m -1)
			return curr.cc;
		//debug(curr.r, curr.c, curr.cc);
		for(int i = 0; i < 4 && curr.r != -1 && curr.c != -1; i++){
			int dc = curr.c + dx[i];
			int dr = curr.r + dy[i];
			
			if(isAdj(dr, dc)){
				pq.push(state(dr, dc, curr.cc));
			}
		}

		if(curr.r == -1){
			for(int i = 0; i < inColumns[curr.c].size(); i++){
				state now = inColumns[curr.c][i];
				if(!flag && now.r == n - 1 && now.c == m - 1 && curr.c != m - 1) continue;
				if(now.r == n - 1 && now.c == m - 1)
					flag = true;
				if(isAdj(now.r, now.c)){
					now.cc = curr.cc;
					pq.push(now);
				}
			}
		}

		if(curr.c == -1){
			for(int i = 0; i < inRows[curr.r].size(); i++){
				state now = inRows[curr.r][i];
				if(!flag && now.r == n - 1 && now.c == m - 1 && curr.r != n - 1) continue;
				if(now.r == n - 1 && now.c == m - 1)
					flag = true;
				if(isAdj(now.r, now.c)){
					now.cc = curr.cc;
					pq.push(now);
				}
			}
		}

		if(curr.r != -1 && curr.c != -1){
			if(isValid(curr.r + 1, -1))
				pq.push(state(curr.r + 1, -1, curr.cc + 1));

			if(isValid(curr.r - 1, -1))
				pq.push(state(curr.r - 1, -1, curr.cc + 1));

			if(isValid(-1, curr.c + 1))
				pq.push(state(-1, curr.c + 1, curr.cc + 1));

			if(isValid(-1, curr.c - 1))
				pq.push(state(-1, curr.c - 1, curr.cc + 1));

			if(isValid(-1, curr.c))
				pq.push(state(-1, curr.c, curr.cc + 1));

			if(isValid(curr.r, -1))
				pq.push(state(curr.r, -1, curr.cc + 1));
		}

	}

	return -1;
}

int main(){

	int r, c;
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		cin >> r >> c;
		if(r == n && c == m)
			flag = true;
		r--, c--;
		state now(r, c, 0);
		inColumns[c].push_back(now);
		inRows[r].push_back(now);
		if(c - 1 >= 0)
			inColumns[c - 1].push_back(now);
		if(c + 1 < m)
			inColumns[c + 1].push_back(now);
		if(r - 1 >= 0)
			inRows[r - 1].push_back(now);
		if(r + 1 < n)
			inRows[r + 1].push_back(now);
		adj[r][c] = 1;
	}
	
	r = n - 1;
	c = m - 1;
	adj[r][c] = 1;
	state now(r, c, 0);
	inColumns[c].push_back(now);
	inRows[r].push_back(now);
	if(c - 1 >= 0)
		inColumns[c - 1].push_back(now);
	if(c + 1 < m)
		inColumns[c + 1].push_back(now);
	if(r - 1 >= 0)
		inRows[r - 1].push_back(now);
	if(r + 1 < n)
			inRows[r + 1].push_back(now);

	int res = solve();
	if(res != -1 && !flag)
		res++;
	cout << res << endl;
	return 0;
}