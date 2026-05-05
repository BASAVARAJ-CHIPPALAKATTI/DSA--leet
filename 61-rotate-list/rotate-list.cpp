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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0){
            return head;
        }
        int n=1;
        ListNode* temp=head;
        while(temp->next){
            n++;
            temp=temp->next;
        }
        // make it circular
        temp->next=head;

        k=k%n;
        ListNode* newHead=head;
        int skip=n-k;
        for(int i=1;i<skip;i++){
            newHead=newHead->next;
        }
        head=newHead->next;
        newHead->next=nullptr;
        return head;
    }
};