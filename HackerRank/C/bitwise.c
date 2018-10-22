#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;

    for (int i = 1; i < n; ++i)
    {
        for (int j = i+1; j <= n; ++j)
        {
            int tAnd = i&j;
            if (tAnd > maxAnd && tAnd < k)
            {
                maxAnd = tAnd;
            }
            int tOr = i|j;
            if (tOr > maxOr && tOr < k)
            {
                maxOr = tOr;
            }
            int tXor = i^j;
            if (tXor > maxXor && tXor < k)
            {
                maxXor = tXor;
            }

        }
    }

    printf("%d\n", maxAnd);
    printf("%d\n", maxOr);
    printf("%d\n", maxXor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) {
  	// variables to hold the maximum calculated values of bitwise operations
    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;

    for (int i = 1; i < n; ++i)
    {
        for (int j = i+1; j <= n; ++j)
        {
        	// check for AND
            int tAnd = i&j;
            if (tAnd > maxAnd && tAnd < k)
            {
                maxAnd = tAnd;
            }
            // check for OR
            int tOr = i|j;
            if (tOr > maxOr && tOr < k)
            {
                maxOr = tOr;
            }
            // check for XOR
            int tXor = i^j;
            if (tXor > maxXor && tXor < k)
            {
                maxXor = tXor;
            }

        }
    }

    // print each maximum value
    printf("%d\n", maxAnd);
    printf("%d\n", maxOr);
    printf("%d\n", maxXor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}