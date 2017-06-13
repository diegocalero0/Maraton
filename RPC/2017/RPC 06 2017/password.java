
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.HashMap;
import java.util.Map;

public class password {

    static StringBuilder respuesta;
    
    public static void main(String[] args) throws IOException {
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int casos = Integer.parseInt(br.readLine());

            for (int i = 0; i < casos; i++) {
                respuesta = new StringBuilder("");
                fractionToDecimal(Integer.parseInt(br.readLine()));
                respuesta.insert(1, '.');
                System.out.println(respuesta);
            }
           
    }

   static void fractionToDecimal(int n) {
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        int rem = 1;
        int cont = 0;
        while (!mp.containsKey(rem)) {
            mp.put(rem, cont);
            respuesta.append((int)rem / n);
            rem = rem % n;
            rem = rem * 10;
            cont++;
        }
    }
}
