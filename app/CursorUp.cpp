#include "CursorUp.hpp"

void CursorUp::execute(EditorModel& model)
{
	previousUpColumn = model.cursorColumn();
	model.moveUp();

}

void CursorUp::undo(EditorModel& model)
{
	model.setCursorLine(model.cursorLine() + 1);
	model.setCursorColumn(previousUpColumn);

}