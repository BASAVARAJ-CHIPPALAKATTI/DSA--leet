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
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        int remove=count-n;
        ListNode* curr=head;
        if(remove==0){
            return head->next;
        }
        
       while(curr){
        if(remove==1){
            break;
        }
        remove--;
        curr=curr->next;
       }
    
       curr->next=curr->next->next;
       return head;
    }
};