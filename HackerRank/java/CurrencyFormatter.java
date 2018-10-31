import java.util.*;
import java.text.*;

public class CurrencyFormatter {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double payment = scanner.nextDouble();
        scanner.close();
        
        String us = NumberFormat.getCurrencyInstance(Locale.US).format(payment);
        String china = NumberFormat.getCurrencyInstance(Locale.CHINA).format(payment);
        // first, get the number format instance
        NumberFormat nff = NumberFormat.getCurrencyInstance(Locale.FRANCE);
        // second, use it to format the number
        String france = nff.format(payment);
        // create custom locale for India
        Locale IndiaLocale = new Locale("en", "IN");
        String india = NumberFormat.getCurrencyInstance(IndiaLocale).format(payment);
        
        System.out.println("US: " + us);
        System.out.println("India: " + india);
        System.out.println("China: " + china);
        System.out.println("France: " + france);

    }
}