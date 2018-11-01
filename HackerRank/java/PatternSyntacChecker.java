import java.util.Scanner;
import java.util.regex.*;

public class PatternSyntaxChecker{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		while(testCases>0){
			String pattern = in.nextLine();
          	//Write your code
            try{
                // if pattern compiles, print "Valid"
                Pattern.compile(pattern);
                System.out.println("Valid");
            } catch (PatternSyntaxException e){
                // print "Invalid" if exception thrown (can't compile)
                System.out.println("Invalid");
            } finally {
                // decrement testCases either way
                testCases--;
            }
		}
        in.close(); // close the scanner
	}
}