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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        int length = getLength(head);
        ListNode dummy(0);
        dummy.next = head;

        for (int step = 1; step < length; step *= 2) {
            ListNode* curr = dummy.next;
            ListNode* tail = &dummy;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step);

                tail = merge(left, right, tail);
            }
        }

        return dummy.next;
    }

private:
    int getLength(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }
        return length;
    }

    ListNode* split(ListNode* head, int step) {
        if (head == nullptr)
            return nullptr;

        for (int i = 1; i < step && head->next; i++) {
            head = head->next;
        }

        ListNode* right = head->next;
        head->next = nullptr;
        return right;
    }

    ListNode* merge(ListNode* left, ListNode* right, ListNode* tail) {
        ListNode* curr = tail;
        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        curr->next = left ? left : right;
        while (curr->next)
            curr = curr->next;

        return curr;
    }
};