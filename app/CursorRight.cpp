#include "CursorRight.hpp"

void CursorRight::execute(EditorModel& model)
{
	model.moveRight();

}

void CursorRight::undo(EditorModel& model)
{
	model.moveLeft();

}