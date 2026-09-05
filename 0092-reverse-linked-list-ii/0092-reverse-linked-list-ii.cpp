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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // prev ko left ke just pehle le jao
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Current first node of the section
        ListNode* curr = prev->next;

        // Reverse the required portion
        for (int i = 0; i < right - left; i++) {

            ListNode* nextNode = curr->next;

            curr->next = nextNode->next;

            nextNode->next = prev->next;

            prev->next = nextNode;
        }

        return dummy->next;
    }
};