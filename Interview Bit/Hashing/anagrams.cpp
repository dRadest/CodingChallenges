/*
* https://www.interviewbit.com/problems/anagrams/
*
* Given an array of strings, return all groups of strings that are anagrams. 
* Represent a group by a list of integers representing the index in the original list. 
* Look at the sample case for clarification.
*
* Example :
*	Input : cat dog god tca
*	Output : [[1, 4], [2, 3]]
* cat and tca are anagrams which correspond to index 1 and 4.
* dog and god are another set of anagrams which correspond to index 2 and 3.
* The indices are 1 based ( the first element has index 1 instead of index 0).
*
* Ordering of the result : You should not change the relative ordering 
* of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.
*/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int> > ans;
    // for mapping string to indecies it occurs at
    unordered_map<string, vector<int> > map;
    string temp;
    // traverse all strings
    for(int i = 0; i < A.size(); i++){
        temp = A[i];
        // map lexicographically sorted string to the index
        sort(temp.begin(),temp.end());
        map[temp].push_back(i+1);
    }
    
    auto it = map.begin();
    
    // push groups of indecies to ans
    while(it != map.end()){
        ans.push_back(it->second);
        it++;
    }

    return ans;
}
