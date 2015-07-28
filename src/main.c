#include <stdio.h>
#include <GTree.h>

int main(int argc, const char *argv[])
{
        GTree* g;
        g = initialize();
        int i = 1;
        while (i <= 15)
        {
                g = insertNode(g, i);
                /*cutePrint(g, "");*/
                /*printf("\n-------------------\n\n");*/
                i++;
        }
        /*g = removeNode(g, 15);*/
        /*cutePrint(g, "");*/
        /*printf("\n-------------------\n\n");*/
        /*g = removeNode(g, 13);*/
        /*cutePrint(g, "");*/
        /*printf("\n-------------------\n\n");*/
        /*g = removeNode(g, 4);*/
        /*cutePrint(g, "");*/
        /*printf("\n-------------------\n\n");*/
        awesomePrint(g);
        destroy(g);
        destroySentinel();
        return 0;
}
