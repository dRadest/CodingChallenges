#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
         long long int stack[100000],max[100000],x;
         long int N,top=-1,topm=0;
         int q;
         scanf("%ld",&N);
         // initialize all elements in the max stack to zero
         for(long int i=0;i<N;i++)
         {
             max[i] = 0;
         }
    
         for(long int i=0;i<N;i++ )
         {    
             scanf("%d",&q);
             if(q == 1) // push
             {
                 scanf(" %d", &x);
                 if(max[topm] <= x) // if current max less or equal to x
                 {
                     max[++topm] = x; // add x to the max stack
                 }
                 stack[++top] = x; // add x to the stack
             }
             else if(q == 2) // delete
             {
                 if(max[topm] == stack[top]) // if elements on the top of each stack equal
                 {
                     --topm; // delete from max stack
                 }
                 --top; // delete from stack
             }
             else if(q == 3) // print max
             {
                 printf("%d\n", max[topm]);
             }
         }
    return 0;
}
