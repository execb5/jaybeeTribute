#include <bool.h>

typedef struct {
    void* data;
    Node* leftNode;
    Node* rightNode;
} Node;

typedef struct {
    Node* root;
} GTree;

void* insert(GTree* tree, void* data);
void* contains(GTree* tree, void* data);
bool* insert(GTree* tree, void* data);
void* insert(GTree* tree, void* data);


