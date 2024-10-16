#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int elems[MAX];
    int count;
} MinHeap;

void initMinHeap(MinHeap *m){
    m->count = 0;
}

bool insert(MinHeap *m, int num);
bool delete(MinHeap *m);
void display(MinHeap m);

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    MinHeap m;
    initMinHeap(&m);
    
    insert(&m, 69);
    insert(&m, 7);
    insert(&m, 25);
    insert(&m, 19);
    insert(&m, 40);
    
    insert(&m, 9);
    insert(&m, 17);
    insert(&m, 15);
    insert(&m, 21);
    insert(&m, 44);
    
    display(m);
    
    delete(&m);
    display(m);
    
    delete(&m);
    display(m);
    
    delete(&m);
    display(m);
    
    delete(&m);
    display(m);
    
    delete(&m);
    display(m);
}


bool insert(MinHeap *m, int num){
    // Swapping Implementation
    // m->elems[m->count]=num;
    
    // int i = m->count;
    // while (m->elems[i] < m->elems[(i-1)/2]){
    //     swap(&m->elems[i], &m->elems[(i-1)/2]);
    //     i = (i-1)/2;
    // }
    
    // ++m->count;
    
    // Proper Implementation
    if (m->count < MAX){
        int i;
        for (i=m->count;i>0 && num < m->elems[(i-1)/2];i = (i-1)/2){
            m->elems[i] = m->elems[(i-1)/2];
        }
        m->elems[i] = num;
        m->count++;
        return true;
    }
    return false;
}

bool delete(MinHeap *m){
    int i;
    --m->count;
    for (i=0;i<m->count;i = (m->elems[(i*2)+1] < m->elems[(i*2)+2]) ? (i*2)+1 : (i*2)+2){
        m->elems[i] = (m->elems[(i*2)+1] < m->elems[(i*2)+2]) ? m->elems[(i*2)+1]: m->elems[(i*2)+2];
        if (m->elems[i] < m->elems[(i-1)/2]){
            m->elems[i] = m->elems[m->count];
        }
    }
    return true;
}

void display(MinHeap m){
    printf("\n{");
    for (int i=0;i<m.count;++i){
        printf("%d", m.elems[i]);
        if (i<m.count-1){
            printf(", ");
        }
    }
    printf("}");
}