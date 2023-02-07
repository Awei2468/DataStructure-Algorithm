#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void TwoSum(struct Node *head, int sum) {
    int hash[1001] = {0};
    for (struct Node *i = head->next; i != NULL; ++i) {
        if (hash[sum - i->data]) {
            int a = i->data, b = sum - i->data;
            if (a > b)
                printf("(%d , %d) ", b, a);
            else
                printf("(%d , %d) ", a, b);
        }
        else
            hash[i->data] = 1;
    }
}

int main() {

    return 0;
}
