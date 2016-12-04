import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		int matris[][];
		int b=0;
		int a=2;
		int k=0;
		int mayor=0;
		while(true){
			b=0;
			a=2;
			mayor=0;
			k=0;
			n=sc.nextInt();
			if(n==0)
				break;
			matris=new int[n][n];
			for (int i = 0; i < matris.length; i++) {
				for (int j = 0; j < matris.length; j++) {
					matris[i][j]=(int) Math.pow(a, k);
					k++;
					
					if(i==n-1&&j==n-1){
						mayor=matris[i][j];
					}
					
				}
				k=b+1;
				b++;
				
			}
			int t=String.valueOf(mayor).length();
			for (int i = 0; i < matris.length; i++) {
				for (int j = 0; j < matris.length; j++) {
					System.out.print(String.format("%1$"+t+"s",String.valueOf(matris[i][j])));
					if(j!=n-1){
						System.out.print(" ");
					}
				}
				System.out.println();
			}
			System.out.println();
		}

	}

}