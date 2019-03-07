/*
*
* https://www.codechef.com/INOIPRAC/problems/INOI1201
*
* SOLUTION:
* Key idea behind the greedy solution of this problem is to
* sort participants in descending order by the time they take 
* in vault and doughnuts tracks. Those are challanges participants 
* can tackle simultaneously and will be a deciding factor in 
* calculating overall time. Why? We want the citizen taking the longest
* to start as soon as possible as others will make up for whatever time 
* they fall behind in first challenge.
*
* NOTE:
* i)  Code could be simplified to store less data
* ii) Orson Welles' Citizen Kane (1941) is considered to be one of the greatest movies of all time.
*		How the movie came to be is equally as inspiring and profound.
* 
*/

#include <bits/stdc++.h>

struct Citizen{
	int cobol, val, dou, total;
};

int main(int argc, char const *argv[])
{
	// instance of Citizen to be used in
	// reading the input and processing the citizens
	Citizen kane;

	// read the input
	int n;
	std::vector<Citizen> participants;
	std::cin>>n;
	while(n--)
	{
		std::cin >> kane.cobol >> kane.val >> kane.dou;
		kane.total = kane.cobol + kane.val + kane.dou;
		participants.push_back(kane);

	}

	// sort participants by other two track's time descending
	std::sort(participants.begin( ), participants.end( ), [ ](const auto& one, const auto& two )
	{
   		return (one.val + one.dou) > (two.val + two.dou);
	});

	int start_time = 0; // keep track of when the citizen starts
	int min_time = 0; // overall min time
	// greedily, process all the participants 
	// starting from highest time to lowest
	for (int i = 0; i < participants.size(); ++i)
	{
		// current participant
		kane = participants[i];
		// when the participant finishes
		int finish_time = start_time + kane.total;
		if(finish_time > min_time) // update min time
		{
			min_time = finish_time;
		}
		// update start time for the next citizen
		start_time += kane.cobol;
	}

	std::cout << min_time << "\n";
	
	return 0;
}