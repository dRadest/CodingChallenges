import java.io.*;
import java.util.*;

public class StringTokens {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        // Write your code here.
        scan.close();
        // remove any leading and trailing whitespaces
        s = s.trim(); 
        if(s.length() == 0){
            System.out.println(0);
        } else {
            // split string around one or more non word character
            String[] tokens = s.split("[ !,?._'@]+"); 
            System.out.println(tokens.length);
            // print every token in tokens array
            for(String token : tokens){
                System.out.println(token);
            }
        }
    }
}