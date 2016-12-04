import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int g=sc.nextInt();
		String b=sc.nextLine();
		String a;
		boolean aux=false;
		while(g!=0&&!b.equals(" 0")){
			aux=false;
			b=b.substring(1);
			a="";
			for (int i = 0; i < b.length(); i++) {
				if(g+48!=b.charAt(i)){
					if(b.charAt(i)==48&&aux){
						a+=b.charAt(i);
					}else if(b.charAt(i)!=48){
						a+=b.charAt(i);
					}
					
					if(b.charAt(i)!=48){
						aux=true;
					}
				}
			}
			if(aux){
				System.out.println(a);
			}