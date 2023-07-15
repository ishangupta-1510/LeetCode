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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head,*fast=head;
        ListNode *preslow = nullptr;
        for(int i=0;i<n-1;i++){
            fast = fast->next;
        }
        if(fast->next == nullptr){
            head = head->next;
            delete slow;
            return head;
        }
        while(fast->next){
            preslow = slow;
            slow = slow->next;
            fast = fast->next;
        }
        preslow->next = slow->next;
        delete slow;
        return head;
    }
};