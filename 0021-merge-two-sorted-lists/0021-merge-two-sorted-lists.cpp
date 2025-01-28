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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* ptr = new ListNode(0);
        ListNode* ptr1 = ptr;
        while(a!=NULL&&b!=NULL){
            if(a->val <= b->val){
                ptr->next = new ListNode(a->val);
                ptr=ptr->next;
                a=a->next;
            }else{
                ptr->next = new ListNode(b->val);
                ptr=ptr->next;
                b=b->next;
            }
        }
        while(a!=NULL){
            ptr->next = new ListNode(a->val);
                ptr=ptr->next;
                a=a->next;
        }
        while(b!=NULL){
            ptr->next = new ListNode(b->val);
                ptr=ptr->next;
                b=b->next;
        }
        return ptr1->next;
    }
};