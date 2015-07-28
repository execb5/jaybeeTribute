#include <stdio.h>
#include <GTree.h>

GTree*
initialize(void)
{
        if (nil != NULL)
                return nil;
        nil = malloc(sizeof(*nil));
        nil->leftSubTree = nil->rightSubTree = nil;
        nil->level = 0;
        return nil;
}

GTree*
makeNode(int data, int level)
{
        GTree* newNode = malloc(sizeof(*newNode));
        if (newNode == NULL)
                return NULL;
        newNode->data = data;
        newNode->level = level;
        newNode->leftSubTree = newNode->rightSubTree = nil;
        return newNode;
}

GTree*
skew(GTree* root)
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

GTree*
split(GTree* root)
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

GTree*
insertNode(GTree* root, int data)
{
        if (root == nil)
                root = makeNode(data, 1);
        else
        {
                if (data < root->data)
                        root->leftSubTree = insertNode(root->leftSubTree, data);
                else
                        root->rightSubTree = insertNode(root->rightSubTree, data);
                root = skew(root);
                root = split(root);
        }
        return root;
}


void
basicPrint(GTree* root)
{
        if (root == nil)
                return;
        basicPrint(root->leftSubTree);
        printf("%d\n", root->data);
        basicPrint(root->rightSubTree);
}

void
cutePrint(GTree* root, char* space)
{
        if (root == nil)
                return;
        char aux[256]="";
        strcpy(aux, space);
        strcat(aux, "-+");
        cutePrint(root->leftSubTree, aux);
        printf("%s%d,%d\n", space, root->data, root->level);
        cutePrint(root->rightSubTree, aux);
}
void 
awesomePrint(GTree* root)
{
        printf("%d\n", root->data);        
}

GTree*
findNode(GTree* root, int data)
{
        if (root == nil || data == root->data)
                return root;
        if (data < root->data)
                return findNode(root->leftSubTree, data);
        return findNode(root->rightSubTree, data);
}

GTree*
removeNode(GTree* root, int data)
{
        if (root != nil)
        {
                if (data == root->data)
                {
                        if (root->leftSubTree != nil && root->rightSubTree != nil)
                        {
                                GTree* successor = root->leftSubTree;
                                while (successor->rightSubTree != nil)
                                        successor = successor->rightSubTree;
                                root->data = successor->data;
                                root->leftSubTree = removeNode(root->leftSubTree, root->data);
                        }
                        else
                        {
                                GTree* aux = root;
                                if (root->leftSubTree == nil)
                                        root = root->rightSubTree;
                                else
                                        root = root->leftSubTree;
                                free(aux);
                        }
                }
                else
                {
                        if (data > root->data)
                                root->rightSubTree = removeNode(root->rightSubTree, data);
                        else
                                root->leftSubTree = removeNode(root->leftSubTree, data);
                }
        }
        if (root->leftSubTree->level < root->level - 1 || root->rightSubTree->level < root->level - 1)
        {
                if (root->rightSubTree->level > --root->level)
                        root->rightSubTree->level = root->level;
                root = skew(root);
                root = split(root);
        }
        return root; 
}

void
destroy(GTree* root)
{
        if (root == nil)
                return;
        destroy(root->rightSubTree);
        destroy(root->leftSubTree);
        free(root);
}

void
destroySentinel(void)
{
        free(nil);
}
