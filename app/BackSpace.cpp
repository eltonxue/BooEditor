#include "BackSpace.hpp"

void BackSpace::execute(EditorModel& model)
{
	previousColumn = model.cursorColumn();
	model.backSpace();
	character = model.getPreviousCharacter();
	
}

void BackSpace::undo(EditorModel& model)
{

	if (previousColumn == 1)
	{
		model.newLine();
	}
	else
	{
		model.insertCharacter(character);
	}
	
}