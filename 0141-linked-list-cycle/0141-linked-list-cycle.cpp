/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast=head,*slow=head; 
        int k = 0;
        while(fast!=slow or k==0){
            if(fast == nullptr or fast->next == nullptr){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
            k=1;
        }
        return true;
    }
};