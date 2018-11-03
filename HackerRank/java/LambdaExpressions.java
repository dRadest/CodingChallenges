import java.io.*;
import java.util.*;

interface PerformOperation {
	boolean check(int a);
}
class MyMath {
	public static boolean checker(PerformOperation p, int num) {
 		return p.check(num);
 }

// Write your code here
	public static PerformOperation isOdd(){
    	return (a -> a % 2 != 0);
	}

	public static PerformOperation isPrime(){
    	return a -> {
            if (a <= 1){
                return false;
            }
            for(int i=2; i*i<=a; i++){
                if(a % i == 0){
                    return false;
                }
            }
            return true;
    	};
	}

	public static PerformOperation isPalindrome(){
    	return a -> {
            int r, sum = 0, temp = a;
            while (a > 0){
                r = a%10;
                sum = (sum*10)+r;
                a=a/10;
            }
            return (temp == sum);
    	};
	}
} // end of solution

public class Solution {

 public static void main(String[] args) throws IOException {
  MyMath ob = new MyMath();
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  int T = Integer.parseInt(br.readLine());
  PerformOperation op;
  boolean ret = false;
  String ans = null;
  while (T--> 0) {
   String s = br.readLine().trim();
   StringTokenizer st = new StringTokenizer(s);
   int ch = Integer.parseInt(st.nextToken());
   int num = Integer.parseInt(st.nextToken());
   if (ch == 1) {
    op = ob.isOdd();
    ret = ob.checker(op, num);
    ans = (ret) ? "ODD" : "EVEN";
   } else if (ch == 2) {
    op = ob.isPrime();
    ret = ob.checker(op, num);
    ans = (ret) ? "PRIME" : "COMPOSITE";
   } else if (ch == 3) {
    op = ob.isPalindrome();
    ret = ob.checker(op, num);
    ans = (ret) ? "PALINDROME" : "NOT PALINDROME";

   }
   System.out.println(ans);
  }
 }
}
