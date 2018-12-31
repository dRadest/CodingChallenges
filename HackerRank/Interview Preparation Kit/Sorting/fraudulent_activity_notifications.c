#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

int n, d;
scanf("%d %d", &n, &d);

int* expend = (int*)malloc(n * sizeof(int));       
int i, j;

for(i=0; i<n; i++) scanf("%d", (expend+i));

int notifications = 0;
int first = 1;
int expend_num[201] = {0};

for(i=d; i<n; i++){               

    if(first){
        for(j=0; j<d; j++) expend_num[*(expend+j)]++;                           first = 0;
    }
    else{
        expend_num[*(expend+i-1-d)]--;
        expend_num[*(expend+i-1)]++;
    }

    int find_median = 0;
    int median_2;

    for(j=0; j<=200; j++){
        find_median += expend_num[j];

        if(d % 2){ // odd number
            if(find_median > d/2){
                median_2 = 2 * j;
                break;
            }
        }
        else{ // even number
            if(find_median > d/2){
                median_2 = 2 * j;
                break;
            }
            if(find_median == d/2){
                median_2 = j;
                while(expend_num[j+1] == 0) j++;
                median_2 += j+1;
                break;
            }
        }                        
    }        

    if(*(expend+i) >= median_2) notifications++;            
}

printf("%d", notifications);

free(expend);
return 0;

}