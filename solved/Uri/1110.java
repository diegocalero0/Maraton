import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		ArrayDeque<Integer> cola = new ArrayDeque<>();
		Scanner sc = new Scanner(System.in);
		
		int numCartas;
		int remain;
		String descartadas="";
		while((numCartas=sc.nextInt())!=0){
			descartadas="";
			ArrayDeque<Integer> baraja=new ArrayDeque<>();
			for (int i = 1; i<=numCartas; i++) {
				baraja.add(i);
			}
			while(true){
			descartadas+=baraja.pollFirst()+", ";
			if(baraja.size()>1){
				baraja.offerLast(baraja.pollFirst());
			}else{
				remain=baraja.pollFirst();
				System.out.println("Discarded cards: "+descartadas.substring(0,descartadas.length()-2));
				System.out.println("Remaining card: "+remain);
				break;
			}
		}
			
		}
		

	}

}