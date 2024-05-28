#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* delNode(struct ListNode *head, int target);

int main(){
    int a[2] = {1,128*1024-1};
    char *p;
    for (int i = 0; i < 2; ++i) {
        p = (char *)&a[i];
        //printf("0x%X\n",&a[i]);
        //printf("0x%X %X %X %X\n",p++,p++,p++,p++);
        p = (char *)&a[i];
        *(p++)+=1;
        *p|=*p<<1;
        *(++p)+=1;
        *p^=1;
        printf("0x%X\n",a[i]);
    }

    int b = 0x12345678;
    p = (char *)&b;
    printf("0x%X %X %X %X\n",*p++,*p++,*p++,*p++);

    return 0;
}

struct ListNode* delNode(struct ListNode *head, int target){
    struct ListNode *pre = NULL, *cur = head;
    while (cur) {
        while (cur->val != target) {
            pre = cur;
            cur = cur->next;
        }
        if (!pre) head = head->next, cur = head;
        else pre->next = cur->next, cur = cur->next;
    }
    return head;
}
