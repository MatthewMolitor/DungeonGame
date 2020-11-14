#include "CharacterNode.h"



CharacterNode::CharacterNode(Enemy &enemy, CharacterNode* pNext):
	_enemy(enemy), _pNext(pNext)
{
}


CharacterNode::~CharacterNode()
{
}
