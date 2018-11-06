#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

// Complete the dynamicArray function below.

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */

// struct that defines a node in a linked list
typedef struct linklist{
    int data; 
    struct linklist* next;
} linknode, *linklistp;

// struct that defines individual sequence of nodes
typedef struct {
    linklistp head; // head node of the sequence
    int size; // size of the sequence
} sequence;

// inserts new node a the tail of the sequence 
linklistp insert_tail(linklistp head, linklistp newnode){
    if(head == NULL){
        head = newnode;
    } else{
        // move to the last node in the sequence
        linklistp temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        // attach newnode to the back
        newnode -> next = NULL;
        temp -> next = newnode;
    }
    return head;
}

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    // sequence array of size n
    sequence* s = NULL;
    s = (sequence*)malloc(n * sizeof(sequence));
    // initialize every sequence to zero
    for(int i=0; i<n; i++){
        sequence* seq = (sequence*)malloc(sizeof(sequence));
        seq -> head = NULL;
        seq -> size = 0;
        s[i] = *seq;
    }
    // allocate the memory for the result array
    int* result = (int*)malloc(sizeof(int));
    int result_index = 0;
    // initialize last answer to zero
    int last_answer = 0;
    // traverse through the queries
    for(int i=0; i<queries_rows; i++){
        /* access elements of queries 
        * via pointer *(*(queries + i) + j)
        * where i is row and j is column number
        * there are only 3 columns */
        int type = *(*(queries + i) + 0);
        int x = *(*(queries + i) + 1);
        int y = *(*(queries + i) + 2);
        // calculate index j
        int j = (x^last_answer)%n;
        if(type == 1){ // add y to the tail of j-th sequence
            // prepare the node to be inserted
            linklistp node = malloc(sizeof(linknode));
            node -> data = y;
            node -> next = NULL;
            // increment the size of the j-th sequence
            s[j].size++;
            // insert the node at the tail of the j-th sequence
            s[j].head = insert_tail(s[j].head, node);
        } else if(type == 2){
            // the index at which new last_answer is located
            int index = y % (s[j].size);
            // move to the position in the sequence
            linklistp temp = s[j].head;
            while(index > 0){
                temp = temp -> next;
                index--;
            }
            last_answer = temp -> data;
            // save the last_answer to the result array
            *(result + result_index) = last_answer;
            result_index++;
            result = (int*)realloc(result, (result_index+1) * sizeof(int));
        }
    }
    *result_count = result_index;
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nq = split_string(rtrim(readline()));

    char* n_endptr;
    char* n_str = nq[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = nq[1];
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    int** queries = malloc(q * sizeof(int*));

    for (int i = 0; i < q; i++) {
        *(queries + i) = malloc(3 * (sizeof(int)));

        char** queries_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            char* queries_item_endptr;
            char* queries_item_str = *(queries_item_temp + j);
            int queries_item = strtol(queries_item_str, &queries_item_endptr, 10);

            if (queries_item_endptr == queries_item_str || *queries_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(queries + i) + j) = queries_item;
        }
    }

    int queries_rows = q;
    int queries_columns = 3;

    int result_count;
    int* result = dynamicArray(n, queries_rows, queries_columns, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}