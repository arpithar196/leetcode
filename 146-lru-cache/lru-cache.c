#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node** hashmap;
} LRUCache;

// Safely insert node right after head
void add(LRUCache* obj, Node* node) {
    node->prev = obj->head;
    node->next = obj->head->next;
   // if (obj->head->next != NULL) {
        obj->head->next->prev = node;
    //}
    obj->head->next = node;
}

// Remove node from its current position
void delete(LRUCache* obj, Node* node) {
   // if (node->prev) 
    node->prev->next = node->next;
   // if (node->next)
     node->next->prev = node->prev;
}

// Create a new doubly linked node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* lru = (LRUCache*)malloc(sizeof(LRUCache));
    lru->capacity = capacity;
    lru->size = 0;

    lru->head = createNode(-1, -1);
    lru->tail = createNode(-1, -1);
    lru->head->next = lru->tail;
    lru->tail->prev = lru->head;

    lru->hashmap = (Node**)calloc(100001, sizeof(Node*));
    return lru;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = obj->hashmap[key];
    if (node) {
        delete(obj, node);
        add(obj, node);
        return node->value;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = obj->hashmap[key];
    if (node) {
        node->value = value;
        delete(obj, node);
        add(obj, node);
    } else {
        if (obj->size == obj->capacity) {
            Node* toRemove = obj->tail->prev;
            delete(obj, toRemove);
            obj->hashmap[toRemove->key] = NULL;
            free(toRemove);
            obj->size--;
        }
        Node* newNode = createNode(key, value);
        add(obj, newNode);
        obj->hashmap[key] = newNode;
        obj->size++;
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* cur = obj->head;
    while (cur) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj->hashmap);
    free(obj);
}
