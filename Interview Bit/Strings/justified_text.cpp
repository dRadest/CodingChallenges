/*
* https://www.interviewbit.com/problems/justified-text/
* Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
* You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
* Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
* Extra spaces between words should be distributed as evenly as possible.
* If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
* For the last line of text, it should be left justified and no extra space is inserted between words.
* Your program should return a list of strings, where each string represents a single line.
*/

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> result;
    short int k = 0, ls = 0;
    for (short int i = 0; i<A.size(); i+=k)
    {
        
        k = ls = 0;
        while (i+k<A.size() && ls + k + A[i+k].size() <= B)
        {
            ls += A[i+k].size();
            ++k;
        }
        string tmp = A[i];
        for (int j = 0; j < k - 1; j++) {
            if (i + k >= A.size()) tmp += " ";
            else tmp += string((B - ls) / (k - 1) + (j < (B - ls) % (k - 1)), ' ');
            tmp += A[i+j+1];
        }
        tmp += string(B - tmp.size(), ' ');

        result.emplace_back(tmp);
    }
    return result;
}
