#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

// returns the area of triangle
double area_of_triangle(triangle* tr){
    int a = tr -> a;
    int b = tr -> b;
    int c = tr -> c;
    double p = (a + b + c) / 2.0; /* divide by 2.0 to avoid casting to int*/
    double expression = p*(p-a)*(p-b)*(p-c);
    double area = sqrt(expression);
    return area;
}
// sort triangles based on their areas in ascending order
int comparator(const void *p, const void *q)  { 
    triangle* tr1 = (triangle*) p;
    triangle* tr2 = (triangle*) q;
    double a1 = area_of_triangle(tr1);
    double a2 = area_of_triangle(tr2);
    // round the difference up to the nearest integer
    double area_diff = ceil(a1-a2); 
    return (int)(area_diff);
} 


void sort_by_area(triangle* tr, int n) {
	// use the qsort from the c standard library
    qsort(tr, n, sizeof(*tr), comparator);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}