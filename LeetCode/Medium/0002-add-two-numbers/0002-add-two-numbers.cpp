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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* new_list = new ListNode();
        ListNode* temp = new_list;
        int num1 = 0;
        int num2 = 0;
        int carry = 0;
        while(temp1 != nullptr || temp2 != nullptr){
            if(temp1 == nullptr){
                num1 = 0;
            }else{
                num1 = temp1->val;
                temp1 = temp1->next;
            }
            if(temp2 == nullptr){
                num2 = 0;
            }else{
                num2 = temp2->val;
                temp2 = temp2->next;
            }
            temp->val = (num1 + num2 + carry) % 10;
            carry = (num1 + num2 + carry) / 10;
            if(temp1 != nullptr || temp2 != nullptr){
                temp->next = new ListNode();
                temp = temp->next;
            }
        }
        if(carry > 0){
            temp->next = new ListNode(carry);
        }
        return new_list;
    }
};
