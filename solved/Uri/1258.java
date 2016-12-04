import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<String> brancoP;
		ArrayList<String> brancoM;
		ArrayList<String> brancoG;
		ArrayList<String> vermelhoP;
		ArrayList<String> vermelhoM;
		ArrayList<String> vermelhoG;
		int n = sc.nextInt();
		String nombre;
		String camiseta;
		while (n != 0) {
			sc.nextLine();
			brancoP = new ArrayList<>();
			brancoM = new ArrayList<>();
			brancoG = new ArrayList<>();
			vermelhoP = new ArrayList<>();
			vermelhoM = new ArrayList<>();
			vermelhoG = new ArrayList<>();

			for (int i = 0; i < n; i++) {
				nombre = sc.nextLine();
				camiseta = sc.nextLine();
				switch (camiseta) {
				case "branco P":
					brancoP.add(nombre);
					break;

				case "branco M":
					brancoM.add(nombre);
					break;
				case "branco G":
					brancoG.add(nombre);
					break;

				case "vermelho P":
					vermelhoP.add(nombre);
					break;

				case "vermelho M":
					vermelhoM.add(nombre);
					break;
				case "vermelho G":
					vermelhoG.add(nombre);
					break;	
				}
			}
			
			imprimir(brancoP,"branco P");
			imprimir(brancoM,"branco M");
			imprimir(brancoG,"branco G");
			imprimir(vermelhoP,"vermelho P");
			imprimir(vermelhoM,"vermelho M");
			imprimir(vermelhoG,"vermelho G");
			n=sc.nextInt();
			if(n!=0){
				System.out.println();
			}
		}

	}
	public static void imprimir(ArrayList<String> a,String b){
		String aux;
		for(int j=0;a.size()-1-j>0;j++){
		for (int i = 0; i < a.size()-1-j; i++) {
			if(a.get(i).compareTo(a.get(i+1))>0){
				aux=a.get(i);
				a.set(i, a.get(i+1));
				a.set(i+1, aux);
				
			}
		}
	}
		for (int i = 0; i < a.size(); i++) {
			switch (b) {
			case "branco P":
				System.out.println(b+" "+a.get(i));
				break;

			case "branco M":
				System.out.println(b+" "+a.get(i));
				break;
			case "branco G":
				System.out.println(b+" "+a.get(i));
				break;

			case "vermelho P":
				System.out.println(b+" "+a.get(i));
				break;

			case "vermelho M":
				System.out.println(b+" "+a.get(i));
				break;
			case "vermelho G":
				System.out.println(b+" "+a.get(i));
				break;	
			}
		}
	}

}