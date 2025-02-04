//
// Created by XX on 2025/2/2.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // 用于bool类型

typedef struct Node {
    int id;
    int score;
    struct Node *next;
} Node;

Node *create_node_list(int n);

// 冒泡排序交换节点方法
Node *bubble_sort(Node *head_one, Node *head_two);

// 插入排序方法
Node *insertion_sort(Node *head_one, Node *head_two);

/* 归并排序方法 */
// symbol为0表示递归版本，为1表示迭代版本
Node *merge_nodes(Node *head_one, Node *head_two, int symbol);

Node *merge(Node *left, Node *right);

// 递归版本
Node *merge_sort(Node *head);

Node *find_mid(Node *head);

// 迭代版本
Node *merge_sort_iterative(Node *head);

Node *split(Node *head, int n);

void swap_nodes(Node *prev, Node *a, Node *b);

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    Node *head_one = create_node_list(n);
    Node *head_two = create_node_list(m);
    head_one = merge_nodes(head_one, head_two, 1); // 接收新头节点
    while (head_one != NULL) {
        printf("%d %d\n", head_one->id, head_one->score);
        Node *temp = head_one;
        head_one = head_one->next;
        free(temp); // 释放节点内存
    }
    return 0;
}

Node *create_node_list(int n) {
    if (n <= 0) return NULL;
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        scanf("%d %d", &newNode->id, &newNode->score);
        newNode->next = NULL;
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// 冒泡排序
Node *bubble_sort(Node *head_one, Node *head_two) {
    // 合并两个链表
    if (head_one == NULL) return head_two;
    Node *tail = head_one;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head_two;

    // 冒泡排序
    bool swapped;
    Node **ptr_to_head = &head_one; // 用于处理头节点交换

    do {
        swapped = false;
        Node **prev_ptr = ptr_to_head; // 指向前驱指针的指针
        Node *curr = *prev_ptr;

        while (curr != NULL && curr->next != NULL) {
            Node *next = curr->next;
            if (curr->id > next->id) {
                // 交换curr和next
                *prev_ptr = next; // 前驱指针指向next
                curr->next = next->next;
                next->next = curr;
                swapped = true;
                // 更新prev_ptr为next的地址，因为下一轮比较从next开始
                prev_ptr = &((*prev_ptr)->next);
            } else {
                // 无需交换，移动指针
                prev_ptr = &curr->next;
                curr = curr->next;
            }
        }
    } while (swapped);

    return *ptr_to_head; // 返回排序后的头节点
}

/* 交换两个相邻节点 */
void swap_nodes(Node *prev, Node *a, Node *b) {
    if (a == NULL || b == NULL) return;
    a->next = b->next;
    b->next = a;
    if (prev != NULL) {
        prev->next = b;
    }
}

// 插入排序
Node *insertion_sort(Node *head_one, Node *head_two) {
    // 合并两个链表
    if (head_one == NULL) return head_two;
    Node *tail = head_one;
    while (tail->next != NULL) tail = tail->next;
    tail->next = head_two;

    // 插入排序核心逻辑
    Node *sorted_head = NULL; // 新链表的头节点
    Node *current = head_one; // 遍历原始链表的指针

    while (current != NULL) {
        Node *next = current->next; // 保存下一个待处理节点

        // 处理头节点插入
        if (sorted_head == NULL || current->id < sorted_head->id) {
            current->next = sorted_head;
            sorted_head = current;
        }
        // 处理中间插入
        else {
            Node *search = sorted_head;
            // 找到第一个比当前节点大的前驱节点
            while (search->next != NULL && search->next->id < current->id) {
                search = search->next;
            }
            // 插入到search后面
            current->next = search->next;
            search->next = current;
        }
        current = next; // 处理下一个节点
    }
    return sorted_head;
}

// 归并排序
Node *merge_nodes(Node *head_one, Node *head_two, int symbol) {
    // 合并两个链表
    if (head_one == NULL) return head_two;
    Node *tail = head_one;
    while (tail->next != NULL) tail = tail->next;
    tail->next = head_two;

    // 对合并后的链表进行归并排序（默认为递归版本）
    if (symbol == 0) return merge_sort(head_one);
    return merge_sort(head_one);
}

/* 合并两个有序链表 */
Node *merge(Node *left, Node *right) {
    Node dummy; // 哑节点简化头节点处理
    Node *tail = &dummy;

    while (left && right) {
        if (left->id < right->id) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    // 处理剩余节点
    tail->next = (left != NULL) ? left : right;
    return dummy.next;
}

/* 归并排序主函数（递归版本） */
Node *merge_sort(Node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    // 1. 找到中间节点并分割链表
    Node *mid = find_mid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL; // 断开链表

    // 2. 递归排序左右两部分
    left = merge_sort(left);
    right = merge_sort(right);

    // 3. 合并排序后的链表
    return merge(left, right);
}

/* 使用快慢指针法找到中间节点 */
Node *find_mid(Node *head) {
    Node *slow = head;
    Node *fast = head->next; // 让slow停在中间偏左位置

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/* 归并排序主函数（迭代版本） */
Node *merge_sort_iterative(Node *head) {
    if (!head || !head->next) return head;

    int block_size = 1; // 初始块大小为1
    int list_length = 0;
    Node dummy; // 哑节点简化操作
    dummy.next = head;

    // 计算链表长度（可选优化）
    Node *temp = head;
    while (temp) {
        list_length++;
        temp = temp->next;
    }

    // 外层循环控制块大小倍增
    for (; block_size < list_length; block_size <<= 1) {
        Node *prev = &dummy; // 前驱指针
        Node *curr = dummy.next; // 当前处理指针

        while (curr) {
            // 分割左半块
            Node *left = curr;
            Node *right = split(left, block_size);

            // 分割右半块
            curr = split(right, block_size);

            // 合并左右块并连接
            prev->next = merge(left, right);

            // 移动prev到已排序部分的末尾
            while (prev->next) {
                prev = prev->next;
            }
        }
    }
    return dummy.next;
}

/* 分割链表，返回后半部分的头节点 */
Node *split(Node *head, int n) {
    while (--n && head) {
        head = head->next;
    }
    if (!head) return NULL;

    Node *rest = head->next;
    head->next = NULL; // 断开前半部分
    return rest;
}
