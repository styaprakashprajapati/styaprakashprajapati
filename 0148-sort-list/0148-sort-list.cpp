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

    // Do sorted linked lists ko merge karega
    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Jo list bach gayi usko attach kar do
        if (list1 != nullptr) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        return dummy.next;
    }


    ListNode* sortList(ListNode* head) {

        // 0 ya 1 node → already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Slow-fast pointer se middle find karo
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Second half ka head
        ListNode* second = slow->next;

        // First half ko break karo
        slow->next = nullptr;

        // Dono halves sort karo
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        // Dono sorted lists merge karo
        return merge(left, right);
    }
};