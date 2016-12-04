import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner (System.in);
		int A=sc.nextInt();
		int H=sc.nextInt();
		int k=A;
		int t=H;
		int R1=sc.nextInt();
		int R2=sc.nextInt();
		boolean aux=false;
		boolean aux2=false;
		while(A!=0&&H!=0&&R1!=0&&R2!=0){
			 aux=false;
			 aux2=false;
			if(R1>R2){
				if(R1*2<=A&&R1*2<=H){
			     A-=R1*2;
			     H-=R1*2;
			     aux=true;
			     
				}
				
				if(R2*2<=A||R2*2<=H||ccccetnoroo(k, t,  R1, R2 )){
				     
				     aux2=true;
				     
					}
			}else{
				if(R2*2<=A&&R2*2<=H){
				     A-=R2*2;
				     H-=R2*2;
				     aux=true;
				     
					}
					if(R1*2<=A||R1*2<=H||ccccetnoroo(k,  t,  R2, R1 )){
					    
					     aux2=true;
					     
						}
			}
			if(aux&&aux2){
				System.out.println("S");
			}else{
				System.out.println("N");
			}
			 A=sc.nextInt();
			 H=sc.nextInt();
			 k=A;
			 t=H;
			 R1=sc.nextInt();
			 R2=sc.nextInt();
		}
	}
	public static boolean ccccetnoroo(int A, int H, int R1, int R2 ){
		int x1=R1;
		int x2=A-R2;
		int y1=H-R1;
		int y2=R2;
		double dis=Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		if(dis>=R1+R2){
			return true;
		}
		return false;
	}

}