#include<bits/stdc++.h>
using namespace std;

#define INF 9999999

bool permanente[250];
int dist[250], ady[250][250];

int n ,m ,c;

void floydwarshall(){
	for (int k = c ; k < n ; k++)
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < n ; j++)
				ady[i][j] = min(ady[i][j], ady[i][k] + ady[k][j]);
}

int main(){

    int k, u, v, p;
    int result;
    while(cin >> n >> m >> c >> k && (n || m || c || k)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ady[i][j] = INF;
            }
        }

        while(m--){
            cin >> u >> v >> p;
            ady[u][v] = p;
            ady[v][u] = p;
        }

        dist[c - 1] = 0;
        for(int i = c - 2; i >= 0; i--){
            dist[i] = dist[i + 1] + ady[i][i + 1];
        }
        floydwarshall();
        result = ady[k][c - 1];

        for(int i = 0; i < c - 1; i++){
            result = min(result, ady[k][i] + dist[i]);
        }

        cout << result << endl;

    }

    return 0;
}
