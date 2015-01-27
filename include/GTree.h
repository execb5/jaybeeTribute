#include <bool.h>

typedef struct {
        int level;
        void* data;
        GTree* leftSubTree;
        GTree* rightSubTree;
} GTree;

void* insert(GTree* tree, void* data);
void* contains(GTree* tree, void* data);
bool* insert(GTree* tree, void* data);
void* insert(GTree* tree, void* data);
