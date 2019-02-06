/* 
* https://www.interviewbit.com/problems/roman-to-integer/
* Given a roman numeral, convert it to an integer.
* Input is guaranteed to be within the range from 1 to 3999.
*/

// returns numeric value of the character c 
int value(char c){
    if(c == 'I'){
        return 1;
    }
    else if(c == 'V'){
        return 5;
    }
    else if(c == 'X'){
        return 10;
    }
    else if(c == 'L'){
        return 50;
    }
    else if(c == 'C'){
        return 100;
    }
    else if(c == 'D'){
        return 500;
    }
    else{
        return 1000;
    }
}
int Solution::romanToInt(string A) {
    int result = 0, last, sec_last;
    // traverse input string backwards
    for(int i = A.size()-1; i >= 0; i--){
        char c = A[i];
        last = value(A[i]);
        if(i != 0){
            sec_last = value(A[i-1]);
        }
        result = result + last;
        if(sec_last < last){
            // substract from result and decrement position
            result = result - sec_last;
            i--;
        }
        // 'nullify' last and sec_last
        sec_last = 0;
        last = 0;
    }
    
    return result;
}
