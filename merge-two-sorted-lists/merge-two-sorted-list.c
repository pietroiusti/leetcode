#include <stdlib.h>
#include <stdio.h>

/* https://leetcode.com/problems/merge-two-sorted-lists */

/* [1,2,4] */
/* [1,3,4] *
// =>
/* [1,1,2,3,4,4] */

// * Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    // If I build the list directly it's gonna be reversed...

    // I can start by putting the results into an array, and then
    // traverse the array backwards so to build the list in the right
    // order.

    // todo: how to avoid the array step?

    int arr[102];

    int i = 0;
    while (list1!=NULL || list2!=NULL) {
        if (list1 == NULL) {
            //printf("list1 is null\n");
            arr[i] = list2->val;
            list2 = list2->next;
        } else if (list2 == NULL) {
            //printf("list2 is null\n");
            arr[i] = list1->val;
            list1 = list1->next;            
        } else if (list1->val < list2->val) {
            //printf("list1->val < list2->val (%d < %d)\n", list1->val, list2->val);
            arr[i] = list1->val;
            list1 = list1->next;
        } else if (list2->val < list1->val) {
            //printf("list2->val < list1->val (%d < %d)\n", list2->val, list1->val);
            arr[i] = list2->val;
            list2 = list2->next;
        } else if (list1->val == list2->val){
            //printf("list1->val == list2->val (%d == %d)\n", list1->val, list2->val);
            arr[i] = list1->val;
            list1 = list1->next;
        } else {
            //printf("What??\n");
            exit(666);
        }
        i++;
    }

    struct ListNode *list = NULL;
    i--;
    while (i >= 0) {
        //printf("arr[%d]: %d\n", i, arr[i]);
        //make node and add it to the result list
        struct ListNode *np = (struct ListNode *)malloc(sizeof(struct ListNode));
        np->val = arr[i];
        np->next = list;
        //printf("Created node: {val: %d, next: %p}\n", np->val, np->next);
        list = np;
        //printf("result = %p\n", &list);

        i--;
    }
    
    return list;
}

int main(void) {
    // create list 1
    struct ListNode l1_4;
    l1_4.val = 4;
    l1_4.next = NULL;
    struct ListNode l1_2;
    l1_2.val = 2;
    l1_2.next = &l1_4;
    struct ListNode l1_1;
    l1_1.val = 1;
    l1_1.next = &l1_2;
    struct ListNode *l1 = &l1_1;

    // create list 2
    struct ListNode l2_4;
    l2_4.val = 4;
    l2_4.next = NULL;
    struct ListNode l2_3;
    l2_3.val = 3;
    l2_3.next = &l2_4;
    struct ListNode l2_1;
    l2_1.val = 1;
    l2_1.next = &l2_3;
    struct ListNode *l2 = &l2_1;

    // merge lists
    struct ListNode *lnp = mergeTwoLists(l1, l2);

    // print result
    while (lnp) {
        printf("%d\n", lnp->val);
        lnp = lnp->next;
    }

    return 0;
}
