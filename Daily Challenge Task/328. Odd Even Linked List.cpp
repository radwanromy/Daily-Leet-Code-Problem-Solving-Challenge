/******************************************************************************
328. Odd Even Linked List
Medium

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106

*******************************************************************************/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddh = new ListNode(0); 
        ListNode *odd = oddh;
        ListNode *evenh = new ListNode(0);
        ListNode *even = evenh;
        ListNode *cur = head;
        int i = 1;
        
        while(cur){
            if(i % 2 == 1){
                odd->next = cur;
                odd = odd->next;
            }else{
                even->next = new ListNode(cur->val);
                even = even->next;
            }
            i++;
            cur = cur->next;
        }
        
        odd->next = evenh->next;
        return oddh->next;
    }
};

/*
 The code is a function that takes in a ListNode* head and returns the list of nodes after it.
 The code starts by creating an oddList node with 0 as its value, then creates two more nodes: evenh and even.
 The code loops through the list until cur is null, which means that there are no more nodes to loop through.
 The first thing the code does when it's done iterating over all the nodes is create an oddList node with 0 as its value, then creates two more nodes: evenh and even.
 Then it sets up for another iteration of the loop where if i % 2 == 1, then odd will be set to cur (the current node) else if i % 2 == 0, then even will be set to new ListNode(cur->val).
 This way each iteration of the loop has one less element than before because every time you add a new node into your list you're also adding one less element into your original list so eventually they'll both have equal number of elements again.
 The code creates a list of nodes that are either odd or even.
 The first node in the list is head, which is then followed by an infinite loop that iterates through each node in the list and checks if it is odd or even.
 If it's odd, the next node in the list will be cur, while if it's even, new ListNode(cur->val) will be created and placed after cur.
*/