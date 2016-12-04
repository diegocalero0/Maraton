import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int casos=sc.nextInt();
		sc.nextLine();
		String impresion;
		String real;
		while(casos-->0){
			real="";
			impresion=sc.nextLine();
			for (int i = (impresion.length()/2)-1; i >=0; i--) {
				real+=impresion.charAt(i);
			}
			for (int i = impresion.length()-1; i>=impresion.length()/2; i--) {
				real+=impresion.charAt(i);
			}
			System.out.println(real);
		}

	}

}