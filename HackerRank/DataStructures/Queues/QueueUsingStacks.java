import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Stack<Integer> s1 = new Stack<Integer>();
        Stack<Integer> s2 = new Stack<Integer>();
        Scanner scn = new Scanner(System.in);
        int q = scn.nextInt();
        for(int i=0; i<q; i++){
            int type = scn.nextInt();
            if(type == 1){
                int elem = scn.nextInt();
                s2.push(elem);
            }else {
                if(s1.isEmpty()){
                    while(!s2.isEmpty()){
                        s1.push(s2.pop());
                    }
                }
                if(!s1.isEmpty()){
                    if(type == 2){
                        s1.pop();
                    }
                    if(type == 3){
                        System.out.println(s1.peek());
                    }
                }
            }
        }
    }
}