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
        if(s.length()%2 != 0){ // input string has to be of even length
            return "NO";
        }
        Stack<Character> st = new Stack(); // stack of opening brackets
        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            if(ch == '(' || ch == '[' || ch == '{'){ // current char open bracket
                st.push(ch);
            }else if(!st.empty()){ // opening brackets stack has to contain characters
                // check if brackets match
                if(ch == ')' && st.peek() != '('){
                    return "NO";
                }
                if (ch == '}' && st.peek() != '{') {
                    return "NO";
                }
                if (ch == ']' && st.peek() != '[') {
                    return "NO";
                }
                st.pop(); // remove the top character
            }else if(ch == ')' || ch == ']' || ch == '}'){ // stack is empty and the current char is closing bracket
                return "NO";
            }
        }
        if(st.empty()){
            return "YES";
        }
        return "NO";
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
