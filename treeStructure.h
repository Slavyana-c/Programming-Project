#include "stdio.h"
#include "math.h"
#include "stdlib.h"


struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
};
typedef struct qnode Node;
