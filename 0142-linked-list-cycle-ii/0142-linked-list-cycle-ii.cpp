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
        ListNode* fast = head;
        ListNode* slow = head;

        int check = 0;

        while(fast != nullptr && fast->next != nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                check = 1;
                break;
            }
        }
        
        if(check) {
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            
            }
            return fast;
        }
        return nullptr;
    }
};