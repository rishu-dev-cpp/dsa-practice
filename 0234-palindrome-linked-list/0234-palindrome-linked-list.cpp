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

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // Slow Fast pointer se mid tak pahuncho
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Second half ko reverse karo
        ListNode* reversedHead = reverseList(slow);

        ListNode* p1 = head;         
        ListNode* p2 = reversedHead;

        while (p2 != nullptr) { // reversed waali list jab tak khatam nahi hoti
            if (p1->val != p2->val) {
                return false; 
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return true; 
    }
};