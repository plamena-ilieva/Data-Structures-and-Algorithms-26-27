class Solution {
    void pushBack(
        ListNode*& head,
        ListNode*& tail,
        ListNode* node)
    {
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* lessHead = nullptr;
        ListNode* lessTail = nullptr;

        ListNode* greaterHead = nullptr;
        ListNode* greaterTail = nullptr;

        while (head != nullptr)
        {
            ListNode* next = head->next;
            head->next = nullptr;

            if (head->val < x) {
                pushBack(lessHead, lessTail, head);
            } else {
                pushBack(greaterHead, greaterTail, head);
            }

            head = next;
        }

        if (lessTail != nullptr) {
            lessTail->next = greaterHead;
            return lessHead;
        }

        return greaterHead;
    }
};
