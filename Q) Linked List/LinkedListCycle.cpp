#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Definition for singly-linked list node
 *
 * This structure represents a single node in a singly-linked list.
 * Each node contains an integer value and a pointer to the next node.
 */
struct ListNode
{
    int val;        ///< The integer value stored in the node
    ListNode *next; ///< Pointer to the next node in the list (NULL if last node)

    /**
     * @brief Constructor to initialize a ListNode
     * @param x The integer value to store in the node
     */
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @brief Solution class containing cycle detection algorithm
 *
 * This class implements Floyd's Cycle Detection Algorithm (also known as
 * "Tortoise and Hare" algorithm) to detect if a linked list contains a cycle.
 */
class Solution
{
public:
    /**
     * @brief Detects if a linked list contains a cycle
     *
     * This function uses Floyd's Cycle Detection Algorithm with two pointers:
     * - Tortoise (slow pointer): moves one step at a time
     * - Hare (fast pointer): moves two steps at a time
     *
     * If there's a cycle, the fast pointer will eventually catch up to the slow pointer.
     * If there's no cycle, the fast pointer will reach the end of the list.
     *
     * @param head Pointer to the head of the linked list
     * @return true if the linked list contains a cycle, false otherwise
     *
     * @note A cycle exists when a node's next pointer points to a previous node
     *
     * @example
     * List: 1->2->3->4->2 (cycle back to node 2)
     * Returns: true
     *
     * List: 1->2->3->4->NULL (no cycle)
     * Returns: false
     *
     * @complexity
     * Time Complexity: O(n) where n is the number of nodes in the list
     * Space Complexity: O(1) - only uses two pointer variables
     *
     * @algorithm Floyd's Cycle Detection Algorithm
     * 1. Initialize two pointers at head
     * 2. Move tortoise one step, hare two steps
     * 3. If they meet, cycle exists
     * 4. If hare reaches NULL, no cycle
     */
    bool hasCycle(ListNode *head)
    {
        // Base case: empty list or single node cannot have a cycle
        if (!head || !head->next)
            return false;

        // Initialize both pointers at the head of the list
        ListNode *hare = head;     // Fast pointer (moves 2 steps)
        ListNode *tortoise = head; // Slow pointer (moves 1 step)

        // Continue until hare reaches the end or finds a cycle
        while (hare && hare->next)
        {
            hare = hare->next->next;   // Move hare 2 steps forward
            tortoise = tortoise->next; // Move tortoise 1 step forward

            // If pointers meet, a cycle is detected
            if (hare == tortoise)
                return true;
        }

        // Hare reached the end, no cycle found
        return false;
    }
};