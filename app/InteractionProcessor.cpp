// InteractionProcessor.cpp
//
// ICS 45C Fall 2016
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.



void InteractionProcessor::run()
{
    view.refresh();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            for (auto c = commandStack.begin(); c < commandStack.end(); ++c)
            {
                delete *c;
            }
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (undoStack.size() > 0)
            {
                Command* command = undoStack.back();

                command->undo(model);
                redoStack.push_back(command);
                undoStack.pop_back();
                model.clearErrorMessage();
                
            }

            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (redoStack.size() > 0)
            {
                Command* command = redoStack.back();

                command->execute(model);
                undoStack.push_back(command);
                redoStack.pop_back();
                model.clearErrorMessage();
            }

            view.refresh();

        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command(); // dynamic allocation
            commandStack.push_back(command); // all commands

            try
            {
                command->execute(model);

                redoStack.clear();

                undoStack.push_back(command);

                model.clearErrorMessage();

            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
        }
    }
}

