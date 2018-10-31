import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class EndOfFile {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = 1;
        while (sc.hasNext()) { // scanner has tokes in its input
                String s = sc.nextLine(); // advance past the current line and return it
                System.out.println(i++ + " " + s);
        }
        sc.close();
    }
}