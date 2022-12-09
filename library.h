#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#ifndef UNTITLED1_LIBRARY_H
#define UNTITLED1_LIBRARY_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define len(x) (sizeof x / sizeof x[0])

typedef struct bstNode{
    int value;
    struct bstNode* left;
    struct bstNode* right;
    bool ignore;
} bstNode;
typedef struct bst{
    bstNode* root;
    int len;
}bst;
bst* bstInit(int value){
    bstNode* rootNode;
    bst* out;

    rootNode = (bstNode*)malloc(sizeof *rootNode);
    rootNode->value = value;
    rootNode->ignore = false;

    out = (bst*)malloc(sizeof *out);
    out->root = rootNode;
    out->len = 1;

    return out;
}
void bstSet(bst* t, int value){
    bstNode* pos = t->root;
    while (true){
        if (value == pos->value){
            if (pos->ignore){
                pos->ignore = false;
                break;
            }
            pos->ignore = false;
            return;
        }
        if (value < pos->value){
            if (pos->left != NULL){
                pos = pos->left;
                continue;
            }
            bstNode* newNode;
            newNode = (bstNode*)malloc(sizeof *newNode);
            newNode->value = value;
            pos->left = newNode;
            break;
        }else{
            if(pos->right != NULL){
                pos = pos->right;
                continue;
            }
            bstNode* newNode;
            newNode = (bstNode*)malloc(sizeof *newNode);
            newNode->value = value;
            pos->right = newNode;
            break;
        }
    }
    t->len++;
}
bool bstExists(bst* t, int value){
    bool out = false;
    bstNode* pos = t->root;
    while (pos != NULL){
        if (value == pos->value){
            if (!pos->ignore){
                out = true;
            }
            return out;
        }
        else if(value < pos->value){
            pos = pos->left;
        }else{
            pos = pos->right;
        }
    }
    return out;
}
void bstDelete(bst* t, int value){
    bstNode* pos = t->root;
    while (pos != NULL){
        if(value == pos->value){
            pos->ignore = true;
            t->len--;
            return;
        }else if (value < pos->value){
            pos = pos->left;
        }else{
            pos = pos->right;
        }
    }
}
void bstRePrint(bstNode* n){
    if (n == NULL){return;}
    bstRePrint(n->left);

    if (!n->ignore){
        printf("%d, ", n->value);
    }

    bstRePrint(n->right);
}
void bstPrint(bst* t){
    bstRePrint(t->root);
    printf("\n");
}
void bstReIterate(bstNode* n, bstNode** arr){
    if (n == NULL){return;}
    bstReIterate(n->left, arr);

    arr[len(arr)] = n;

    bstReIterate(n->right, arr);
}
bstNode** bstIterate(bst* t){
    bstNode** out = (bstNode**)malloc(t->len * (sizeof *(t->root)));
    bstReIterate(t->root, out);
    return out;
}

bool greaterThan(char* s1, char* s2){
    int i = 0;
    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] > s2[i]) {
            return true;
        }
        else if (s2[i] > s1[i]) {
            return false;
        }
    }
    if (s2[i] != '\0') {
        return false;
    }
    else {
        return true;
    }
}

typedef struct omapNode{
    struct omapNode* left;
    struct omapNode* right;
    char* key;
    int value;
    bool ignore;
}omapNode;
typedef struct omap{
    omapNode* root;
    int len;
}omap;
omap* omapInit( char* key, int value){
    omap* out;
    out = (omap*)malloc(sizeof *out);
    omapNode* newNode;
    newNode = (omapNode*)malloc(sizeof *newNode);
    newNode->key = key;
    newNode->ignore = false;
    newNode->value = value;
    out->root = newNode;
    out->len = 1;
    return out;
}
void omapSet(omap* o, char* key, int value){
    struct omapNode* pos = o->root;
    while (true){
        if (strcmp(key, pos->key) == 0){
            if (pos->ignore){
                pos->ignore = false;
                break;
            }
            pos->ignore = false;
            return;
        }else if (greaterThan(pos->key, key)){
            if (pos->left != NULL){
                pos = pos->left;
                continue;
            }
            omapNode* newNode;
            newNode = (omapNode*)malloc(sizeof *newNode);
            newNode->key = key;
            newNode->value = value;
            pos->left = newNode;
            break;
        }else{
            if(pos->right != NULL){
                pos = pos->right;
                continue;
            }
            omapNode* newNode;
            newNode = (omapNode*)malloc(sizeof *newNode);
            newNode->key = key;
            newNode->value = value;
            pos->right = newNode;
            break;
        }
    }
    o->len++;
}
int omapGet(omap* o, char* key){
    int out = 0;
    omapNode* pos = o->root;
    while (pos != NULL){
        if (strcmp(key, pos->key) == 0){
            if (!pos->ignore){
                out = pos->value;
            }
            break;
        }else if(greaterThan(pos->key, key)){
            pos = pos->left;
        }else{
            pos = pos->right;
        }
    }
    return out;
}
void omapDelete(omap* o, char* key){
    omapNode* pos = o->root;
    while (pos != NULL){
        if(strcmp(key, pos->key) == 0){
            pos->ignore = true;
            o->len--;
            return;
        }else if (greaterThan(pos->key, key)){
            pos = pos->left;
        }else{
            pos = pos->right;
        }
    }
}
void omapReIterate(omapNode* pos, omapNode** out){
    if (pos == NULL){
        return;
    }
    omapReIterate(pos->left, out);

    out[len(out)] = pos;
    printf("[%s:%d]", pos->key, pos->value);


    omapReIterate(pos->right, out);
}
omapNode** omapIterable(omap* o){
    omapNode** out;
    out = (omapNode**)calloc(o->len, sizeof *(o->root));
    omapReIterate(o->root, out);
    printf("%p\n", out[0]);
    return out;
}
void omapPrint(omap* o) {
    omapNode** iter = omapIterable(o);
    printf("%p\n", iter);
	for (int i = 0; i < len(iter);i++) {
        printf("%p\n", (iter[0]));
		printf("[%s:%d]", (iter[i])->key, (*iter)[i].value);
	}
	printf("\n");
}

#endif //UNTITLED1_LIBRARY_H


#pragma clang diagnostic pop