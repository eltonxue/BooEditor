#include "CursorEnd.hpp"

void CursorEnd::execute(EditorModel& model)
{
	previousColumn = model.cursorColumn();
	model.moveEnd();

}

void CursorEnd::undo(EditorModel& model)
{
	model.setCursorColumn(previousColumn);
	
}