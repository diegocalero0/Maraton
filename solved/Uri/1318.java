import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m;
		int n;
		int arreglo[];
		m=sc.nextInt();
		n=sc.nextInt();
		int aux;
		int result;
		while(m!=0&&n!=0){
			result=0;
			arreglo=new int[m+1];
			
			for (int i = 0; i < n; i++) {
				aux=sc.nextInt();
				if(arreglo[aux]==1){
					result++;
					arreglo[aux]++;
				}else{
					arreglo[aux]++;
				}
			}
			System.out.println(result);
			m=sc.nextInt();
			n=sc.nextInt();
		}

	}

}