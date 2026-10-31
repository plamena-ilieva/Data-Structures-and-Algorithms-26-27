class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* nodes[50000];
        int n = 0;

        while (head != nullptr) {
            nodes[n++] = head;
            head = head->next;
        }

        int left = 0;
        int right = n - 1;

        while (left < right) {
            nodes[left++]->next = nodes[right];

            if (left == right)
                break;

            nodes[right--]->next = nodes[left];
        }

        nodes[left]->next = nullptr;
    }
};
