#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// 遍历链表并打印节点值
void printList(Node* head) {
    Node* p = head;
    int index = 0;
    while (p) {
        printf("Node %d: %d\n", index, p->value);
        p = p->next;
        index++;
    }
}

// 反转链表
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // 新的头节点
}

// 查找值为 target 的节点，返回序号，未找到返回 -1
int findValue(Node* head, int target, int startIndex) {
    Node* p = head;
    int index = 0;
    while (p) {
        if (index >= startIndex && p->value == target) {
            return index;
        }
        p = p->next;
        index++;
    }
    return -1;//WRONG!
}

void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(5);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(7);
    printf("Origin Node: \n");
    printList(head);
    // 反转链表
    head = reverseList(head);
    printf("\nReversed: \n");
    printList(head);
    // 查找第一个值为5的节点
    int firstIndex = findValue(head, 5, 0);
    printf("\nFirst 5 addr: %d\n", firstIndex);
    // 查找下一个值为5的节点（从上一个索引+1开始）
    int nextIndex = findValue(head, 5, firstIndex + 1);
    printf("Next 5 addr: %d\n", nextIndex);
    // 释放链表
    freeList(head);
    return 0;
}