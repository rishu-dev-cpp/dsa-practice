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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* temp = head;
        
        // Dono ka zinda hona zaroori hai
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                ListNode* del = temp->next;
                temp->next = temp->next->next; // Bypass kiya
                delete del;                    // Safai ki
                // YAHAN temp ko aage NAHI badhana hai!
            } else {
                // Agar duplicate nahi hai, TABHI aage badho
                temp = temp->next;
            }
        }
        return head;
    }
};