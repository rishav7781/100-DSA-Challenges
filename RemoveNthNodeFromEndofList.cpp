class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;

        // Step 1: Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Step 2: If fast becomes NULL, delete head
        if (!fast) return head->next;

        // Step 3: Move both fast and slow till fast reaches last node
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 4: Delete nth node from end
        slow->next = slow->next->next;

        return head;
    }
};
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