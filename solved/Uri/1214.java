import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Scanner;

/**
 *
 * @author admin
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
       int casos=sc.nextInt();
       int n=0;
       int p[];
       int suma=0;
       double d=0;
       int c=0;
       double resultado;
       DecimalFormat e=new DecimalFormat("0.000");
       DecimalFormatSymbols s=new DecimalFormatSymbols();
       s.setDecimalSeparator('.');
       e.setDecimalFormatSymbols(s);
       while(casos-->0){
           suma=0;
           c=0;
           n=sc.nextInt();
           p=new int[n];
           for (int i = 0; i < p.length; i++) {
               p[i]=sc.nextInt();
               suma+=p[i];
           }
           d=(double)(suma)/(double)(n);
           for (int i = 0; i < p.length; i++) {
               if(p[i]>d){
                   c++;
               }
           }
          resultado=(double)(c*100)/(double)(n);
           System.out.println(e.format(resultado)+"%");
       }
    }
    
}