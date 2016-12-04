import java.util.HashMap;
import java.util.Scanner;


public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		HashMap<String, String> m = new HashMap<>();
		m.put("brasil","Feliz Natal!");
		m.put("alemanha","Frohliche Weihnachten!");
		m.put("austria","Frohe Weihnacht!");
		m.put("coreia","Chuk Sung Tan!");
		m.put("espanha","Feliz Navidad!");
		m.put("grecia","Kala Christougena!");
		m.put("estados-unidos","Merry Christmas!");
		m.put("inglaterra","Merry Christmas!");
		m.put("australia","Merry Christmas!");
		m.put("portugal","Feliz Natal!");
		m.put("suecia","God Jul!");
		m.put("turquia","Mutlu Noeller");
		m.put("argentina","Feliz Navidad!");
		m.put("chile","Feliz Navidad!");
		m.put("mexico","Feliz Navidad!");
		m.put("antardida","Merry Christmas!");
		m.put("canada","Merry Christmas!");
		m.put("irlanda","Nollaig Shona Dhuit!");
		m.put("belgica","Zalig Kerstfeest!");
		m.put("italia","Buon Natale!");
		m.put("libia","Buon Natale!");
		m.put("siria","Milad Mubarak!");
		m.put("marrocos","Milad Mubarak!");
		m.put("japao","Merii Kurisumasu!");
		String a;
		while(sc.hasNextLine()){
			a=sc.nextLine();
			if(m.containsKey(a)){
				System.out.println(m.get(a));
			}else{
				System.out.println("--- NOT FOUND ---");
			}
		}

	}

}