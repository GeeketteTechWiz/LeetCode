class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to serve as the starting point of the result list
        ListNode *dummy = new ListNode(0);
        ListNode *l = dummy; // Pointer to the current node in the result list
        int carry = 0; // Variable to keep track of carry-over during addition

        // Iterate while there are nodes left in either l1 or l2
        while (l1 || l2) {
            int sum = carry; // Initialize sum with the carry from the previous iteration
            
            // Add the value from l1 if it exists
            if (l1) {
                sum += l1->val;
                l1 = l1->next; // Move to the next node in l1
            }
            
            // Add the value from l2 if it exists
            if (l2) {
                sum += l2->val;
                l2 = l2->next; // Move to the next node in l2
            }
            
            // If sum is greater than 9, set carry to 1 and adjust sum to a single digit
            if (sum > 9) {
                carry = 1;
                sum = sum % 10;
            } else {
                carry = 0;
            }
            
            // Create a new node with the value of sum and link it to the result list
            l->next = new ListNode(sum);
            l = l->next; // Move to the next node in the result list
        }
        
        // If there's a carry left after processing all nodes, add a new node with carry value
        if (carry) {
            l->next = new ListNode(carry);
            l = l->next;
        }
        
        // Return the next node of dummy, which is the head of the result list
        return dummy->next;
    }
};
