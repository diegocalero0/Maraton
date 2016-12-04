import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a;
		long b;
		long result;
		
		while(sc.hasNextLong()){
			a=sc.nextLong();
			b=sc.nextLong();
			
			result=factorial(a)+factorial(b);
			System.out.println(result);
		}
		
	}
	
	public static long factorial(long a){
		if(a==0)
			return 1;
		else
			return a*factorial(a-1);
	}
	

}