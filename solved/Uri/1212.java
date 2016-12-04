import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a;
		long b;
		int acarreos=0;
		int aux=0;
		while(true){
			acarreos=0;
			aux=0;
			a=sc.nextLong();
			b=sc.nextLong();
			if(a==0&&b==0){
				break;
			}
			
			while(a!=0&&b!=0){
				if((a%10+b%10+aux)>9){
					acarreos++;
					aux=1;
				}else{
					aux=0;
				}
				a=(int)a/10;
				b=(int)b/10;
				
				if(a==0&&b!=0){
					if(b%10+aux>9)
						acarreos++;
				}else if(b==0&&a!=0){
					if(a%10+aux>9)
						acarreos++;
				}
			}
			if(acarreos==0){
				System.out.println("No carry operation.");
			}else if(acarreos==1){
				System.out.println(acarreos+" carry operation.");
			}else{
				System.out.println(acarreos+" carry operations.");
			}
		}

	}

}