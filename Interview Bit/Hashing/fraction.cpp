/*
* https://www.interviewbit.com/problems/fraction/
*
* Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
*
*If the fractional part is repeating, enclose the repeating part in parentheses.
*
* Example :
*   Given numerator = 1, denominator = 2, return "0.5"
*   Given numerator = 2, denominator = 1, return "2"
*   Given numerator = 2, denominator = 3, return "0.(6)"
*/

string Solution::fractionToDecimal(int A, int B) {
    if (A == 0)
        return "0";
    int64_t n = A,/*numerator*/ d = B/*denominator*/;
    string res = "";
    
    if (n < 0 ^ d < 0)      // Brilliant
        res += '-';
    
    n = abs(n), d = abs(d);
    
    res += to_string(n/d); // append decimal part
    int64_t rem = n%d; // remainder
    
    if (rem == 0)
        return res;
    
    res += '.';
    
    // map remainder to position in res string
    unordered_map<int, int> m;
    
    for (; rem; rem %= d)
    {
        if (m.find(rem) != m.end()) // remainder already mapped
        {
            res.insert(m[rem], 1, '(');
            res.push_back(')');
            break;
        }
        
        m[rem] = res.size();
        rem *= 10;
        res.push_back('0' + rem/d);
    }
    return res;
}
