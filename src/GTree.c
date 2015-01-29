#include <stdlib.h>
#include <GTree.h>

unsigned char sentinelNode(void)
{
        nil = malloc(sizeof(*nil));
        if (nil == NULL)
                return 0;
        nil->leftSubTree = nil->rightSubTree = nil;
        nil->level = 0;
        return 1;
}

GTree* make_node (int data, int level)
{
        GTree* newNode = malloc(sizeof(*newNode));
        if (newNode == NULL)
                return NULL;
        newNode->data = data;
        newNode->level = level;
        newNode->leftSubTree = newNode->rightSubTree = nil;
        return newNode;
}

GTree* skew(GTree* root)
{
        if (root->level != 0)
        {
                if (root->level == root->leftSubTree->level)
                {
                        GTree* aux = root;
                        root = root->leftSubTree;
                        aux->leftSubTree = root->rightSubTree;
                        root->rightSubTree = aux;
                }
                root->rightSubTree = skew(root->rightSubTree);
        }
        return root;
}

GTree* split(GTree* root)
{
        int lvl = root->level;
        int gchild = root->rightSubTree->rightSubTree->level;
        if(lvl != 0 && lvl == gchild)
        {
                GTree* aux = root;
                root = root->rightSubTree;
                aux->rightSubTree = root->leftSubTree;
                root->leftSubTree = aux;
                root->rightSubTree = split(root->rightSubTree);
        }
        return root;
}
