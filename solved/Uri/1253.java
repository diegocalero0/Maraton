import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long casos=sc.nextLong();
		long cont=0;
		sc.nextLine();
		String a;
		String b="";
		long d;
		while(cont++!=casos){
			b="";
			a=sc.nextLine();
			d=sc.nextLong();
			sc.nextLine();
			for (int i = 0; i < a.length(); i++) {
				if(a.charAt(i)-d<65)
					b+=(char)(90-d+(Math.abs(65-a.charAt(i)))+1);
				else
					b+=(char)(a.charAt(i)-d);
			}
			System.out.println(b);
		}

	}

}