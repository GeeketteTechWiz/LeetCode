/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val; // Value of the node
 *     ListNode *next; // Pointer to the next node in the list
 *     ListNode() : val(0), next(nullptr) {} // Default constructor
 *     ListNode(int x) : val(x), next(nullptr) {} // Constructor with value
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value and next node
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base case: If one of the lists is empty, return the other list
        if (!list1 || !list2)
            return list1 ? list1 : list2;
        
        // Ensure list1 starts with the smaller value
        if (list1->val > list2->val)
            swap(list1, list2);

        // Recursively merge the rest of list1 with list2 and link it to the current node of list1
        list1->next = mergeTwoLists(list1->next, list2);
        
        // Return the updated list1 which now points to the merged list
        return list1;
    }
};
