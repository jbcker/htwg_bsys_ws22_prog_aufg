//
// Created by jonab on 05.12.2022.
//
#include "genstacklib.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define size 100

void genStackNew (genStack *s, int elementSize, void (*freefn)(void*)) {
    s->elementPtr = malloc(elementSize * size);
    s->elementSize = elementSize;
    s->stackSize = 0;
    s->allocSize = size;
    s->freefn = freefn;
}

void genStackDispose (genStack *s) {
    if(s->freefn != NULL) {
        for (int i = 0; i <= s->stackSize; i++) {
            s->freefn((char *) s->elementPtr + i * s->elementSize);
        }
    }
    free(s->elementPtr);
    s->allocSize = 0;
    s->stackSize = 0;
}

bool genStackIsEmpty (const genStack *s) {
    if(s->stackSize == 0) {
        return 1;
    } else
        return 0;
}

void genStackPush (genStack *s, const void *elementAddr) {
    if(s->allocSize == s->stackSize) {
        s->allocSize = s->allocSize * 2;
        s->elementPtr = realloc(s->elementPtr, s->elementSize * s->allocSize);
    }
    memcpy(((char *)s->elementPtr + s->stackSize * s->elementSize), elementAddr, s->elementSize);
    //s->elementPtr[s->stackSize] = *elementAddr;
    s->stackSize++;
}

void genStackPop (genStack *s, void *elementAddr) {
    assert(s->stackSize > 0);
    s->stackSize = s->stackSize - 1;
    memcpy(elementAddr, ((char *)s->elementPtr + s->stackSize * s->elementSize), s->elementSize);
    //s->freefn((char *)s->elementPtr + s->stackSize * s->elementSize);
    //elementAddr = s->elementPtr[s->stackSize];
}

unsigned int genStackSize (genStack * s) {
    return s->stackSize;
}
