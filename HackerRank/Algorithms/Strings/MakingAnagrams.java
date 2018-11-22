import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        String s1 = in.nextLine();
        String s2 = in.nextLine();
        in.close();
        int cArr[]=new int[26];
        for(int i=0;i<s1.length();i++)
            cArr[s1.charAt(i)-97]++;
        for(int i=0;i<s2.length();i++)
            cArr[s2.charAt(i)-97]--;
        int count=0;
        for(int i=0;i<26;i++)
            count+=Math.abs(cArr[i]);
        System.out.println(count);
    }
}