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
 /* approach 
 create new dummy listnode
 use simple while loop until carry ,l1,l2 becomes end that much do process
 and store every iteration in dummy
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* temp=dummy;
        int carry=0;
        while(carry || curr1 || curr2){
            int sum=carry;
            if(curr1){
                sum+=curr1->val;
                curr1=curr1->next;
            }
            if(curr2){
                sum+=curr2->val;
                curr2=curr2->next;
            }
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            
        }
        return dummy->next;
    }
};