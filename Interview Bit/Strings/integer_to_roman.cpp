/*
* https://www.interviewbit.com/problems/integer-to-roman/
* Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version
* Input is guaranteed to be within the range from 1 to 3999.
*
* details about expected output:
* https://projecteuler.net/about=roman_numerals
*
* geekforgeeks:
* https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/
*/

string Solution::intToRoman(int num) {
    // storing roman values of digits from 0-9  
    // when placed at different places 
    string m[] = {"", "M", "MM", "MMM"}; 
    string c[] = {"", "C", "CC", "CCC", "CD", "D",  
                        "DC", "DCC", "DCCC", "CM"}; 
    string x[] = {"", "X", "XX", "XXX", "XL", "L",  
                        "LX", "LXX", "LXXX", "XC"}; 
    string i[] = {"", "I", "II", "III", "IV", "V",  
                        "VI", "VII", "VIII", "IX"}; 
          
     // Converting to roman 
     string thousands = m[num/1000]; 
     string hundereds = c[(num%1000)/100]; 
     string tens =  x[(num%100)/10]; 
     string ones = i[num%10]; 
          
     string ans = thousands + hundereds + tens + ones; 
          
     return ans; 
}
