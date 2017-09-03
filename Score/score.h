#ifndef SCORE_H
#define SCORE_H

typedef struct student {
    char num[10];
    char name[15];
    int Chinese;
    int English;
    int Math;
    int total;
    float average;
    int rank;
};

typedef struct node {
    student student data;
    struct node *next;
} Node, *Link;

void printHeader();
void printStudent(Node *student);
void stringInput(char *string, int length, char *notice);

/* input score between [0,100]  */
int numberInput(char *notice);

#endif
