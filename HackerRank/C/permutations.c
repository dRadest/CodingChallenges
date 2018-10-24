#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// swaps the strings at indicies a and b
void swap(char **s, int a, int b){
    char* temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

// reverses the sequence of strings from start to end index
void reverse_sequence(char **s, int start, int end){
    while (start < end){
        swap(s, start++, end--);
    } 
}

int next_permutation(int n, char **s){
    int k = -1;
    int l = -1;
    // find the largest k such that s[k] < s[k+1]
    for (int i = n - 2; i > -1 ; i--){
        /* if the string at current index alphabetically 
        before the string at the next index */
        if (strcmp(s[i], s[i + 1]) < 0){
            // we found our k (break out of the loop)
            k = i; 
            break;
        }
    }
    // find the largest l > k such that s[k] < s[l]
    for (int j = n - 1; j > k && k > -1; j--){
        /* if the string at current index alphabetically 
        before the string at the next index */
        if (strcmp(s[k], s[j]) < 0){
            // we found our l
            l = j;
            // swap s[k] and s[l]
            swap(s, k, l);
            // reverse the sequence from k+1 up to and including final element
            reverse_sequence(s, k + 1, n - 1);
            // there is next permutation
            return 1;
        }
    }
    // there is no next permutation
    return 0;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}