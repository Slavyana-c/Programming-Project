
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "test.h"
#include  "valueTree.h"

// main

int main( int argc, char **argv ) {

  Node *head;
  head = makeNode( 0.0,0.0, 0 );
  growTree(head,5);
  growTree(head,5);

  check(head);

  //task1(head, 2);
  //task2(head, 2);

  // make the head node
  //head = makeNode( 0.0,0.0, 0 );

  // make a tree

//  makeChildren( head );


//  makeChildren( head->child[1] );
//  makeChildren( head->child[2] );
  //makeChildren( (head->child[2]) -> child[3] );

//  int i;
//  for (i = 0; i < 5; i++) {
//    growTree(head, 3);
//  }



//  growTree(head,2);
//  growTree(head,2);



  // print the tree for Gnuplot
	writeTree( head );

  destroyTree(head);

  return 0;
}
