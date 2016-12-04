using namespace std;

struct nodo{int xa; int ya; int xb; int yb; int xc; int yc; int c;};

int visitados[10][10][10][10][10][10], n;
string mapa[10];

bool mismoEspacio(int x1, int y1, int x2, int y2){
    if(x1 == x2 && y1 == y2)
        return true;
    return false;
}

void marcar(int x1, int y1, int x2, int y2, int x3, int y3){
    visitados[y1][x1][y2][x2][y3][x3] = 1;
    visitados[y1][x1][y3][x3][y2][x2] = 1;
    visitados[y2][x2][y1][x1][y3][x3] = 1;
    visitados[y2][x2][y3][x3][y1][x1] = 1;
    visitados[y3][x3][y1][x1][y2][x2] = 1;
    visitados[y3][x3][y2][x2][y1][x1] = 1;
}

bool esSolucion(int x1, int y1, int x2, int y2, int x3, int y3){
    if(mapa[y1][x1] == 'X' && mapa[y2][x2] == 'X' && mapa[y3][x3] == 'X')
        return true;
    return false;
}

int moverDer(int x, int y){
    if(x + 1 < n && mapa[y][x + 1] != '#')
        return x + 1;
    return x;
}

int moverAba(int x, int y){
    if(y + 1 < n && mapa[y + 1][x] != '#')
        return y + 1;
    return y;
}

int moverIzq(int x, int y){
    if(x - 1 >= 0 && mapa[y][x - 1] != '#')
        return x - 1;
    return x;
}

int moverArr(int x, int y){
    if(y - 1 >= 0 && mapa[y - 1][x] != '#')
        return y - 1;
    return y;
}

bool esValido(int x1, int y1, int x2, int y2, int x3, int y3){
    if((x1 != x2 || y1 != y2) && (x1 != x3 || y1 != y3) && (x2 != x3 || y2 != y3)){
        if(visitados[y1][x1][y2][x2][y3][x3] == 0){
            return true;
        }
    }
    return false;
}

