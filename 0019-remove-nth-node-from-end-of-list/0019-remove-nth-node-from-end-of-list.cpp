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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // fast ko n steps aage le jao
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Dono ko saath move karo
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow->next is the node to delete
        ListNode* deleteNode = slow->next;

        slow->next = slow->next->next;

        delete deleteNode;

        return dummy->next;
    }
};