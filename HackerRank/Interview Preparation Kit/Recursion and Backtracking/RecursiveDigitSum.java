import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
	static int digitString(String n) {
		if(n.length() == 1) {
			return Character.getNumericValue(n.charAt(n.length()-1));
		}
		int m=0;
		while(n.length()>0) {
			m += Character.getNumericValue(n.charAt(n.length()-1));
			n = n.substring(0, n.length()-1);
		}
		return digitString(String.valueOf(m));
	}

    static int digitSum(String n, int k) {
        int result1 = digitString(n);
        result1 *= k;
        int result = digitString(String.valueOf(result1));
        return result;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String n = in.next();
        int k = in.nextInt();
        int result = digitSum(n, k);
        System.out.println(result);
        in.close();
    }
}
