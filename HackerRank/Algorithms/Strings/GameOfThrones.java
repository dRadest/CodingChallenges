import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static String gameOfThrones(String s){
        Map<Character, Integer> map = new HashMap<Character, Integer>();
		for(int i=0; i<s.length(); i++) {
			char ch = s.charAt(i);
			if(!map.containsKey(ch)) {
				int count = 0;
				for(int j=0; j<s.length(); j++) {
					if(ch == s.charAt(j)) {
						count++;
					}
				}
				map.put(ch, count);
			}
		}
		int cnt = 0;
		Object[] array = map.values().toArray();
		for(Object o:array) {
			if((int)o%2 != 0) {
				cnt++;
			}
		}
		String answer = cnt > 1 ? "NO" : "YES";
		return answer;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String result = gameOfThrones(s);
        System.out.println(result);
    }
}
