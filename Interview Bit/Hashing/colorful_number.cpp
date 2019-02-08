/*
* https://www.interviewbit.com/problems/colorful-number/
*
* For Given Number N find if its COLORFUL number or not
*
* Return 0/1
*
* COLORFUL number:
* A number can be broken into different contiguous sub-subsequence parts. 
* Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
* And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
*/

int Solution::colorful(int A) {
    if(A == NULL){
        return 0;
    }
    
    // construct a vector of individual digits
    vector<long long int> vec;
    while(A){
        vec.insert(vec.begin(), A%10);
        A /= 10;
    }
    // keep track of products of subsequences
    unordered_map<long long int, int> map;
    long long int key;
    // traverse vector to get all contiguous subsequences
    for(int i = 0; i < vec.size(); i++){
        key = 1;
        for(int j = i; j < vec.size(); j++){
            key *= vec[j];
            // product already mapped
            if(map.find(key) != map.end()){
                return 0;    
            }
            map.insert({key, key});
        }
    }
    return 1;
}
