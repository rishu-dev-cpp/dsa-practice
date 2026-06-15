class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Agar list khali hai ya sirf 1 hi node hai, 
        // toh use delete karne ke baad kuch nahi bachega (NULL return karo)
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // Yeh slow ke thik piche waale node ko track karega

        // Fast ko 2 kadam aur Slow ko 1 kadam badao
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;        // Slow ke aage badhne se pehle uski jagah yaad rakho
            slow = slow->next;  // Slow chala 1 kadam
            fast = fast->next->next; // Fast chala 2 kadam
        }

        // Ab 'slow' khada hai middle node par, 
        // aur 'prev' khada hai middle se thik PEHLE waale node par!
        
        prev->next = slow->next; // Middle node ko bypass kar diya (Connection cut!)
        
        delete slow; // Free memory

        return head; // Bachi hui list ka head return kar do
    }
};