import java.math.BigInteger;
import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
 
        String total, more;
        for(int t = 0; t < 10; ++t) {
            total = input.nextLine();
            more = input.nextLine();;
            BigInteger total_apples = new BigInteger(total);
            BigInteger excess_apples = new BigInteger(more);
 
            BigInteger ans_1 = total_apples.add(excess_apples).divide(BigInteger.valueOf(2));
            BigInteger ans_2 = total_apples.subtract(excess_apples).divide(BigInteger.valueOf(2));
 
 
 
            System.out.println(ans_1);
            System.out.println(ans_2);
 
        }
    }
}