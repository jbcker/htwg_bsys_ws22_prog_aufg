//
// Created by jonab on 07.11.2022.
//

#include "ulstack.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define size 100

void ulStackNew (ulstack * s) {
    s->elementPtr = malloc(sizeof(unsigned long)*size);
    s->allocSize = size;
    s->stackSize = 0;
}

void ulStackDispose (ulstack * s) {
    free(s->elementPtr);
    s->allocSize = 0;
    s->stackSize = 0;
}

void ulStackPush (ulstack * s, unsigned long value) {
    if(s->allocSize == s->stackSize) {
        s->allocSize = s->allocSize * 2;
        s->elementPtr = realloc(s->elementPtr, sizeof(unsigned long) * s->allocSize);
    }
    s->elementPtr[s->stackSize] = value;
    s->stackSize++;
}

unsigned long ulStackPop (ulstack * s) {
    assert(s->stackSize > 0);
    s->stackSize = s->stackSize - 1;
    return s->elementPtr[s->stackSize];
}

unsigned int ulStackSize (ulstack * s) {
    return s->stackSize;
}
