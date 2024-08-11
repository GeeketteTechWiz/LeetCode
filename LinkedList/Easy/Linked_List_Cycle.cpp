class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Check if the list is empty or has only one node; if so, no cycle can exist
        if (head == NULL) {
            return false;
        }
        
        // Initialize two pointers: slow and fast
        ListNode *slow = head;              // Slow pointer starts at the head of the list
        ListNode *fast = head->next;        // Fast pointer starts at the node after the head

        // Traverse the list
        while (slow != fast) {
            // If fast pointer reaches the end of the list, there is no cycle
            if (fast == NULL || fast->next == NULL) {
                return false;
            }

            // Move slow pointer one step
            slow = slow->next;

            // Move fast pointer two steps
            fast = fast->next->next;
        }
        
        // If slow and fast pointers meet, a cycle exists
        return true;
    }
};
