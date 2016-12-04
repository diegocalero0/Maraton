import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		long casos=sc.nextLong();
		long cont=0;
		long x;
		boolean a;
		while(cont++!=casos){
			x = sc.nextLong();
			a=true;
			for (int i = 2; (i*i)<=x && a; i++) {
				if(x%i==0){
					a=false;
				}
			}
			if(a){
				System.out.println("Prime");
			}else{
				System.out.println("Not Prime");
			}
		}

	}

}