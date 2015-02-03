#include <GTree.h>

GTree* initialize(void)
{
        if (nil != NULL)
                return nil;
        nil = malloc(sizeof(*nil));
        nil->leftSubTree = nil->rightSubTree = nil;
        nil->level = 0;
        return nil;
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
                ++root->level;
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
                if (data < root->data)
                        root->leftSubTree = insert(root->leftSubTree, data);
                else
                        root->rightSubTree = insert(root->rightSubTree, data);
                root = skew(root);
                root = split(root);
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
void cutePrint(GTree* root, char* space)
{
        if (root == nil)
                return;
        char aux[256]="";
        strcpy(aux, space);
        strcat(aux, "-+");
        cutePrint(root->leftSubTree, aux);
        printf("%s%d\n", space, root->data);
        cutePrint(root->rightSubTree, aux);
}
GTree* find(GTree* root, int data)
{
        if (root == nil || data == root->data)
                return root;
        if (data < root->data)
                return find(root->leftSubTree, data);
        return find(root->rightSubTree, data);
}
