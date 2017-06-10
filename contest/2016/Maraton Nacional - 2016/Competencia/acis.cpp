#include<bits/stdc++.h>

using namespace std;

double dist(double x1,double y1,double posx,double posy){
    return sqrt((posx-x1)*(posx-x1)+(posy-y1)*(posy-y1));
}

double distanciaMin(int x1,int y1,int x2,int y2,int posx,int posy){
    double u = (double)((posx-x1)*(x2-x1)+(posy-y1)*(y2-y1))/(double)(dist(x1,y1,x2,y2)*dist(x1,y1,x2,y2));
    double xi=x1 + u*(x2-x1);
    double yi=y1 + u*(y2-y1);
    if(u<0.0||u>1.0){
        return min(dist(x1,y1,posx,posy),dist(x2,y2,posx,posy));
    }
    return dist(posx,posy,xi,yi);
}

int main(){
    int n,posx,posy,x1,y1,x2,y2,xprimero,yprimero;
    double radio;

    while(cin >> n){
        radio = 10000000;
        cin >> posx >> posy >> x1 >> y1;
        xprimero = x1;
        yprimero = y1;

        while(--n){
            cin >> x2 >> y2;
            radio = min(radio,distanciaMin(x1,y1,x2,y2,posx,posy));
            x1=x2;
            y1=y2;
        }
        radio = min(radio,distanciaMin(xprimero,yprimero,x2,y2,posx,posy));
        printf("%.3f\n",radio);

    }

    return 0;
}
