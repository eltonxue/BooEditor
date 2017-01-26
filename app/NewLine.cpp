#include "NewLine.hpp"

void NewLine::execute(EditorModel& model)
{
	previousColumn = model.cursorColumn();
	model.newLine();
	previousSubstr = model.getPreviousSubstr();
}

void NewLine::undo(EditorModel& model)
{
	model.undoNewLine(previousSubstr, previousColumn);
}