import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n=sc.nextLong();
		
		HashMap<Long, String> a = new HashMap<>();
		a.put((long) 61, "Brasilia");
		a.put((long) 71, "Salvador");
		a.put((long) 11, "Sao Paulo");
		a.put((long) 21, "Rio de Janeiro");
		a.put((long) 32, "Juiz de Fora");
		a.put((long) 19, "Campinas");
		a.put((long) 27, "Vitoria");
		a.put((long) 31, "Belo Horizonte");
		
		if(a.containsKey(n)){
			System.out.println(a.get(n));
		}else{
			System.out.println("DDD nao cadastrado");
		}

	}

}
