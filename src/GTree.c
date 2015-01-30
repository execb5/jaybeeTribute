#include <stdlib.h>
#include <GTree.h>

unsigned char beginGTree(void)
{
        nil = malloc(sizeof(*nil));
        if (nil == NULL)
                return 0;
        nil->leftSubTree = nil->rightSubTree = nil;
        nil->level = 0;
        return 1;
}

GTree* makeNode(int data, int level)
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

GTree* insert(GTree* root, int data)
{
        if (root == nil)
                root = makeNode(data, 1);
        else
        {
                if (root->data < data)
                        root->leftSubTree = insert(root->leftSubTree, data);
                else
                        root->rightSubTree = insert(root->rightSubTree, data);
                /*root = skew(root);*/
                /*root = split(root);*/
        }
        return root;
}

void basicPrint(GTree* root)
{
        if (root == nil)
                return;
        basicPrint(root->leftSubTree);
        printf("%d\n", root->data);
        basicPrint(root->rightSubTree);
}
