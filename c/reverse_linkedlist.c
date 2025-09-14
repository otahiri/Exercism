struct ListNode* reverseList(struct ListNode* head) {
    int i;
    ListNode *current = NULL;
    ListNode *previous = head;

	i = 0;
	if (head == NULL)
		return head;
	previous->next = NULL;
	while (head->next != NULL)
	{
		head = head->next;
		current = head;
		current->next = previous;
		previous = current;
	}
	return previous;
}
