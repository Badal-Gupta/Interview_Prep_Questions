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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * cur = head;
        ListNode* prev = NULL;
        int count=0;
        while(cur!=NULL){
            if(cur->next!=NULL&&cur->val==cur->next->val){
                cur->next=cur->next->next;
                count++;
            }else{
                if(count>0){
                   if(prev==NULL){
                     cur=cur->next;
                     head=cur;
                     count=0;
                   }else{
                    cur=cur->next;
                    prev->next=cur;
                    count=0;
                   }
                }else{
                    prev= cur;
                    cur=cur->next;
                }
            }
        }
        return head;
    }
};