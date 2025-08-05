class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while(cur!= NULL){
            n++;
            cur = cur->next;
        }
        if(n==0){
            return head;
        }
        k = (k%n);
        if(k==0){
            return head;
        }
        int count = 0;
        cur = head;
        ListNode* prev= NULL;
        while(count<n-k && cur != NULL){
            count++;
            prev = cur;
            cur = cur->next;
        }

        prev->next = NULL;
        ListNode* a = cur; 
        while(cur->next != NULL ){
            cur = cur->next;
        }
        cur->next = head;
        head = a;
        return head;

    }
};