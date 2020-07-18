#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
/**
 * LeetCode
 * 2.两数相加
 * https://leetcode-cn.com/u/banana798/
 */
//添加结点
ListNode* add(ListNode*head, int temp){
    ListNode *p=head;
    while(1){
        if(p->next==NULL){
            p->next=(ListNode*)malloc(sizeof(ListNode));
            p->next->val = temp;
            p->next->next=NULL;
            return head;
        }
        p=p->next;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p=l1, *q=l2, *curr = head;
    //tag用以标记进位
    int tag = 0;
    while(p!=NULL||q!=NULL){
        int x = p ? p->val : 0;
        int y = q ? q->val : 0;
        int sum = tag + x + y;
        tag = sum/10;
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->next->next=NULL;
        curr->next->val = sum%10;
        curr=curr->next;
        if(p) p=p->next;
        if(q) q=q->next;
    }
    //最后进1位
    if(tag>0){
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->next->next=NULL;
        curr->next->val = tag;
    }
    return head->next;
}

int main(){
    struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next=NULL;
    l2->next=NULL;

    //向链表添加测试数据
    add(l1,1);
    add(l2,9);

    l1=addTwoNumbers(l1->next,l2->next);
    printf("%d->%d",l1->val,l1->next->val);
}
