#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct
{
	element array[MAX_LIST_SIZE];
	int size;
	int flag;
} ArrayListType;

void error(char* message)
{
	return;
}

void init(ArrayListType* L)
{
	L->size = 0;
	L->flag = 0;
}

int is_empty(ArrayListType* L)
{
	return L->size == 0;
}

int is_full(ArrayListType* L)
{
	return L->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType* L, int pos)
{
	if (pos < 0 || pos >= L->size)
		error("Pos Error");
	return L->array[pos];
}

void print_list(ArrayListType* L)
{
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_last(ArrayListType* L, element item)
{
	if (L->size >= MAX_LIST_SIZE)
		error("List Overflow");
	L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item)
{
	if (!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for (int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i + 1] = L->array[i];
			L->flag++;
		}
		L->array[pos] = item;
		L->size++;
	}
}

element delete(ArrayListType* L, int pos)
{
	element item;

	if (pos < 0 || pos >= L->size)
		error("Pos Error");
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++)
	{
		L->array[i] = L->array[i + 1];
		L->flag++;
	}
	L->size--;
	return item;
}

int main()
{
	ArrayListType list;
	int choice, num, pos;
	element tmp;

	init(&list);

	while (1)
	{
		printf("===========M E N U==========\n");
		printf("<1> Insert\n");
		printf("<2> Delete\n");
		printf("<3> Print\n");
		printf("<4> Exit\n");
		printf("Choose menu : ");
		scanf_s("%d", &choice);

		if (choice == 1)
		{
			printf("Type the number and position : ");
			scanf_s("%d %d", &num, &pos);
			if (pos > list.size)
				printf("List size is now 0, Try again with pos 0\n");
			else
			{
				insert(&list, pos, num);
				printf("Insert %d in %d\n", num, pos);
				printf("\n");
				printf("Move : %d\n", list.flag);
			}
		}

		else if (choice == 2)
		{
			if (is_empty(&list))
				printf("List is empty\n");
			else
			{ 
				printf("Type position : ");
				scanf_s("%d", &pos);
				tmp = delete(&list, pos);
				printf("\n");
				printf("Move : %d\n", list.flag);
				printf("Delete : %d\n", tmp);
			}
		}

		else if (choice == 3)
		{
			print_list(&list);
		}

		else if (choice == 4)
		{
			printf("Exit Menu\n");
			break;
		}

		else
		{
			printf("EXIT IS 4");
			break;
		}
		printf("\n");
		list.flag = 0;
	}
}