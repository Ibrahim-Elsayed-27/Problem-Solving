class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* first = curr;
            ListNode* second = curr->next;

            ListNode* nextPair = second->next;

            second->next = first;
            first->next = nextPair;


            prev->next = second;

            prev = first;
            curr = nextPair;
        }

        return dummy.next;
    }
};
