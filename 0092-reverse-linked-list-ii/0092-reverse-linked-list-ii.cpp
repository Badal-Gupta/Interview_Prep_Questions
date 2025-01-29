/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||left==right)return head;
        int count = 1;
        ListNode* ptr=head;
        ListNode* ptr2 = head;
        ListNode* prev = NULL;
        ListNode*nxt=NULL;
        ListNode*nxt2=NULL;
        ListNode*prev2=NULL;
        while(count!=left){
            prev=ptr;
            ptr=ptr->next;
            count++;
        }
        ListNode* ptr3 = ptr;
        count=1;
        while(count!=right){ 
            ptr2=ptr2->next;
            count++;
        }
        nxt2 = ptr2->next;
        if (ptr2!=NULL) ptr2->next=NULL;
        if(prev!=NULL) prev->next=NULL;

        while(ptr!=NULL){
            nxt=ptr->next;
            ptr->next=prev2;
            prev2=ptr;
            ptr=nxt;
        }

        if(prev!=NULL)prev->next=prev2;
        ptr3->next=nxt2;
        if(prev!=NULL)return head;
        else return prev;
    }
};