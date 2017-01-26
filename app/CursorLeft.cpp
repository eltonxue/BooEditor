#include "CursorLeft.hpp"

void CursorLeft::execute(EditorModel& model)
{
	model.moveLeft();
}

void CursorLeft::undo(EditorModel& model)
{
	model.moveRight();
	
}