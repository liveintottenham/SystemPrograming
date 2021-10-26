
#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node {
    char *name;
    int mid_score;
    int end_score;
  };

struct node *root = NULL;

int compare(const void *cp1, const void *cp2){
  return strcmp(((struct node *)cp1)->name,
		((struct node *)cp2)->name);
}

void print_node(const void *nodeptr, VISIT order, int level){
  if (order == preorder || order == leaf)
    printf("\n name : %-20s\n Middle Test score : %d\n Final Test score : %d\n",
	   (*(struct node **)nodeptr)->name,
	   (*(struct node **)nodeptr)->mid_score,
	   (*(struct node **)nodeptr)->end_score);
}

void main(){
  struct node **ret;
  int student, i=0;
  
  printf("Please enter the number of students  : ");
  scanf("%d",&student);
  printf("\n");

  char nametable[student];
  struct node nodetable[student];

  char *nameptr = nametable;
  struct node *nodeptr = nodetable;

  nodeptr = (struct node*)malloc(sizeof(struct node));
  
  while (scanf("%s %d %d", nameptr,
	       &nodeptr->mid_score,
	       &nodeptr->end_score) != EOF && i++ < student){
    nodeptr->name = nameptr;

    ret = (struct node**)tsearch((void *)nodeptr, (void **)&root, compare);

    printf("\"%s\"'s ", (*ret)->name);
    if (*ret == nodeptr)
      printf("added to the tree. \n\n");
    else
      printf("already exists in the tree. \n\n");
    nameptr += strlen(nameptr) + i;
    nodeptr++;
  }
  twalk((void *)root, print_node);

  free(nodeptr);
  
}
