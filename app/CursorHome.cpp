#include "CursorHome.hpp"

void CursorHome::execute(EditorModel& model)
{
	previousColumn = model.cursorColumn();
	model.moveHome();

}

void CursorHome::undo(EditorModel& model)
{
	model.setCursorColumn(previousColumn);
}