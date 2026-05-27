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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        int carry = 0; // Shuruat mein carry 0 hoga

        // Step 2: Loop tab tak chalega jab tak l1, l2 ya carry mein se kuch bhi bacha ho
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Pehle pichla carry sum mein daal do

            // Agar l1 mein node bacha hai, toh uski value sum mein jodo
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; // l1 ko aage badhao
            }

            // Agar l2 mein node bacha hai, toh uski value sum mein jodo
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; // l2 ko aage badhao
            }

            // Step 3: Naya carry aur naye node ki value nikaalo
            carry = sum / 10;                     // Jaise 12 / 10 = 1 (Carry)
            curr->next = new ListNode(sum % 10);  // Jaise 12 % 10 = 2 (Naya Node)
            
            curr = curr->next; // Answer wali list ke pointer ko aage badhao
        }

        // Step 4: Asli head bachaao aur dummy ko uda do
        ListNode* realHead = dummy->next;
        delete dummy;
        return realHead;
    }
};