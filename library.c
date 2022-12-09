#include "library.h"

#include <stdio.h>
bool bstTest(){
    bst* t = bstInit(100);
    bstSet(t, 198);
    bstSet(t, 56);
    printf("%s\n", bstExists(t, 198) ? "true" : "false");
    bstPrint(t);
    bstDelete(t, 56);
    bstPrint(t);

    return true;
}
int main(void) {
    bstTest();
    return 0;
}


