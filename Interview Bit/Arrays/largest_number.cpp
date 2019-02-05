/*
* https://www.interviewbit.com/problems/largest-number/
* Given a list of non negative integers, arrange them such that they form the largest number.
*/

bool checkLarger(int a, int b){
    string aa = to_string(a);
    string bb = to_string(b);
    string st = aa + bb;
    string rev = bb + aa;
    
    if(st > rev){
        return true;
    }
    
    return false;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<int> sol = A;
    
    // sort numbers in lexicographically descending order
    sort(sol.begin(), sol.end(), checkLarger);
    
    string ans = "";
    // append each number to the answer
    for(int i = 0; i < sol.size(); i++){
        ans = ans + to_string(sol[i]);
    }
    
    if(ans[0] == '0'){
        return "0";
    }
    
    return ans;
}
