#include <bool.h>

typedef struct {
        int level;
        int data;
        GTree* leftSubTree;
        GTree* rightSubTree;
} GTree;

GTree* insert(GTree* tree, int data);
Gtree* contains(GTree* tree, int data);
Gtree* delete(GTree* tree, int data);
void print(GTree* tree);
