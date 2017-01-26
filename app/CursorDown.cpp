#include "CursorDown.hpp"

void CursorDown::execute(EditorModel& model)
{
	previousDownColumn = model.cursorColumn();
	model.moveDown();

}

void CursorDown::undo(EditorModel& model)
{
	model.setCursorLine(model.cursorLine() - 1);
	model.setCursorColumn(previousDownColumn);

}