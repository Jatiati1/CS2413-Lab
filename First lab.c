/**
 * removeElements - Removes all nodes in a linked list that contain the specified value.
 * @head: Pointer to the head of the linked list.
 * @val: The value to be removed from the list.
 *
 * Return: Pointer to the head of the modified linked list.
 *
 * This function iterates through the linked list and removes every node that matches
 * the target value. It first adjusts the head if the initial nodes contain the target,
 * then traverses the rest of the list using two pointers to remove matching nodes.
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Remove nodes from the beginning that have the target value.
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;  // Store the current head node.
        head = head->next;             // Advance the head to the next node.
        free(temp);                    // Free the memory of the removed node.
    }
    
    // If the list becomes empty, return NULL.
    if (head == NULL) {
        return head;
    }
    
    // Initialize pointers for list traversal.
    // 'prev' points to the last node that does not need removal.
    // 'curr' points to the node following 'prev'.
    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    
    // Traverse the list, removing nodes that match the target value.
    while (curr != NULL) {
        if (curr->val == val) {
            // Bypass the current node by linking 'prev' to 'curr->next'.
            prev->next = curr->next;
            free(curr);            // Free the memory of the removed node.
            curr = prev->next;     // Update 'curr' to the next node.
        } else {
            // Move both pointers forward when the current node does not match the target.
            prev = curr;
            curr = curr->next;
        }
    }
    
    // Return the head of the modified list.
    return head;
}





/**
 * reverseList - Reverses a singly-linked list using an auxiliary stack.
 * @head: Pointer to the head of the linked list.
 *
 * Return: Pointer to the head of the reversed linked list.
 *
 * This function reverses the given linked list by first counting the nodes,
 * then storing pointers to each node in an array acting as a stack, and finally
 * rebuilding the list in reverse order by popping the nodes from the stack.
 */
struct ListNode* reverseList(struct ListNode* head) {
    // Return NULL immediately if the list is empty.
    if (head == NULL) {
        return NULL;
    }

    // 1. Count the number of nodes in the linked list.
    int count = 0;
    struct ListNode* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    // 2. Allocate an array of node pointers to serve as a stack.
    struct ListNode** stack = (struct ListNode**)malloc(count * sizeof(struct ListNode*));
    if (stack == NULL) {
        // Return NULL if memory allocation fails.
        return NULL;
    }

    // 3. Push all node pointers onto the stack.
    curr = head;
    int i = 0;
    while (curr != NULL) {
        stack[i++] = curr;
        curr = curr->next;
    }

    // 4. Pop from the stack to rebuild the list in reverse order.
    // The first node popped becomes the new head.
    struct ListNode* newHead = stack[--i];
    struct ListNode* newCurr = newHead;

    // Continue popping nodes until the stack is empty,
    // linking them to form the reversed list.
    while (i > 0) {
        newCurr->next = stack[--i];
        newCurr = newCurr->next;
    }
    // Set the next pointer of the final node to NULL.
    newCurr->next = NULL;

    // Free the allocated memory for the stack.
    free(stack);

    // Return the head of the reversed linked list.
    return newHead;
}
