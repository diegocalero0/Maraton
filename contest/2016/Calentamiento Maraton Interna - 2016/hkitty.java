import java.util.Scanner;

public class hkitty {

	public static void main(String[] args) {
		
		Scanner lector = new Scanner(System.in);
		
		while(lector.hasNextLine()){
			
			String[] nums = lector.nextLine().split(" ");
			String palabra = "";
			if(nums.length==2){
				
				int num = Integer.parseInt(nums[1]);
				
				for (int i = 0; i < num; i++) {
					palabra += nums[0];
				}
				
				System.out.println(palabra);
				for (int i = 0; i < nums[0].length()-1; i++) {
					
					String one = palabra.charAt(0)+"";
					palabra = palabra.substring(1, palabra.length());
					palabra += one;
					System.out.println(palabra);
				}
			}
			else{
				break;
			}
		}
	}
}
