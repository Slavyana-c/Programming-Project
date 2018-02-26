
#include "stdio.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "test.h"

// main

int main( int argc, char **argv ) {

    Node *head;
    head = makeNode( 0.0,0.0, 0 );

    int task = 0;
    int test = 0;

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
                if(test < 1 || test > 2) printf("Invalid number.\nPlease select 1-2.");
            }
            task1(head, test);

            break;

        case 2:
            printf("Please select a test (1-2):\n1.Grow a full Level 3 tree from a full Level 2 tree\n"
                           "2.Grow a level 4 tree from a non-uniform Level 3 tree that you define.\n");

            while(test < 1 || test > 2) {
                scanf("%d", &test);
                if(test < 1 || test > 2) printf("Invalid number.\nPlease select 1-2.");
            }
            task2(head, test);
            break;

        case 3:
            printf("Please select a test (1-2):\n1.Grow a full Level n tree.\n"
                           "2.Set a limit on tree level and grow a full Level n tree.\n");
            while(test < 1 || test > 2) {
                scanf("%d", &test);
                if(test < 1 || test > 2) printf("Invalid number.\nPlease select 1-2.");
            }
            task3(head, test);

            break;

        case 4:
            printf("Please select a test (1-3):\n1.Tolerance = 0.5, Choice = 0.\n"
                           "2.Tolerance = 0.2, choice = 1.\n 3.Custom tolerance and choice.");
            while(test < 1 || test > 3) {
                scanf("%d", &test);
                if(test < 1 || test > 3) printf("Invalid number.\nPlease select 1-3.");
            }
            task3(head, test);

    }

    writeTree( head );

    destroyTree(head);

    printf("Program completed.\n");

    return 0;
}
