#include <GTree.h>

int main(int argc, const char *argv[])
{
        GTree* g;
        g = initialize();
        g = insert(g, 1);
        g = insert(g, 5);
        g = insert(g, 3);
        g = insert(g, 9);
        g = insert(g, 1);
        g = insert(g, 15);
        g = insert(g, 2);
        g = insert(g, 9);
        g = insert(g, 11);
        g = insert(g, 30);
        g = insert(g, -7);
        g = insert(g, 48);
        basicPrint(g);
        return 0;
}
