class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Base case: If the list is empty or has only one node, no need to reverse
        if (!head || !head->next) {
            return head;
        }
        
        // Create a dummy node to simplify edge cases, such as reversing the first few nodes
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy; // Pointer to the node before the start of the reversal segment

        // Move `pre` to the node immediately before the `left` position
        for (int i = 1; i < left; i++) {
            pre = pre->next;
        }
        
        // `l` will point to the start of the sublist to be reversed
        ListNode* l = pre->next;
        ListNode* p = l; // Pointer to the current node being processed
        ListNode* pre1 = pre; // Pointer to the node before the reversal segment
        
        // Reverse the sublist between `left` and `right`
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* n = p->next; // Save the next node
            p->next = pre1; // Reverse the link
            pre1 = p; // Move `pre1` to the current node
            p = n; // Move `p` to the next node
        }
        
        // Connect the reversed sublist back to the original list
        pre->next = pre1; // Connect the node before the reversal segment to the new head of the reversed sublist
        l->next = p; // Connect the end of the reversed sublist to the remaining part of the list
        
        // Return the new head of the list
        return dummy->next;
    }
};
