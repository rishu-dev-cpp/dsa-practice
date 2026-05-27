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
        // Base case: Agar list khali hai ya 1 hi node hai, toh koi duplicate nahi ho sakta
        if (head == nullptr || head->next == nullptr) return head;

        // Dummy Node ki entry!
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy; // prev hamesha safe node par rahega

        while (head != nullptr) {
            // Agar humein duplicate milta hai
            if (head->next != nullptr && head->val == head->next->val) {
                // Loop chalakar is duplicate value ke aakhiri node tak pahuncho
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Poore duplicate group ko bypass kar do
                prev->next = head->next; 
                // Note: Humne prev ko aage nahi badhaya, kyunki ho sakta hai naya prev->next bhi duplicate nikal aaye!
            } else {
                // Agar koi duplicate nahi mila, toh prev ko aage badhana safe hai
                prev = prev->next;
            }
            // head ko hamesha aage badhate raho
            head = head->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Memory saaf
        return newHead;
    }
};
/*
Maan lo list hai: [1, 1, 2, 3]

    Shuruat mein: dummy -> [1] -> [1] -> [2] -> [3], prev khada hai dummy par, head khada hai pehle 1 par.

    Check kiya: Pehla 1 aur agla 1 match ho gaye! Loop chala aur head pahunch gaya dusre 1 par.

    Bypass: prev->next = head->next (Yaani dummy->next ab direct 2 ko point karega). Teeno 1 line se bahar!

    Next Step: head aage badh kar 2 par gaya. Ab dummy direct 2 se juda hai.

    Check kiya: 2 ka agla 3 hai (No duplicate). Toh prev aage badh kar 2 par aa gaya.

Final List: [2] -> [3]. head badalne wala jhanjhat dummy ne akele sambhal liya!
*/