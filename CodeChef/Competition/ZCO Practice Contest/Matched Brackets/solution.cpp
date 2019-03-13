/*
*
* https://www.codechef.com/ZCOPRAC/problems/ZCO12001
*
*/
#include <bits/stdc++.h> 
  
int main() 
{ 
	// read input
    int n;
    std::cin >> n;
    int brackets[n];
    for (int i = 0; i <n ;++i) {
        std::cin >> brackets[i];
    }

    // variables to hold the result values
    int nest_depth = 0, nest_pos = 0, seq_len = 0, seq_pos = 0;
    // use stack to keep track of matching brackets
    int stack_size = 0; 
    std::stack<int> st;

	// indecies of matching pairs of brackets
	// first index of "(", second index of ")"
    std::vector<std::pair<int, int>> start_end;

    int i = 0;
    while(i<n) // traverse input array
    {
    	if(brackets[i] == 1) // open bracket
    	{
    		st.push(i);
    		stack_size++;
    	}else // close bracket
    	{
    		start_end.push_back(std::make_pair(st.top(), i));
    		st.pop();
    		stack_size--;
    	}
    	if(stack_size > nest_depth) // update nested depth
    	{
    		nest_depth = stack_size;
    		nest_pos = i + 1;
    	}
    	i++;
    }

	// traverse pairs of matching brackets
    for(i=0; i < start_end.size(); ++i)
    {
    	std::pair<int, int> p = start_end[i];
    	// find the largest difference in indecies 
    	// i.e. largest sequence length
    	if(p.second - p.first > seq_len)
    	{
    		seq_len = p.second - p.first + 1;
    		seq_pos = p.first + 1;
    	}
    }

    std::cout << nest_depth << " " << nest_pos << " " << seq_len << " " << seq_pos << "\n";
  
    return 0; 
} 
