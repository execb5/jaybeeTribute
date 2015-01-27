typedef struct GTree{
        int level;
        void* data;
        struct GTree* leftSubTree;
        struct GTree* rightSubTree;
} GTree;

GTree* insert(GTree* tree, void* data);
GTree* contains(GTree* tree, void* data);
GTree* insert(GTree* tree, void* data);
GTree* skew(GTree* root);
GTree* split(GTree* root);
