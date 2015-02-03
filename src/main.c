#include <GTree.h>

int main(int argc, const char *argv[])
{
        GTree* g;
        g = initialize();
        g = insert(g, 2);
        g = insert(g, 5);
        g = insert(g, 4);
        g = insert(g, 7);
        g = insert(g, 6);
        g = insert(g, 3);
        g = insert(g, 8);
        g = insert(g, 10);
        g = insert(g, 9);
        g = insert(g, 1);
        cutePrint(g, "");
        g = remove(g, 10);
        printf("\n-------------------\n\n");
        cutePrint(g, "");
        return 0;
}
