import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Solution
{
    // method to multiply two numbers using KAratsuba algorithm
    static long multiply(long x, long y){

        int size1 = getSize(x);
        int size2 = getSize(y);

        // Maximum of lengths of number
        int N = Math.max(size1, size2);

        // for small values directly multiply      
        if (N < 10){
            return x * y;
        }


        // max length divided, rounded up  
        N = (N / 2) + (N % 2);    

        // multiplier
        long m = (long)Math.pow(10, N);

        // compute sub expressions        
        long b = x / m;
        long a = x - (b * m);
        long d = y / m;
        long c = y - (d * N);

        // compute sub expressions
        long z0 = multiply(a, c);
        long z1 = multiply(a + b, c + d);
        long z2 = multiply(b, d);          

        return z0 + ((z1 - z0 - z2) * m) + (z2 * (long)(Math.pow(10, 2 * N)));        

    }

    // method to calculate length or number of digits in a number
    static int getSize(long num){
        int ctr = 0;
        while (num != 0){
            ctr++;
            num /= 10;
        }

        return ctr;
    }

	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i=0; i<t; i++){
			long num1 = sc.nextLong();
			long num2 = sc.nextLong();
			long result = multiply(num1, num2);
			System.out.println(result);
		}
		sc.close();
	}
}