#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start;
    int duration;
    int end;
};

struct Available_Workshops
{
    int N;
    vector<Workshop> v;
    // constructor
    Available_Workshops(int &n)
    {
        v = vector<Workshop>(n);
        N = n;
    }
};

/* compare function to be used in the sort() function
sorting in ascending order by end time */
bool compare(Workshop &w1, Workshop &w2)
{
    return w1.end < w2.end;
}

Available_Workshops* initialize(int start_time[], int duration[], int n) 
{
	// create the array of available workshops
    Available_Workshops* AW = new Available_Workshops(n);
    
    // loop through all the workshops
    for(int i=0;i<n;i++)
    {
    	// save the times for each workshop in the vector field of Available_Workshops
        AW->v[i].start = start_time[i];
        AW->v[i].duration = duration[i];
        AW->v[i].end = start_time[i] + duration[i];
    }
    // sort the vector in ascending order by end times
    sort(AW->v.begin(),AW->v.end(),compare);
    
    return AW;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) 
{
	/* variables to hold the values of end time and 
		total count of available workshops */
    int end_time=0;
    int count=0;
    
    // loop through the vector of workshops
    for(int i=0;i<ptr->N; i++)
    	/* if start time of the current workshop 
    	 greater or equal than end time */
        if(ptr->v[i].start >= end_time)
        {
        	// adjust the end time
            end_time = ptr->v[i].end;
            // increment the count
            count += 1;
        }
    
    return count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}