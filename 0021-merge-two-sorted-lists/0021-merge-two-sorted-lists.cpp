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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pt1 = list1,*pt2 = list2;
        if(pt1 == NULL){
            return pt2;
        }
        else if(pt2 == NULL){
            return pt1;
        }
        ListNode* curr;
        
        if(pt1->val > pt2->val){
            curr = pt2;
            pt2 = pt2->next;
        }
        else{
            curr = pt1;
            pt1 = pt1->next;
        }
        ListNode* ans = curr;
        while(pt1!=NULL and pt2!=NULL){
            if(pt1->val > pt2->val){
                curr->next = pt2;
                curr = pt2;
                pt2 = pt2->next;
            }
            else{
                curr->next = pt1;
                curr = pt1;
                pt1 = pt1->next;
            }
        }
        if(pt1 == NULL and pt2!= NULL){
            curr->next = pt2;
        }
        else if(pt2 == NULL and pt1!= NULL){
            curr->next = pt1;
        }
        return ans;
    }
};