int bfs(nodo inicial){
    queue<nodo> cola;
    cola.push(inicial);
    nodo aux;

    int x1, y1, x2, y2, x3, y3, x1aux, x2aux, x3aux, y1aux, y2aux, y3aux, c;
    while(!cola.empty()){
        aux = cola.front();
        cola.pop();

        x1 = aux.xa;
        y1 = aux.ya;
        x2 = aux.xb;
        y2 = aux.yb;
        x3 = aux.xc;
        y3 = aux.yc;
        c = aux.c;

        if(esSolucion(x1, y1, x2, y2, x3, y3))
            return aux.c;

        //mover derecha
        x1aux = moverDer(x1, y1);
        x2aux = moverDer(x2, y2);
        x3aux = moverDer(x3, y3);

        if(mismoEspacio(x1aux, y1, x2aux, y2)){
            x2aux--;
            if(mismoEspacio(x2aux, y2, x3aux, y3)){
                x3aux--;
            }
        }

        if(mismoEspacio(x1aux, y1, x3aux, y3)){
            x3aux--;
            if(mismoEspacio(x2aux, y2, x3aux, y3)){
                x2aux--;
            }
        }

        if(mismoEspacio(x2aux, y2, x3aux, y3)){
            x3aux--;
            if(mismoEspacio(x1aux, y1, x3aux, y3)){
                x3aux--;
            }
        }

        if(esValido(x1aux, y1, x2aux, y2, x3aux, y3)){
            marcar(x1aux, y1, x2aux, y2, x3aux, y3);
            nodo add = {x1aux, y1, x2aux, y2, x3aux, y3, c + 1};
            cola.push(add);
        }

        //mover izquierda
        x1aux = moverIzq(x1, y1);
        x2aux = moverIzq(x2, y2);
        x3aux = moverIzq(x3, y3);

        if(mismoEspacio(x1aux, y1, x2aux, y2)){
            x2aux++;
            if(mismoEspacio(x2aux, y2, x3aux, y3)){
                x3aux++;
            }
        }

        if(mismoEspacio(x1aux, y1, x3aux, y3)){
            x3aux++;
            if(mismoEspacio(x2aux, y2, x3aux, y3)){
                x2aux++;
            }
        }

        if(mismoEspacio(x2aux, y2, x3aux, y3)){
            x3aux++;
            if(mismoEspacio(x1aux, y1, x3aux, y3)){
                x3aux++;
            }
        }

        if(esValido(x1aux, y1, x2aux, y2, x3aux, y3)){
            marcar(x1aux, y1, x2aux, y2, x3aux, y3);
            nodo add = {x1aux, y1, x2aux, y2, x3aux, y3, c + 1};
            cola.push(add);
        }

        //mover abajo
        y1aux = moverAba(x1, y1);
        y2aux = moverAba(x2, y2);
        y3aux = moverAba(x3, y3);

        if(mismoEspacio(x1, y1aux, x2, y2aux)){
            y2aux--;
            if(mismoEspacio(x2, y2aux, x3, y3aux)){
                y3aux--;
            }
        }

        if(mismoEspacio(x1, y1aux, x3, y3aux)){
            y3aux--;
            if(mismoEspacio(x2, y2aux, x3, y3aux)){
                y2aux--;
            }
        }

        if(mismoEspacio(x2, y2aux, x3, y3aux)){
            y3aux--;
            if(mismoEspacio(x1, y1aux, x3, y3aux)){
                y3aux--;
            }
        }

        if(esValido(x1, y1aux, x2, y2aux, x3, y3aux)){
            marcar(x1, y1aux, x2, y2aux, x3, y3aux);
            nodo add = {x1, y1aux, x2, y2aux, x3, y3aux, c + 1};
            cola.push(add);
        }

        //mover arriba
        y1aux = moverArr(x1, y1);
        y2aux = moverArr(x2, y2);
        y3aux = moverArr(x3, y3);

        if(mismoEspacio(x1, y1aux, x2, y2aux)){
            y2aux++;
            if(mismoEspacio(x2, y2aux, x3, y3aux)){
                y3aux++;
            }
        }

        if(mismoEspacio(x1, y1aux, x3, y3aux)){
            y3aux++;
            if(mismoEspacio(x2, y2aux, x3, y3aux)){
                y2aux++;
            }
        }

        if(mismoEspacio(x2, y2aux, x3, y3aux)){
            y3aux++;
            if(mismoEspacio(x1, y1aux, x3, y3aux)){
                y3aux++;
            }
        }

        if(esValido(x1, y1aux, x2, y2aux, x3, y3aux)){
            marcar(x1, y1aux, x2, y2aux, x3, y3aux);
            nodo add = {x1, y1aux, x2, y2aux, x3, y3aux, c + 1};
            cola.push(add);
        }

    }

    return -1;

}

int main(){

    int t, xa, ya, xb, yb, xc, yc, c;
    cin >> t;
    c = 0;
    while(t--){
        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        for(int m = 0; m < n; m++){
                            for(int o = 0; o < n; o++){
                                visitados[i][j][k][l][m][o] = 0;
                            }
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            cin >> mapa[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mapa[i][j] == 'A'){
                    xa = j;
                    ya = i;
                }else if(mapa[i][j] == 'B'){
                    xb = j;
                    yb = i;
                }else if(mapa[i][j] == 'C'){
                    xc = j;
                    yc = i;
                }
            }
        }

        nodo inicial = {xa, ya, xb, yb, xc, yc, 0};
        marcar(xa, ya, xb, yb, xc, yc);
        cout << "Case " << ++c << ": ";
        int result = bfs(inicial);

        if(result != -1)
            cout << result << endl;
        else
            cout << "trapped" << endl;

    }

    return 0;
}