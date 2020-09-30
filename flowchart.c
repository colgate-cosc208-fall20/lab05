#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *description;
    struct node *yes;
    struct node *no;
};

struct node *create(char *description) {
    struct node *x = malloc(sizeof(struct node));
    x->description = description;
    return x;
}

void update(struct node x, struct node yes, struct node no) {
    x.yes = &yes;
    x.no = &no;
}

struct node *initialize() {
    // Initialize terminals
    struct node *good = create("Good");
    struct node *listen = create("You need to learn flowcharts.");
    struct node *wait = create("Wait, what?");
    struct node *that = create("That wasn't a question.");

    // Initialize createes
    struct node *understand = create("Do you understand flow charts?");
    struct node *okay_yes = create("Okay. You see the lines labeled 'Yes'?");
    struct node *and_no = create("And you can see the ones labeled 'No'.?");
    struct node *but_twice = create("But you just followed them twice!");
    struct node *but_no = create("But you see the ones labeled 'No'?");
    update(*understand, *good, *okay_yes);
    update(*okay_yes, *and_no, *but_no);
    update(*and_no, *good, *but_twice);
    update(*but_twice, *that, *that);
    update(*but_no, *wait, *listen);

    return understand;
}

struct node *choice(struct node *curr) {
    while(1) {
        printf("PROMPT: %s (y/n) ", curr->description);
        char choice;
        fgets(&choice, 1, stdin);
        if ('y' == choice) {
            return curr->yes;
        }
        else if ('n' == choice) {
            return curr->no;
        }
        else {
            printf("Invalid choice\n");
        }
    }
}

struct node *traverse(struct node *start) {
    struct node *curr = start;
    while (!(NULL == curr->yes && NULL == curr->no)) {
       curr = choice(curr); 
    }
    return curr;
}

int main() {
    struct node *start = initialize();
    struct node *end = traverse(start);
    printf("FINISHED: %s\n", end->description);
}
