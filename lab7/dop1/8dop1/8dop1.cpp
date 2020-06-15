/*Разработать функции работы с приоритетной очередью. Постановка запросов в очередь выполняется по приоритету,
снятие  подряд из младших адресов (начало очереди). Приоритет: минимальное значение числового параметра,
при совпадении параметров  LIFO.*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _node {
    struct _node* next;
    int val;
} node;

typedef struct {
    node* lst;
} pqueue;

inline void pqueue_init(pqueue* pq) { pq->lst = NULL; }
inline  int pqueue_top(pqueue* pq) { return pq->lst->val; }
inline  int pqueue_empty(pqueue* pq) { return (pq->lst == NULL); }

int  pqueue_push(pqueue* pq, int val);
void pqueue_pop(pqueue* pq);
void pqueue_clear(pqueue* pq);

int main(void) {
    int    i;
    pqueue pq;
    pqueue_init(&pq);
    for (i = 0; i < 10; ++i)
        pqueue_push(&pq, rand() % 10);

    pqueue_push(&pq, 100);
    pqueue_push(&pq, -100);

    while (!pqueue_empty(&pq)) {
        printf("%d ", pqueue_top(&pq));
        pqueue_pop(&pq);
    }
    return 0;
}

//вставка
int pqueue_push(pqueue* pq, int val) {
    node* p, * i, ** q = &pq->lst;
    for (i = pq->lst; (i != NULL) && (i->val > val); ) {
        q = &i->next;
        i = i->next;
    }

    p = (node*)malloc(sizeof(node));
    if (p != NULL) {
        p->val = val;
        p->next = i;

        if (pq->lst == NULL)
            pq->lst = p;
        else
            *q = p;
    }
    return (p != NULL);
}

//вытолкнуть макс
void pqueue_pop(pqueue* pq) {
    node* t;
    if (pq->lst != NULL) {
        t = pq->lst;
        pq->lst = pq->lst->next;
        free(t);
    }
}

//удаление у всех
void pqueue_clear(pqueue* pq) {
    node* t;
    while (pq->lst != NULL) {
        t = pq->lst;
        pq->lst = pq->lst->next;
        free(t);
    }
}