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
  /*
            Story : 
            1. Hume odd and even ko segregate karna hai
            2. To let's take two pointers to point to ODD and EVEN nodes
            3. Unko alag alag segregate kardenge
            4. Last me connect kardenge odd ko even se
            
        */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* odd= head;
        ListNode* even=head->next;

        ListNode* evenst=head->next;

        while(even && even->next){
            odd->next=odd->next->next; //odd->next=even->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenst;
        return head;
    }
};