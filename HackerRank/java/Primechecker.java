import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.reflect.*;
// solves the problem of not finding symbol in
import static java.lang.System.in;

class Prime{
	/*
	* checks if the given integer n is a prime number
	* returns true if it is, false otherwise
	*/
    private boolean isPrime(int n){
        if(n <= 1) { // 1 is neither prime nor composite
            return false;
        }
        for(int i=2; i<= n/2; i++){
        	// remainder after division 0, n is NOT prime
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    /*
    * prints integer arguments that are prime
    */
    public void checkPrime(int... num){
        String primes = "";
        // traverse through the arguments
        for(int n : num){
            if(isPrime(n)){ // append the number to the primes String
                primes += n + " ";
            }
        }
        // print out the primes String
        System.out.println(primes);
    }
}

/*********************** locked section ***********************/
public class Solution {

	public static void main(String[] args) {
		try{
		BufferedReader br=new BufferedReader(new InputStreamReader(in));
		int n1=Integer.parseInt(br.readLine());
		int n2=Integer.parseInt(br.readLine());
		int n3=Integer.parseInt(br.readLine());
		int n4=Integer.parseInt(br.readLine());
		int n5=Integer.parseInt(br.readLine());
		Prime ob=new Prime();
		ob.checkPrime(n1);
		ob.checkPrime(n1,n2);
		ob.checkPrime(n1,n2,n3);
		ob.checkPrime(n1,n2,n3,n4,n5);	
		Method[] methods=Prime.class.getDeclaredMethods();
		Set<String> set=new HashSet<>();
		boolean overload=false;
		for(int i=0;i<methods.length;i++)
		{
			if(set.contains(methods[i].getName()))
			{
				overload=true;
				break;
			}
			set.add(methods[i].getName());
			
		}
		if(overload)
		{
			throw new Exception("Overloading not allowed");
		}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	
}