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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum =0;
        ListNode *l3 = NULL;
        while(l1 or l2 or sum){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }    
            ListNode* newNode = new ListNode(sum%10);
            if(l3 == NULL){
                l3 = newNode;
            }
            else{
                ListNode* head = l3;
                while(l3->next){
                    l3=l3->next;
                }
                l3->next = newNode;
                l3 = head;
            }
            sum = sum /10;
        }
        return l3;
    }
};