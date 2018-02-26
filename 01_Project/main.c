
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

    int task = 0;
    int test = 0;
    int maxLvl;
    int n;

    printf("Please select a task (1-4):\n1.Destroy the tree\n"
    "2.Growing the Quadtree\n3.A limit on tree level"
    "\n4.Generating a data-dependent Quadtree\n");

    while(task < 1 || task > 4) {
        scanf("%d", &task);
        if(task < 1 || task > 4) printf("Invalid number.\nPlease select 1-4.");
    }

    switch (task) {
        case 1:
            printf("Please select a test (1-2):\n1.A full tree at Level 2\n"
                           "2.A non-uniform Level 3 tree that you define.\n");
            while(test < 1 || test > 2) {
                scanf("%d", &test);
                if(test < 1 || test > 4) printf("Invalid number.\nPlease select 1-2.");
            }
            task1(head, test);

            break;

        case 2:
            printf("Please select a test (1-2):\n1.Grow a full Level 3 tree from a full Level 2 tree\n"
                           "2.Grow a level 4 tree from a non-uniform Level 3 tree that you define.\n");

            while(test < 1 || test > 2) {
                scanf("%d", &test);
                if(test < 1 || test > 4) printf("Invalid number.\nPlease select 1-2.");
            }
            task2(head, test);
            break;

        case 3:
            printf("Please select a test (1-2):\n1.Grow a full Level n tree.\n"
                           "2.Set a limit on tree level and grow a full Level n tree.\n");
            while(test < 1 || test > 2) {
                scanf("%d", &test);
                if(test < 1 || test > 4) printf("Invalid number.\nPlease select 1-2.");
            }
            task3(head, test);

            break;
    }


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
    printf("Done.");

    return 0;
}
