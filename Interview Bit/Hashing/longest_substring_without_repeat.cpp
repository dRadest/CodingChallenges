/*
* https://www.interviewbit.com/problems/longest-substring-without-repeat/
*
* Given a string,
* find the length of the longest substring without repeating characters.
* Example:
*   The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
*   For "bbbbb" the longest substring is "b", with the length of 1.
*/

int Solution::lengthOfLongestSubstring(string A) {
    if (A.empty())
        return 0;
    
    unordered_map<char, int> map;
    int count = 0;
    int len = 0;
    
    int pos = 0;
    int size = A.size();
    
    while (pos<size)
    {
        // char not mapped
        if (map.find(A[pos]) == map.end())
        {
            map[A[pos]] = pos;
            ++count; ++pos;
        }
        else
        {
            // re-set values
            pos = map[A[pos]] + 1;
            map.clear();
            len = max(count, len);
            count = 0;
        }
    }
    len = max(count, len);
    
    return len;
}


