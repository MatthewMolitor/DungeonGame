#include "CharacterList.h"



CharacterList::CharacterList(int capacity, CharacterNode* node):
	pHead(node)
{
	maxCapacity = capacity;
	numberCharacters = 1;
}


CharacterList::~CharacterList()
{
	CharacterNode* current = pHead;
	CharacterNode* next = pHead->next();
	while (current != 0)
	{
		next = current->next();
		delete current;
		current = next;
	}


}
