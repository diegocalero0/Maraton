#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

/**
Problema: Dadas la cantidad de filas y de columnas de una matriz vacía indicar
la cantidad de caminos para ir desde (More bottom left) hasta (More top rigth)
*/

/**
Algoritmo sin utilizar programacion dinamica. Solo recursividad
Solucion si se mueve arriba + solucion si se mueve a la derecha 
*/
int  numberOfPaths(int m, int n){
   if (m == 1 || n == 1)
        return 1;
   return  numberOfPaths(m-1, n) + numberOfPaths(m, n-1);
           // + numberOfPaths(m-1,n-1);
}

/**
Algoritmo utilizando programacion dinamica Bottom - Up
*/
long long numberOfPathsDP(int m, int n){
    long long count[m][n];
 
    for (int i = 0; i < m; i++)
        count[i][0] = 1;
 
    for (int j = 0; j < n; j++)
        count[0][j] = 1;
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++)
            count[i][j] = count[i-1][j] + count[i][j-1];
 
    }
    return count[m-1][n-1];
}


/**
Lee el numero de casos para cada caso lee las filas y las columnas y llama el método puede llamarse
el metodo con DP para una mayor rapidez.
*/
int main(){

	int t;
	cin >> t;
    int r, c;
	while(t--){
		cin >> r >> c;
    cout << numberOfPathsDP(r, c) << endl;
	}

	return 0;
}