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
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans=0;
        set<int>st;
        for(int num : nums){
            st.insert(num);
        }
        bool newone=true;
        ListNode* temp=head;
        while(temp){
            //new component
            if(st.find(temp->val)!=st.end()){
                if(newone==true){
                    ans++;
                    newone=false;
                }  
            }
            else{
                newone=true;
            }
            temp=temp->next;           
        }
        return ans;
    }
};