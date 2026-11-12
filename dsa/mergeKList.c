//merge k sorted lists :)

#include <stdio.h>

#define K 10
#define MAX 100

struct heapNode{
    int val;
    int arrayIdx;
    int elementIdx;
};

typedef struct heapNode hNode;

struct minHeap{
    hNode arr[K];
    int size;
};


int arrays[K][MAX];
int lengths[K];


void swap(hNode *a, hNode *b) {
    hNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct minHeap *h, int i){
    while(i > 0){
        int parent = (i-1)/2;
        if (h->arr[parent].val > h->arr[i].val){
            swap(&h->arr[parent], &h->arr[i]);
        }
        else{
            break;
        }
    }
}

void insert(struct minHeap *h, hNode node){
    if(h->size == K){
        printf("heap full\n");
        return;
    }
    int i = h->size;
    h->arr[i] = node;
    h->size++;

    heapifyUp(h, i);
    return;
}

void heapifyDown(struct minHeap *h, int i){
    int smallest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < h->size && h->arr[l].val < h->arr[smallest].val){
        smallest = l;
    }

    if(r < h->size &&h->arr[r].val < h->arr[smallest].val){
        smallest = r;
    }

    if (smallest != i){
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

hNode extractMin(struct minHeap *h){
    hNode min = h->arr[0];

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    if(h->size > 0){
        heapifyDown(h, 0);
    }

    return min;
}

void mergeLists(int k){
    struct minHeap h;
    h.size = 0;

    int result[K*MAX];
    int count = 0;

    //add first element from each list
    for(int i=0; i<k; i++){
        if(lengths[i] > 0){
            hNode node;
            node.val = arrays[i][0];
            node.arrayIdx = i;
            node.elementIdx = 0;

            insert(&h, node);
        }
    }

    //repeated extraction of min element and merging
    while(h.size > 0){
        hNode min = extractMin(&h);

        int a = min.arrayIdx;
        int next = min.elementIdx + 1;

        result[count++] = min.val;

        if (next < lengths[a]){
            hNode newNode;
            newNode.arrayIdx = a;
            newNode.elementIdx = next;
            newNode.val = arrays[a][next];

            insert(&h, newNode);
        }
    }


    printf("\nMerged sorted array:\n");
    
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
    
        printf("\n");

    
}
