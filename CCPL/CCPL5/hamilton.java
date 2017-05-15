import java.util.Scanner;

public class hamilton {
    
    public static void main(String[] args) {
        Scanner lector = new Scanner(System.in);
        
        while (lector.hasNext()) {
            int n =  lector.nextInt();
            long a = grayToBinary32(Long.parseLong(lector.next(),2));
            long b = grayToBinary32(Long.parseLong(lector.next(),2));
            System.out.println(( (b-1) - a) );
            
        }
    }
   static long grayToBinary32(long num)
    {
        num = num ^ (num >> 32);
        num = num ^ (num >> 16);
        num = num ^ (num >> 8);
        num = num ^ (num >> 4);
        num = num ^ (num >> 2);
        num = num ^ (num >> 1);
        return num;
    }
    
}