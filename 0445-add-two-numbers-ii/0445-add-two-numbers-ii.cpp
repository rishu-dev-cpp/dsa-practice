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
        stack<int> s1, s2;
        
        // l1 ke saare elements stack 1 mein daalo
        while(l1 != nullptr){
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        // l2 ke saare elements stack 2 mein daalo (Bug Fixed: s2 use kiya)
        while(l2 != nullptr){
            s2.push(l2->val); 
            l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* head = nullptr; // Yeh humara naya head pointer banega

        // Loop tab tak chalega jab tak dono stacks khali na ho jayein ya carry bacha ho
        while(!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry; // Har baar pichle carry se shuru karo
            
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            
            carry = sum / 10; // Naya carry nikaalo
            
            // HEAD INSERTION MAGIC:
            // Naya dabba banao jisme sum % 10 ho
            ListNode* newNode = new ListNode(sum % 10);
            
            // Naye dabbe ka haath purane head ko pakda do
            newNode->next = head;
            
            // Aur ab naye dabbe ko hi sabse aage (head) ghoshit kar do
            head = newNode;
        }
        return head; // Is baar dummy ki zaroorat nahi padi, head hi sabse aage hai!
        
    }
};