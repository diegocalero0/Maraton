import java.math.BigInteger;
import java.util.Scanner;

/*
	Problema: solucionar (66 elevado a la n) % 100... n puede tener hasta 1000000 cifras 
*/
public class problem {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		BigInteger a = new BigInteger("66");
		BigInteger mod = new BigInteger("100");
		BigInteger i, res;

		sc.nextLine();

		while(t-- > 0){
			String s = sc.nextLine();
			s = s + s;
			System.out.println("digitos: " + s.length());
			i = new BigInteger(s);
			res = a.modPow(i, mod);
			System.out.println(res.toString());
		}
	}
}
