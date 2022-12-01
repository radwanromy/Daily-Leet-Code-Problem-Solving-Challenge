/******************************************************************************
2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * res = new ListNode(-1); 
    ListNode * curr=res; 
    int carry=0;
    while(l1 || l2)
    {
    int n1=l1 ? l1->val : 0; 
    int n2=l2 ? l2->val : 0; 
    int sum=n1 + n2 + carry;
    carry=sum/10;
    curr->next = new ListNode(sum%10);
    curr=curr->next;

         if(l1)
             l1=l1->next;

         if(l2)
             l2=l2->next;
     }
     if(carry)
         curr->next= new ListNode(1);   

     return res->next;
    }
};

/*
 The code is a function that takes two ListNode objects and adds them together.
 The code starts by creating a new ListNode object with the value -1.
 Then, it loops through each of the nodes in the list until one is found to be null or not present.
 The first thing it does is check if either of the input nodes are null, which would indicate that they have been removed from the list.
 If either node is not null, then it increments their val variable by 1 and checks to see if there was an overflow (carry).
 If so, then it creates a new ListNode object with sum%10 as its val variable and sets curr->next to point at this newly created node.
 If neither input node is null or has an overflow, then l1 will be set equal to l2 because both are still present in the list; otherwise l1 will be set equal to l1->next because only one of them remains in the list after adding n2+n1+carry into sum .
 The code is meant to add two numbers together and then return the sum of the two numbers.
 The code begins by creating a new ListNode object that will be used to store the result of adding two numbers together.
 The while loop repeats until either l1 or l2 are null, which indicates that they have been added to the list.
 Next, n1 and n2 are calculated based on whether l1 or l2 was processed first.
 Then, a variable called carry is initialized with 0 and used in calculating the sum of n1 + n2 + carry.
 After this, curr is set equal to curr->next so it can be returned when done adding up all of the numbers in the list.
 If either l1
*/

