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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        // Step 1: Total nodes gino
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Step 2: Dummy Node aur pointers setup
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        // Total kitne jhund reverse karne hain?
        int groups = count / k; 

        // Step 3: Har jhund ke liye khel shuru karo
        for (int g = 0; g < groups; g++) {
            // Har jhund mein k-1 baar shifting hogi
            for (int i = 0; i < k - 1; i++) {
                ListNode* tempNode = curr->next;
                curr->next = tempNode->next;
                tempNode->next = prev->next;
                prev->next = tempNode;
            }
            // AGLE JHUND KE LIYE POSITION SHIFT:
            prev = curr;       // prev ab purane jhund ka aakhiri node ban gaya
            curr = prev->next; // curr agle jhund ka pehla node ban gaya
        }

        ListNode* realHead = dummy->next;
        delete dummy;
        return realHead;
    }
};