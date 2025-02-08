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
    int pairSum(ListNode* head) {
        ListNode* slow,*fast;
        slow=head;
        fast=head;

        while(fast && fast->next){
            fast=fast->next->next;
             slow=slow->next;
        }
     //reverse
        ListNode* prev=nullptr;
        while(slow){
           ListNode* temp=slow->next;
           slow->next=prev;
           prev=slow;
           slow=temp;
        }
        ListNode* first=head;
        ListNode* second=prev;
        int pairsum=0;
        while(first && second){
            pairsum=max(pairsum,first->val+second->val);
            first=first->next;
            second=second->next;
        }
        return pairsum;
    }
};