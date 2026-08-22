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

    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > pq;

        // First node of every list
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            // Smallest node
            ListNode* node = pq.top();
            pq.pop();

            // Add to answer
            tail->next = node;
            tail = tail->next;

            // Add next node of same list
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};