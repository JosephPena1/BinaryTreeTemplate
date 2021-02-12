#include "TreeNode.h"
#include <iostream>
#include "raylib.h"

TreeNode::TreeNode(int value)
{
	m_value = value;
}

void TreeNode::draw(int x, int y, bool selected)
{
	//creates an array to store the value converted to a string.
	static char buffer[10];

	//converts the value given to a string and stores it in the buffer.
	sprintf(buffer, "%d", m_value);

	//draws the outline for node.
	DrawCircle(x, y, 30, YELLOW);

	//If the node is selected, make the color green, else make it black.
	if (selected)
		DrawCircle(x, y, 28, GREEN);
	else
		DrawCircle(x, y, 28, BLACK);

	//draws the text in the center of the node.
	DrawText(buffer, x - 12, y - 12, 12, WHITE);
}