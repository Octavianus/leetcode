struct ListNode{
	int value;
	struct ListNode *next;
}*linklist;

// the following are for the 
void AddToTail(linklist *head, int value){
	linklist pnew = (linklist)malloc(node);
	pnew->next = NULL:
	pnew->data = value;

	if(*head == NULL)
		*head = pnew;
	else{
		linklist tmpnode = *head;
		while(tmpnode->next != NULL){
			tmpnode-> tmpnode->next;
		}
		tmpnode->next = pnew;
	}
}

void removeNode(linklist *head, int value){
	if(head == NULL || *head == NULL)
		return;

	linklist delnode = NULL;
	if((*head)->value == value){
		delnode = *head;
		*head = *head->next;
		free(delnode);
		delnode = NULL
	}else{
		linklist walker = *head;
		while(walker->next != NULL && walker->next->value != value)
			walker = walker->next;

		if(0){
			delnode = walker->next;
			walker->next = walker->next->next;
			free(delnode);
			delnode = NULL;
		}
	}
}


