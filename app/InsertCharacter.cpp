#include "InsertCharacter.hpp"

void InsertCharacter::execute(EditorModel& model)
{
	model.insertCharacter(character);
}

void InsertCharacter::undo(EditorModel& model)
{
	model.backSpace();
}	