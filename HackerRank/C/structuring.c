#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

/****************TODO************************/
void add_word(struct sentence *sen, char *data) {
    struct word *word = malloc(sizeof(struct word));
    word->data = data;

    sen->data = (struct word *) realloc(sen->data, sizeof(struct word) * (sen->word_count + 1));
    sen->data[sen->word_count] = *word;
    sen->word_count++;
}

void add_sentence(struct paragraph *par, char *data) {
    size_t offs = 0;
    size_t size = strlen(data);

    struct sentence *sen = malloc(sizeof(struct sentence));
    sen->data = NULL;
    sen->word_count = 0;

    while (offs < size) {
        char *s = strchr(data + offs, ' ');
        size_t len = s == NULL ? size - offs : s - data - offs;

        char *word = malloc((len + 1) * sizeof(char));
        memset(word, '\0', (len + 1) * sizeof(char));
        strncpy(word, data + offs, len);

        add_word(sen, word);
        offs += len + 1;
    }

    par->data = (struct sentence *) realloc(par->data, sizeof(struct sentence) * (par->sentence_count + 1));
    par->data[par->sentence_count] = *sen;
    par->sentence_count++;
}

// helper function that adds paragraph (data) to the document
void add_paragraph(struct document* doc, char* data) {
	// offset value to keep track of where we are in the paragraph
    size_t offs = 0;
    // length of the paragraph
    size_t size = strlen(data);

    // initialize the paragraph
    struct paragraph *par = malloc(sizeof(struct paragraph));
    par->data = NULL;
    par->sentence_count = 0;

    // repeate until we reach the end of the paragraph
    while (offs < size) {
    	// pointer to the first occurance of period (sentence delimiter)
        char *s = strchr(data + offs, '.');
        // adjust the len accordingly
        size_t len = s == NULL ? size - offs : s - data - offs;

        // initialize the sentence
        char *sentence = malloc((len + 1) * sizeof(char));
        // set all characters in the sentence to '\0'
        memset(sentence, '\0', (len + 1) * sizeof(char));
        // copy up to len characters from (paragraph + offset) to sentence
        strncpy(sentence, data + offs, len);

        // add sentence to the paragraph
        add_sentence(par, sentence);
        // increment offset accordingly
        offs += len + 1;
    }

    // resize the document data field (add paragraph to the document)
    doc->data = (struct paragraph *) realloc(doc->data, sizeof(struct paragraph) * (doc->paragraph_count + 1));
    doc->data[doc->paragraph_count] = *par;
    doc->paragraph_count++;
}

struct document get_document(char* text) {
	// initialize the document
    struct document* doc = malloc(sizeof(struct document));
    doc->data = NULL;
    doc->paragraph_count = 0;

    size_t offs = 0; /* offset of where we are in the text */
    size_t size = strlen(text); /*length of the string up to but not including terminating null character '\0'*/

    while (offs < size) {
    	// pointer to the first occurance of newline character '\n'
        char *s = strchr(text + offs, '\n');
        // adjust the length of the paragraph accordingly
        size_t len = s == NULL ? size - offs : s - text - offs;

        // allocate the memory for the paragraph
        char *paragraph = malloc((len + 1) * sizeof(char));
        // set the characters in paragraph to '\0'
        memset(paragraph, '\0', (len + 1) * sizeof(char));
        // copy up to len characters from (text + offs) into paragraph
        strncpy(paragraph, text + offs, len);

        // add the paragraph to the document
        add_paragraph(doc, paragraph);
        // move the offset
        offs += len + 1;
    }

    return *doc;

}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
	return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
	return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
	return Doc.data[k-1];
}
/****************TODO************************/

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}