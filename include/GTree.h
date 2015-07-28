#include <stdlib.h>
#include <string.h>

typedef struct GTree{
        int level;
        int data;
        struct GTree* leftSubTree;
        struct GTree* rightSubTree;
} GTree;

GTree* nil;


GTree* initialize(void);
GTree* makeNode (int data, int level);


GTree* insertNode(GTree* root, int data);
GTree* contains(GTree* root, int data);
GTree* removeNode(GTree* root, int data);
void basicPrint(GTree* root);
GTree* skew(GTree* root);
GTree* split(GTree* root);
GTree* find(GTree* root, int data);
void cutePrint(GTree* root, char* space);
void destroy(GTree* root);
void destroySentinel(void);
