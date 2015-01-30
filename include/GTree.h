#include <stdlib.h>

typedef struct GTree{
        int level;
        int data;
        struct GTree* leftSubTree;
        struct GTree* rightSubTree;
} GTree;

GTree* nil;


unsigned char beginGTree(void);
GTree* makeNode (int data, int level);


GTree* insert(GTree* root, int data);
GTree* contains(GTree* root, int data);
GTree* remove(GTree* root, int data);
void basicPrint(GTree* root);
GTree* skew(GTree* root);
GTree* split(GTree* root);
