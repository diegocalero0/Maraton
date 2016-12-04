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
		String numero;
		int decimal;
		while(true){
			numero=sc.nextLine();
			if(numero.length()>2&&numero.charAt(1)=='x'){
				numero=numero.substring(2);
				System.out.println(String.valueOf(hexToDec(numero)));
			}else{
				decimal=Integer.parseInt(numero);
				if(decimal<0){
					break;
				}else{
				System.out.println("0x"+Integer.toHexString(decimal).toUpperCase());
				}
			}
		}

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