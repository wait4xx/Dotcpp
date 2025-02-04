//
// Created by XX on 2025/2/2.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_circular_list(int n);

int report(int n, int m);

int josephus(int n, int m);

int josephus_recursive(int n, int m);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", josephus(n, 3));
    return 0;
}

Node* create_circular_list(int n)
{
    if (n == 0) return NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    Node* tail = head;

    for (int i = 1; i < n; i++)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i + 1;
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = head; // 形成循环
    return head;
}

int report(int n, int m)
{
    Node* head = create_circular_list(n);
    Node* current = head;
    Node* previous = head;

    int count = 0;
    while (current->next != current)
    { // 当前节点的下一个节点是自己时停止
        count++;
        if (count % m == 0)
        { // 报数到m
            previous->next = current->next; // 删除当前节点
            free(current);
            current = previous->next;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    int result = current->data;
    free(current); // 最后一个节点也需要释放
    return result;
}

// 约瑟夫问题的数学解法(迭代法)
int josephus(int n, int m)
{
    int pos = 0; // 最终剩下的人的位置从0开始计数
    for (int i = 2; i <= n; i++) {
        pos = (pos + m) % i;
    }
    return pos + 1; // 调整为从1开始计数
}

// 约瑟夫问题的递归解法
int josephus_recursive(int n, int m)
{
    if (n == 1) return 1;
    return (josephus_recursive(n - 1, m) + m - 1) % n + 1;
}
