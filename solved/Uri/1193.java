import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Main {

	static Map<Character, Integer> mapaHex=new HashMap<Character, Integer>();
	
	public static void main(String[] args) {
		mapaHex.put('0', 0);
		mapaHex.put('1', 1);
		mapaHex.put('2', 2);
		mapaHex.put('3', 3);
		mapaHex.put('4', 4);
		mapaHex.put('5', 5);
		mapaHex.put('6', 6);
		mapaHex.put('7', 7);
		mapaHex.put('8', 8);
		mapaHex.put('9', 9);
		mapaHex.put('a', 10);
		mapaHex.put('b', 11);
		mapaHex.put('c', 12);
		mapaHex.put('d', 13);
		mapaHex.put('e', 14);
		mapaHex.put('f', 15);
		
		Scanner sc = new Scanner(System.in);
		int casos;
		casos=sc.nextInt();
		String instruccion[];
		String numero;
		String tipo;
		int cont=1;
		String numDec;
		String numBin;
		String numHex;
		int numeroDecimal;
		sc.nextLine();
		while(casos-->0){
			instruccion=sc.nextLine().split(" ");
			numero=instruccion[0];
			tipo=instruccion[1];
			System.out.println("Case "+cont+++":");
			switch (tipo) {
			case "bin":
				numeroDecimal=binToDec(numero);
				numDec=String.valueOf(numeroDecimal);
				numHex=Integer.toHexString(numeroDecimal);
				System.out.println(numDec+" dec");
				System.out.println(numHex+" hex");
				break;
			case "dec":
				numeroDecimal=Integer.parseInt(numero);
				numBin=Integer.toBinaryString(numeroDecimal);
				numHex=Integer.toHexString(numeroDecimal);
				System.out.println(numHex+" hex");
				System.out.println(numBin+" bin");
				break;
			case "hex":
				numeroDecimal=hexToDec(numero);
				numDec=String.valueOf(numeroDecimal);
				numBin=Integer.toBinaryString(numeroDecimal);
				System.out.println(numDec+" dec");
				System.out.println(numBin+" bin");
				break;

			}
			System.out.println();
		}
		sc.close();
	}
	public static int binToDec(String bin){
		int dec=0;
		char aux[]=bin.toCharArray();
		int k=0;
		for (int i = aux.length-1; i >=0; i--) {
			dec+=(int)((aux[i]-48)*Math.pow(2, k++));
		}
		return dec;
	}
	public static int hexToDec(String bin){
		int dec=0;
		char aux[]=bin.toCharArray();
		int k=0;
		for (int i = aux.length-1; i >=0; i--) {
			dec+=(int)((mapaHex.get(aux[i]))*Math.pow(16, k++));
		}
		return dec;
	}
}