/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // ListNode* temp=head;
        // unordered_map<ListNode* ,int>mp;

        // while(temp!=NULL){
        //     if(mp.count(temp)!=0){
        //         return temp;
        //     }
        //     mp[temp]=1;
        //     temp=temp->next;
        // }
        // return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==nullptr|| head->next==nullptr){
            return nullptr;
        }
        while(fast!=nullptr && fast->next!=nullptr ){
            slow=slow->next;
            fast=fast->next->next;
                if(slow==fast){
                    slow=head;
                    while(slow!=fast){
                        slow=slow->next;
                        fast=fast->next;
                    }
                    return slow;
                }  
        }
        return NULL;
        
    }
};