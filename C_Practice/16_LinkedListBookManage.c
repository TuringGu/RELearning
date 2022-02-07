#include "16_LinkedListBookManage.h"

int main()
{
	Node * head = NULL;
	char szBookName[50];
	char szNewBookName[50];
	float fBookPrice;
	float fNewBookPrice;
	int nBookNumber;
	int Readflag = 0;	// User choice

	// Initial
	head = AppendNode(head, "1", 1, 1.0);
	head = AppendNode(head, "2", 2, 2.0);
	head = AppendNode(head, "3", 3, 3.0);
	head = AppendNode(head, "4", 4, 4.0);

	while (1)
	{
		printf("Enter your choice: \n");
		printf("0.Exit\n1.Append\n2.Query\n3.Modify\n4.delete\n");
		scanf("%d", &Readflag);
		switch (Readflag)
		{
		case flagExit:
			printf("Bye!\n");
			return 0;
			break;
		case flagAppend:
			printf("Enter book name: ");
			scanf("%s", szBookName);
			printf("Enter book price: ");
			scanf("%f", &fBookPrice);
			printf("Enter book number: ");
			scanf("%d", &nBookNumber);
			head = AppendNode(head, szBookName, nBookNumber, fBookPrice);
			break;
		case flagQuery:
			printf("Enter book name: ");
			scanf("%s", szBookName);
			QueryNode(head, szBookName);
			break;
		case flagModify:
			printf("Enter book name: ");
			scanf("%s", szBookName);
			printf("Enter book new name: ");
			scanf("%s", szNewBookName);
			printf("Enter the price: ");
			scanf("%f", &fNewBookPrice);
			ModifyNode(head, szBookName, szNewBookName, fNewBookPrice);
			break;
		case flagDelete:
			printf("Enter book name: ");
			scanf("%s", szBookName);
			head = DeleteNode(head, szBookName);
			break;
		default:
			printf("Invalid Input\n");
			break;
		}
	}

	return 0;
}

// Append
Node * AppendNode(Node * head, char *BookName, int BookNumber, float BookPrice)
{
	Node * pNewNode = NULL;
	Node * pNode = head;
	pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL)
	{
		printf("Memory malloc failed!\n");
		exit(0);
	}

	if (head == NULL)
	{
		head = pNewNode;
	}
	else
	{
		while (pNode->next != NULL)
		{
			pNode = pNode->next;
		}
		pNode->next = pNewNode;
		
	}

	strcpy(pNewNode->BookName, BookName);
	pNewNode->BookNumber = BookNumber;
	pNewNode->BookPrice = BookPrice;
	pNewNode->next = NULL;
	printf("Append succeed:\nBookName: %s\tPrice: %f\tNumber: %d\n", pNewNode->BookName, pNewNode->BookPrice, pNewNode->BookNumber);

	return head;
}

// Query
Node * QueryNode(Node * head, char * BookName)
{
	int flag = 0;
	Node * pNode = head;
	if (pNode == NULL)
	{
		printf("head == NULL\n");
		return NULL;
	}

	if (strcmp(BookName, pNode->BookName) == 0)
	{
		printf("BookName: %s\tPrice: %f\tNumber: %d\n", pNode->BookName, pNode->BookPrice, pNode->BookNumber);
		flag = 1;
	}
	while (pNode->next != NULL)
	{
		pNode = pNode->next;
		if (strcmp(BookName, pNode->BookName) == 0)
		{
			printf("BookName: %s\tPrice: %f\tNumber: %d\n", pNode->BookName, pNode->BookPrice, pNode->BookNumber);
			flag = 1;
		}
	}

	if (flag == 0)
	{
		printf("Query failed!\n");
		return NULL;
	}

	return pNode;
}

// Modify
void ModifyNode(Node * head, char * BookName, char * NewBookName, float BookPrice)
{
	Node * pNode = QueryNode(head, BookName);
	if (pNode == NULL)
	{
		printf("Modify failed!\n");
		return;
	}

	strcpy(pNode->BookName, NewBookName);
	pNode->BookPrice = BookPrice;
	printf("After the modified\nBookName: %s\tBookPrice: %f\tNumber: %d\n", pNode->BookName, pNode->BookPrice, pNode->BookNumber);
}

// Delete
Node * DeleteNode(Node * head, char * BookName)
{
	Node * pNode;
	Node * pNodeTemp;

	if (head == NULL)
	{
		printf("Delete failed!\n");
		return head;
	}

	// Delete head node
	if (strcmp(BookName, head->BookName) == 0)	
	{
		if (head->next != NULL)
		{
			pNode = head->next;
			printf("The book %s delete succeed\n", head->BookName);
			free(head);
			return pNode;
		}
		else
		{	
			// When only one element in the list, just return NULL
			printf("The book %s delete succeed\n", head->BookName);
			free(head);
			printf("Now list is NULL!\n");
			return NULL;
		}
	}

	// Delete non-head node
	pNode = head;
	while (pNode->next != NULL)	
	{
		if (strcmp(pNode->next->BookName, BookName) == 0)
		{
			pNodeTemp = pNode->next;
			pNode->next = pNode->next->next;
			printf("The book %s delete succeed\n", pNodeTemp->BookName);
			free(pNodeTemp);
			return head;
		}
		else
		{
			pNode = pNode->next;	// Compare next node
		}
	}

	// pNode->next == NULL, pNode is not the delete target
	printf("The delete target is not exist\n");
	return head;
}

