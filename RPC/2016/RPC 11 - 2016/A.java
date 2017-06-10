import java.util.Scanner;

public class A {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		while (sc.hasNextInt()) {

			int prim = sc.nextInt();
			int seg = sc.nextInt();
			int ter = sc.nextInt();

			if (prim == seg) {
				System.out.println("S");
			}

			else if (prim == ter) {
				System.out.println("S");
			}

			else if (seg == ter) {
				System.out.println("S");
			}

			else if (seg == (prim - ter) || seg == (ter - prim)) {
				System.out.println("S");

			}

			else if (prim == (seg - ter) || prim == (ter - seg)) {
				System.out.println("S");
			}

			else if (ter == (prim - seg) || ter == (seg - prim)) {
				System.out.println("S");
			} else {
				System.out.println("N");
			}

		}
	}

}
