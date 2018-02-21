#include "stdio.h"
#include "math.h"
#include "stdlib.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"

void task1(Node *head, int testNum) {

  makeChildren( head );
  int i;

  switch (testNum) {
    // Creates a full tree of Lvl 2
    case 1:
    for ( i = 0; i < 4; i++) {
      makeChildren( head->child[i] );
    }
    break;

    case 2:
    makeChildren(head->child[0]);
    makeChildren(head->child[2]);
    makeChildren( (head->child[0]) -> child[1]);
    makeChildren( (head->child[2]) -> child[3] );

  }

}

void task2(Node *node, int testNum) {
  switch (testNum) {
    case 1:
    task1(node, 1);
    growTree(node, 4);
    break;

    case 2:
    task1(node, 2);
    growTree(node, 4);
    break;

  }
}

void task3() {

}

void task4() {

}

void task5() {

}
