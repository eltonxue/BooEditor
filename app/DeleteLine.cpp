#include "DeleteLine.hpp"

void DeleteLine::execute(EditorModel& model)
{
	previousLine = model.line(model.cursorLine());
	previousLineNumber = model.cursorLine();
	previousColumn = model.cursorColumn();
	model.deleteLine();

}

void DeleteLine::undo(EditorModel& model)
{
	model.undoDeleteLine(previousLine, previousColumn, previousLineNumber);
}