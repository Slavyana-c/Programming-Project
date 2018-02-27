#include "stdio.h"
#include "math.h"
#include "stdlib.h"

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent, int maxLvl );
void growTree( Node *node, int maxLvl );
