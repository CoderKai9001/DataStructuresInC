#include <stdio.h>
#include <stdlib.h>

typedef long long int lint;

typedef struct heap {
    lint* heaparr;
    lint size;
} Heap;

Heap* createheap(lint max) {
    Heap* mh = (Heap*)malloc(sizeof(Heap));
    mh->size = 0;
    mh->heaparr = (lint*)malloc(sizeof(lint)*max);
    return mh;
}
 
void swap(lint* a, lint* b) {
    lint temp = *a;
    *a = *b;
    *b = temp;
}

lint left(lint i) {return (i*2)+1;}
lint right(lint i) {return (i*2)+2;}
lint parent(lint i) {return (i-1)/2;}

//use this heapify for a minheap structure:

void heapify(Heap* mh, lint idx) {
    lint l = left(idx);
    lint r = right(idx);
    lint minimum = idx;
    if(l < mh->size && mh->heaparr[l] < mh->heaparr[minimum]) minimum = l;
    if(r < mh->size && mh->heaparr[r] < mh->heaparr[minimum]) minimum = r;
    if(minimum != idx) {
        swap(&mh->heaparr[minimum], &mh->heaparr[idx]);
        heapify(mh, minimum);
    }
}

//use this heapify for a maxheap structure:

// void heapify(Heap* mh, lint idx) {
//     lint l = left(idx);
//     lint r = right(idx);
//     lint maximum = idx;
//     if(l < mh->size && mh->heaparr[l] > mh->heaparr[maximum]) maximum = l;
//     if(r < mh->size && mh->heaparr[r] > mh->heaparr[maximum]) maximum = r;
//     if(maximum != idx) {
//         swap(&mh->heaparr[maximum], &mh->heaparr[idx]);
//         heapify(mh, maximum);
//     }
// }

void ConvertToHeap(Heap* mh) {
    lint i = (mh->size/2)-1;
    while(i >= 0) {
        heapify(mh, i);
        i--;
    }
}

void InsertToHeap(Heap* mH, int val) {
    if(mH->size == 0) {
        mH->size++;
        mH->heaparr[0] = val;
        return;
    } else {
        mH->size ++;
        mH->heaparr[(mH->size)-1] = val;
        int i = (mH->size)-1;
        while(i != 0 && mH->heaparr[parent(i)] > mH->heaparr[i]) {
            swap(&mH->heaparr[parent(i)], &mH->heaparr[i]);
            i = parent(i);
        }
    }
}

void heapsort(Heap* mh) {
    lint size = mh->size;
    ConvertToHeap(mh);
    for(lint i = 0; i < size; i++) {
        swap(&mh->heaparr[0], &mh->heaparr[mh->size-1]);
        mh->size--;
        heapify(mh, 0);
    }
    mh->size = size;
}

int main() {
    Heap* mh = createheap(100);
    mh->heaparr[0] = 1;
    mh->heaparr[1] = 10;
    mh->heaparr[2] = 5;
    mh->heaparr[3] = 7;
    mh->heaparr[4] = 2;
    mh->heaparr[5] = 99;
    mh->size = 6;
    heapsort(mh);
    for(lint i = 0; i < mh->size; i++) {
        printf("%lld ", mh->heaparr[i]);
    }
}
