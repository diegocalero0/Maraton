#include<bits/stdc++.h>
using namespace std;

struct nodo{int x;int y;int c;};
string m[40];
int visitadosAux[40][40][40][40];
int mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int mov2[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int w;
int h;

bool verificar(int x,int y){
    if(x>=0&&x<w&&y>=0&&y<h&&m[y][x]!='#')
        return true;
    return false;
}

int bfs(nodo dest,nodo g,nodo m){
    int gx,gy,mx,my;
    int i;
    nodo auxg;
    nodo auxm;
    queue<nodo> colag;
    queue<nodo> colam;
    colag.push(g);
    colam.push(m);
    visitadosAux[g.y][g.x][m.y][m.x]=1;
    while(!colag.empty()&&!colam.empty()){
        auxg=colag.front();
        auxm=colam.front();
        colag.pop();
        colam.pop();
        if(auxg.x==dest.x&&auxg.y==dest.y&&auxm.x==dest.x&&auxm.y==dest.y){
            return auxg.c;
        }
        nodo a;
        for(i=0;i<4;i++){
            gx=auxg.x+mov[i][0];
            gy=auxg.y+mov[i][1];
            mx=auxm.x+mov2[i][0];
            my=auxm.y+mov2[i][1];

            if(!verificar(gx,gy)){
                gx=auxg.x;
                gy=auxg.y;
            }
            if(!verificar(mx,my)){
                mx=auxm.x;
                my=auxm.y;
            }

            if(visitadosAux[gy][gx][my][mx]==0){
                visitadosAux[gy][gx][my][mx]=1;
                a={gx,gy,auxg.c+1};
                colag.push(a);
                a={mx,my,auxm.c+1};
                colam.push(a);
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    int l;
    int result;
    int lx,ly,gx,gy,mx,my;
    int i,j;
    while(cin >> h >> w){
        memset(visitadosAux,0, sizeof(visitadosAux));
        cin>> ly >> lx >> gy >> gx >> my >> mx;
        lx--;
        ly--;
        gx--;
        gy--;
        mx--;
        my--;
        nodo destino={lx,ly,0};
        nodo f1={gx,gy,0};
        nodo f2={mx,my,0};

        for(i=0;i<h;i++){
            cin >> m[i];
        }

        destino={lx,ly,0};
        f1={gx,gy,0};
        f2={mx,my,0};
        result=bfs(destino,f1,f2);
        if(result==-1){
            cout<<"NO LOVE\n";
        }else{
            cout<<result<<"\n";
        }
    }
    return 0;
}
