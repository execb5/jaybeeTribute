typedef struct GTree{
        int level;
        int data;
        struct GTree* leftSubTree;
        struct GTree* rightSubTree;
} GTree;

GTree* insert(GTree* root, int data);
GTree* contains(GTree* root, int data);
GTree* delete(GTree* root, int data);
void print(GTree* root);
GTree* skew(GTree* root);
GTree* split(GTree* root);
