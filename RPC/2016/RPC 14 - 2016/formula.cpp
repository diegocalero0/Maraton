#include<bits/stdc++.h>
using namespace std;

double distancia(int x1, int y1, int x2, int y2){
    return sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) );
}

int main(){

    int x1, y1, x2, y2, x3, y3;
    double r, a, b, c, area, radio;
    double result;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cin >> r;


    a = distancia(x1, y1, x2, y2);
    b = distancia(x2, y2, x3, y3);
    c = distancia(x3, y3, x1, y1);

    area = sqrt( (4 * (a * a) * (b * b)) - (((a*a) + (b*b) - (c*c))*((a*a) + (b*b) - (c*c))) ) / 4;
    radio = (area * 2) / (a + b +c);
    result = (radio - r) * 100 / r;
    printf("%.3f\n", result);



}
