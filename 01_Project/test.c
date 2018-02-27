#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"

#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "valueTree.h"

void task1(Node *head, int testNum) {

    makeChildren( head, 5 );
    int i;

    switch (testNum) {
        // Creates a full tree of Lvl 2
        case 1:
            for ( i = 0; i < 4; i++) {
                makeChildren( head->child[i], 5 );
            }
            break;

        // Creates a tree of Lvl 3
        case 2:
            makeChildren(head->child[0], 5);
            makeChildren(head->child[2], 5);
            makeChildren( (head->child[0]) -> child[1], 5);
            makeChildren( (head->child[2]) -> child[3], 5 );
            break;
    }

}

// Grows the quadtree

void task2(Node *node, int testNum) {
    switch (testNum) {
        // Grows a full lvl 3 tree
        case 1:
            task1(node, 1);
            growTree(node, 5);
            break;

        // Grows a full lvl 4 tree
        case 2:
            task1(node, 2);
            growTree(node, 5);
            break;

    }
}

// A limit on tree level

void task3(Node *node, int testNum) {
    int n, maxLvl;
    int i;

    switch (testNum) {
        // Grows a full lvl n tree
        case 1:
            printf("n = ");
            scanf("%d", &n);


            for (i = 0; i < n; ++i) {
                growTree(node, n);
            }
            break;

        // level 3 limit
        case 2:

            task1(node, 2); // level 3 tree
            growTree(node, 3);

            break;

         // level 4 limit
        case 3:

            task1(node, 2); // level 3 tree
            growTree(node, 4);

            break;

         // Grows a full lvl n tree with a set limit
        case 4:
            printf("n = ");
            scanf("%d", &n);
            printf("level limit = ");
            scanf("%d", &maxLvl);

            for (i = 0; i < n; ++i) {
                growTree(node, maxLvl);
            }

            break;

    }
}

// Data-dependent Quadtree

void task4(Node *node, int testNum) {
    task1(node, 1); // full lvl 2 tree

    double tolerance = 0.0;
    int choice = 0;

    switch (testNum) {

        case 1:
            check(node, 0.5, 0);
            break;

        case 2:
            check(node, 0.2, 1);
            break;
        case 3:

            printf("tolerance = ");
            scanf("%lf", &tolerance);
            printf("choice = ");
            scanf("%d", &choice);
            check(node, tolerance, choice);

    }
}


