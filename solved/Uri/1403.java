import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a[];
		int b[];
		int m=sc.nextInt();
		int n=sc.nextInt();
		int aux;
		int mayor;
		int c[];
		while(m!=0&&n!=0){
			a=new int[10001];
			c=new int[10001];
			for (int i = 0; i <m; i++) {
				for (int j = 0; j < n; j++) {
					aux=sc.nextInt();
					a[aux]++;
					c[aux]++;
					
				}
			}
			b=a;
			Arrays.sort(b);
			mayor=b[b.length-2];
			for (int i = 0; i < c.length; i++) {
				if(c[i]==mayor){
					System.out.print(i+" ");
				}
			}
			System.out.println();
			m=sc.nextInt();
			n=sc.nextInt();
		}

	}

}