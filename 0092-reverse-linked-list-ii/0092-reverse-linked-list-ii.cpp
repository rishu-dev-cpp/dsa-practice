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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr && left==right) return head;
        
        // Dummy node 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        //prev ko left - 1 tk le jao
        for(int i=0;i<left-1;i++){
            prev = prev->next;
        }

        // curr ko left wali index pr jao jo question me h
        ListNode* curr = prev->next;

        // right - left baar chalega 
        for(int i=0;i<right-left;i++){
            ListNode* temp = curr->next; 
            curr->next = temp->next;    
            temp->next = prev->next;
            prev->next = temp;
        }
        ListNode* realHead = dummy->next;
        delete dummy;
        return realHead;
    }
};