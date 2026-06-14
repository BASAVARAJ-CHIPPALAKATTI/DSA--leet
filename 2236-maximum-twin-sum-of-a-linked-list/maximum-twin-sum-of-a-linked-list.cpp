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
        vector<int>st;
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        temp=head;
        int count=0;
        int ans=0;
        while(temp){
            if(count >= size/2 && st.size()>0){
                ans=max(ans,st.back()+temp->val);
                st.pop_back();
            }
            else{
                st.push_back(temp->val);
            }
            temp=temp->next;
            count++;
        }
        return ans;
    }
};