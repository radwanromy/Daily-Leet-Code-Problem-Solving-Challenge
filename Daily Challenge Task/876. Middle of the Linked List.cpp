/******************************************************************************

876. Middle of the Linked List
Easy

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

*******************************************************************************/
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
     ListNode* middleNode(ListNode* head) {
        ListNode* step1 = head;
        ListNode* step2 = head;
        
        //if list has odd length, step2 will be the last node
        //if list has even length, step2 will be NULL
        while(step2!=NULL && step2->next!=NULL){
            step1 = step1->next;
            step2 = step2->next->next;
        }
        
        return step1;
    }
};


/*
 The code is trying to find the middle node of a list.
 The code starts by finding the head of the list, which is step1.
 Then it finds the next node in that list and stores it as step2.
 It keeps doing this until there are no more nodes left in that list or until it reaches NULL.
 The code will return the middle node of a list.
 The code will iterate through all nodes in the list and keep track of which is the last node, if there is an odd number of nodes then step2 will be the last node and if there is an even number of nodes then step2 will be NULL.
 The code returns the first node that it finds that has not been checked for being NULL.
 */