import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the isBalanced function below.
    static String isBalanced(String s) {
        int n = s.length();
        if(n %2 != 0){
            return "NO";
        }
        Stack<Character> opening = new Stack<Character>();
        for (int i=0; i<n; i++) {
            char curChar = s.charAt(i);
            if(curChar == '{' || curChar == '[' || curChar == '('){
                opening.push(curChar);
            }else if(!opening.isEmpty()){
                char openChar = opening.pop();
                if(curChar == '}' && openChar != '{'){
                    return "NO";
                }
                if(curChar == ']' && openChar != '['){
                    return "NO";
                }
                if(curChar == ')' && openChar != '('){
                    return "NO";
                }
            }else if(curChar == ')' || curChar == ']' || curChar == '}'){
                return "NO";
            }
        }
        
        if(!opening.isEmpty()){
            return "NO";
        }
        return "YES";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String s = scanner.nextLine();

            String result = isBalanced(s);

            bufferedWriter.write(result);
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
