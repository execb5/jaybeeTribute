#include <GTree.h>

int main(int argc, const char *argv[])
{
        GTree* g;
        g = initialize();
        int i = 1;
        while (i <= 15)
        {
                g = insert(g, i);
                cutePrint(g, "");
                printf("\n-------------------\n\n");
                i++;
        }
        g = remove(g, 15);
        cutePrint(g, "");
        printf("\n-------------------\n\n");
        g = remove(g, 13);
        cutePrint(g, "");
        printf("\n-------------------\n\n");
        g = remove(g, 4);
        cutePrint(g, "");
        printf("\n-------------------\n\n");
        destroy(g);
        destroySentinel();
        return 0;
}
