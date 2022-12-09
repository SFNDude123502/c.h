#include "library.h"

#include <stdio.h>
bool bstTest(){
    bst* t = bstInit(100);
    bstSet(t, 198);
    bstSet(t, 56);
    printf("%s\n", bstExists(t, 198) ? "true" : "false");
    bstPrint(t);
    bstNode** iter = bstIterate(t);
    for (int i=0;i<len(iter);i++){
        printf("%p\n", iter[i]);
    }
    bstDelete(t, 56);
    bstPrint(t);

    return true;
}
bool omapTest(){
    omap* o = omapInit(&"100", 100);
    omapSet(o, &"198", 198);
    omapSet(o, &"56", 56);
    printf("%d\n", omapGet(o, &"198"));
    omapPrint(o);
    omapDelete(o, &"56");
    omapPrint(o);
}
int main(void) {
    omapTest();
    return 0;
}


