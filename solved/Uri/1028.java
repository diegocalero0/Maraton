import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int casos=sc.nextInt();
		
		
		while(casos-->0){
			int f1=sc.nextInt();
			int f2=sc.nextInt();
		if(f1>f2){
			System.out.println(mcd(f1,f2));
		}else{
			System.out.println(mcd(f2,f1));
		}
		}
		
	}
	
	public static int mcd(int a,int b){
		if(a%b==0){
			return b;
		}else{
			return mcd(b,a%b);
		}
	}

}