#include "stdio.h"
#include "math.h"
#include "stdlib.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"

// main

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  makeChildren( head );
  makeChildren( head->child[1] );
  makeChildren( head->child[2] );
  makeChildren( (head->child[2]) -> child[3] );

  destroyTree(head);

  // print the tree for Gnuplot
	writeTree( head );

  return 0;
}
