import java.util.*;

public class StdinOutOne {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        scan.close()


        /* using buffered reader 
        
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int a = 0, b = 0, c = 0;
        try{
            String inputa = reader.readLine();
            a = Integer.parseInt(inputa);
            String inputb = reader.readLine();
            b = Integer.parseInt(inputb);
            String inputc = reader.readLine();
            c = Integer.parseInt(inputc);
        } catch(IOException e) {
            e.printStackTrace();
        }
        reader.close();

        */

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }
}