import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the alternate function below.
    static int alternate(String s) {
        // create list of all different characters in a string
        List<Character> charlist = new ArrayList<>();
        for(int i=0; i<s.length(); i++){
            char curchar = s.charAt(i);
            if(!charlist.contains(curchar)){
                charlist.add(curchar);
            }
        }
        int maxnum = 0;
        int i = 0;
        while(i < charlist.size()-1){
            char charOne = charlist.get(i);
            int j = i + 1;
            while(j < charlist.size()){
                char charTwo = charlist.get(j);
                boolean first = true;
                int currnum = 0;
                for(int k=0; k<s.length(); k++){
                    char currchar = s.charAt(k);
                    if(charOne == currchar || charTwo == currchar){
                        if(charOne == currchar && first){
                            currnum++;
                            first = false;
                        }else if(charTwo == currchar && !first){
                            currnum++;
                            first = true;
                        }else {
                            currnum = 0;
                            break;
                        }
                    }
                }
                if(currnum > maxnum){
                    maxnum = currnum;
                } 
                j++;
            }
            i++;

        }
        return maxnum;
    
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int l = Integer.parseInt(bufferedReader.readLine().trim());

        String s = bufferedReader.readLine();

        int result = alternate(s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Solution {

    // Complete the alternate function below.
    static int alternate(String s) {
        // create list of all different characters in a string
        List<Character> charlist = new ArrayList<>();
        for(int i=0; i<s.length(); i++){
            char curchar = s.charAt(i);
            if(!charlist.contains(curchar)){
                charlist.add(curchar);
            }
        }
        int maxnum = 0;
        int i = 0;
        /*
        * chars in charlist in order as they appear in the string
        * traverse them two-by-two until you reach the end of charlist
        */
        while(i < charlist.size()-1){
            char charOne = charlist.get(i);
            int j = i + 1;
            while(j < charlist.size()){
                char charTwo = charlist.get(j);
                boolean first = true; // current char should be first or second of the two?
                int currnum = 0; // length of substring with the two chars
                for(int k=0; k<s.length(); k++){
                    char currchar = s.charAt(k);
                    if(charOne == currchar || charTwo == currchar){
                        if(charOne == currchar && first){
                            currnum++;
                            first = false;
                        }else if(charTwo == currchar && !first){
                            currnum++;
                            first = true;
                        }else {
                            currnum = 0;
                            break;
                        }
                    }
                }
                if(currnum > maxnum){
                    maxnum = currnum;
                } 
                j++;
            }
            i++;

        }
        return maxnum;
    
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int l = Integer.parseInt(bufferedReader.readLine().trim());

        String s = bufferedReader.readLine();

        int result = alternate(s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
