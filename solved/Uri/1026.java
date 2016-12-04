import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a;
		long b;
		String as;
		String bs;
		StringBuilder result;
		String m,l;
		int mayor;
		int j;
		while(sc.hasNext()){
			result = new StringBuilder();
			a=sc.nextLong();
			b=sc.nextLong();
			as=Long.toBinaryString(a);
			bs=Long.toBinaryString(b);
			
			if(as.length()>bs.length()){
				mayor=as.length();
				m=as;
				l=bs;
				j=bs.length()-1;
			}
			else{
				mayor=bs.length();
				m=bs;
				l=as;
				j=as.length()-1;
			}
			
			for (int i = mayor-1; i >= 0; i--) {
			if(j>=0)	
				if(m.charAt(i)==l.charAt(j)){
					result.append(0);
				}else{
					result.append(1);
				}
			else{
				result.append(m.charAt(i));
			}
			j--;
			}
			
			System.out.println(numero(((result.reverse().toString()))));
		}

	}

	public static long numero(String a){
		int potencia=0;
		long numero=0;
		for (int i = a.length()-1; i >=0 ; i--) {
			if(Integer.valueOf(a.charAt(i)-48)==1){
				numero+=Math.pow(2, potencia);
			}
			potencia++;
		}
		return numero;
	}
}