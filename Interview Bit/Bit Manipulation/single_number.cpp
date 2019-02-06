/*
* https://www.interviewbit.com/problems/single-number/
* Given an array of integers, every element appears twice except for one. Find that single one.
* Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*
* idea:
* XOR is commutative: a^b = b˘a
* XOR is associative: (a^b)^c = a^(b^c)
* a^a = 0
* a^0 = a
* by xoering all the numbers, equals are going to 'nullify' each other and we are left with a single number
*/

int Solution::singleNumber(const vector<int> &A) {
    int xored = 0;
    for(int i=0; i<A.size(); i++){
        xored ^= A[i];
    }
    return xored;
}