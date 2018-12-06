import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    static HashMap<String, Boolean> map = new HashMap<String, Boolean>();
    
    static String passwordCracker(String[] pass, String attempt) {
    	List<String> result = new ArrayList<String>();
    	crack(attempt, pass, result);
    	if(result.size() > 0) {
    		StringBuilder sb = new StringBuilder();
    		for(String str:result) {
    			sb.append(str + " ");
    		}
    		return sb.toString().trim();
    	} else {
    		return "WRONG PASSWORD";
    	}
    }
    
    static boolean crack(String attempt, String[] pass, List<String> result) {
    	if(attempt.length() == 0) {
    		return true;
    	}
    	if(map.containsKey(attempt)) {
    		return false;
    	}
    	
    	for(String password:pass) {
    		if(attempt.startsWith(password)) {
    			result.add(password);
    			map.put(attempt, true);
    			if(crack(attempt.substring(password.length()), pass, result)) {
    				return true;
    			}
    			result.remove(result.size()-1);
    		}
    	}
    	return false;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            String[] pass = new String[n];
            for(int pass_i = 0; pass_i < n; pass_i++){
                pass[pass_i] = in.next();
            }
            String attempt = in.next();
            map.clear();
            String result = passwordCracker(pass, attempt);
            System.out.println(result);
        }
        in.close();
    }
}
