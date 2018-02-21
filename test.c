#include "stdio.h"
#include "math.h"
#include "stdlib.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"

void task1(Node *head, int test) {

  makeChildren( head );
  int i;
  for ( i = 0; i < 4; i++) {
    makeChildren( head->child[i] );
  }
  switch (test) {
    // Creates a full tree of Lvl 2
    case 1:
    break;

    case 2:
    makeChildren( (head->child[0]) -> child[1]);
    makeChildren( (head->child[2]) -> child[3] );

  }

}

void task2(Node *node, int test) {

}

void task3() {

}

void task4() {

}

void task5() {

}
