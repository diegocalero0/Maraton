#include <bits/stdc++.h>
using namespace std;


int main(){

int nCasos,casas,aux,n;
int altura,ancho,areaCuadrado;
double  areaTotal,areaTriangulo;
char c;

scanf("%d",&nCasos);

while(nCasos--){
   cin >> casas;
   aux=0;
   altura=ancho=0;
   areaTotal=areaCuadrado=areaTriangulo= 0.0;
   for(int i=0; i < casas; i++){
   cin >> c >> n;
       if(c=='C'){
      	    areaCuadrado+= n * n;      	
      	    aux++;
      	}else if(c=='S'){
        	 areaCuadrado+= n * n;
      	}else{
      		areaTriangulo+= (sqrt(3)/4) * (n * n);
      	}

      	     if(aux<=2){
      	 		altura+=n;
      	 		if(aux==2){
      	 			aux++;
      	 		}
      	 	}
      	 	if (aux>=3 && aux <= 4){
     			ancho+=n;
     			if(aux==4)aux++;
      	 	}
   }
   	
  double area=altura*ancho;
  area=area - areaTriangulo -areaCuadrado;
   printf("%.4lf\n",area);
}

	return 0;
}
