import java.util.ArrayList;
import java.util.Scanner;

public class WordScramble {

	public static void main(String[] args) {

		Scanner lector = new Scanner(System.in);
		ArrayList<String> sol = new ArrayList<>();

		while (lector.hasNext()) {

			String[] frase = lector.nextLine().split(" ");
			String fraseRv = "";
			String espacio = "";
			for (int i = 0; i < frase.length; i++) {

				fraseRv += espacio + reversa(frase[i]) ;
				espacio = " ";
			}
			
			System.out.println(fraseRv);

		}
	}

	public static String reversa(String p) {

		String pn = "";
		for (int i = p.length() - 1; i >= 0; i--) {

			pn += p.charAt(i) + "";
		}

		return pn;
	}
}