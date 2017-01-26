// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2016
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "CursorRight.hpp"
#include "CursorLeft.hpp"
#include "CursorDown.hpp"
#include "CursorUp.hpp"
#include "CursorHome.hpp"
#include "CursorEnd.hpp"
#include "InsertCharacter.hpp"
#include "BackSpace.hpp"
#include "NewLine.hpp"
#include "DeleteLine.hpp"


// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{

    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                {
                    return Interaction::quit();
                }

            case 'Z':
                {
                    return Interaction::undo();
                }

            case 'A':
                {
                   return Interaction::redo(); 
                }

            case 'U':
                {
                    CursorLeft* moveLeft = new CursorLeft;
                    return Interaction::command(moveLeft);
                }
               
            case 'O':
                {
                    CursorRight* moveRight = new CursorRight;
                    return Interaction::command(moveRight);
                }
            case 'K':
                {
                    CursorDown* moveDown = new CursorDown;
                    return Interaction::command(moveDown);
                }
               
            case 'I':
                {
                    CursorUp* moveUp = new CursorUp;
                    return Interaction::command(moveUp);
                }

            case 'Y':
                {
                    CursorHome* moveHome = new CursorHome;
                    return Interaction::command(moveHome);
                }
            case 'P':
                {
                    CursorEnd* moveEnd = new CursorEnd;
                    return Interaction::command(moveEnd);
                }

            case 'H':
                {
                    BackSpace* backspace = new BackSpace;
                    return Interaction::command(backspace);
                }
            case 'J':
                {
                    NewLine* newline = new NewLine;
                    return Interaction::command(newline);
                }
            case 'M':
                {
                    NewLine* newline = new NewLine;
                    return Interaction::command(newline);
                }
            case 'D':
                {
                    DeleteLine* deleteline = new DeleteLine;
                    return Interaction::command(deleteline);
                }

            }
        }
        else
        {
            InsertCharacter* insertCharacter = new InsertCharacter{keypress.code()};
            return Interaction::command(insertCharacter);

            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
        }
    }
}

