#include<bits/stdc++.h>
using namespace std;

bool seen[8][8];

struct nodo{
	int x; int y; int c;
};

bool isValid(int x, int y){
	if(x >= 0 && x < 8 && y >= 0 && y < 8 && seen[x][y] == 0)
		return true;
	return false;
}

int mov[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

int bfs(nodo ini, nodo fin){
	queue<nodo> q;
	q.push(ini);

	while(!q.empty()){
		nodo curr = q.front(); q.pop();
		if(curr.x == fin.x && curr.y == fin.y)
			return curr.c;
		for(int i = 0; i < 8; i++){
			int x = curr.x + mov[i][0];
			int y = curr.y + mov[i][1];
			if(isValid(x, y)){
				seen[x][y] = 1;
				nodo temp = {x, y, curr.c + 1};
				q.push(temp);
			}
		}
	}

}

int main(){

	string aux1, aux2;

	int fila, columna;
	while(cin >> aux1 >> aux2){
		fila = ((int)aux1.at(0)) - 97;
        columna = (int)aux1.at(1) - 49;
        nodo inicial = {fila,columna, 0};

        fila = ((int)aux2.at(0)) - 97;
        columna = (int)aux2.at(1) - 49;
        nodo llegada = {fila,columna,0};

        for(int i = 0; i < 8; i++)
        	for(int j = 0; j < 8; j++)
        		seen[i][j] = 0;
        cout << "To get from " << aux1 << " to " << aux2 << " takes " << bfs(inicial, llegada) << " knight moves." << endl;
	}

	return 0;
}