#include <buffer.hpp>
#include <editor.hpp>
#include <string>

#include <ncurses.h>

int main(int argc, char **argv)
{
    text::LineBuffer my_line_buffer;
    Editor editor(my_line_buffer);

    my_line_buffer.AppendLine("First Line Appended");
    my_line_buffer.AppendLine("Second Line Appended");
    my_line_buffer.AppendLine("Third Line Appended");
    my_line_buffer.InsertLine(2, "First Line Inserted");
    my_line_buffer.InsertText(1, 7, "Some Text Inserted ");

    initscr();

    raw();                // we dont want to buffer until carriage return, we want keypresses immediatly
    keypad(stdscr, TRUE); // needed for function keys and arrow keys
    noecho();             // we want to be interactive so let the programe handle what keypresses become text and what are commands

    int screen_cols, screen_rows;
    getmaxyx(stdscr, screen_rows, screen_cols);

    int screen_x, screen_y;
    int buffer_x, buffer_y;
    int cursor_x, cursor_y;

    printw("%s", my_line_buffer.ToString().c_str());

    int ch;
    while ((ch = getch()) != 27)
    {
        getyx(stdscr, editor.cursor_y, editor.cursor_x);
            /* get the current curser position */

        switch (ch)
        {
        case KEY_UP:
                editor.MoveUp();
            break;

        case KEY_DOWN:
                editor.MoveDown();
            break;

        case KEY_LEFT:
                editor.MoveLeft();
            break;

        case KEY_RIGHT:
                editor.MoveRight();
            break;

        case KEY_HOME:
                editor.MoveToLineStart();
            break;

        case KEY_END:
                editor.MoveToLineEnd();
            break;

        case KEY_PPAGE:
                // editor.MoveToLineStart();
            break;

        case KEY_NPAGE:
                // editor.MoveToLineEnd();
            break;

        case 10:
            editor.SplitLine();
            break;


        default:
                editor.InsertText(std::string(1, ch));
                editor.MoveRight();
            break;
        }

        attroff(A_REVERSE|A_BLINK);			/* JUST IN CASE WE SWITCHED IT ON A PREVIOUS LOOP */
        move(0, 0);
        printw("%s", my_line_buffer.ToString().c_str());

        move(editor.cursor_y, editor.cursor_x);
        attron(A_REVERSE|A_BLINK);			/* cut bold on */

        attroff(A_REVERSE|A_BLINK);			/* JUST IN CASE WE SWITCHED IT ON A PREVIOUS LOOP */
        // move(0, 0);

        // refresh();
        // move(screen_rows-1, 2);
        // printw(" %d %d ", screen_y, screen_x);

        refresh();
    }

    endwin();

    fprintf(stdout, "%s", my_line_buffer.ToString().c_str());

    return 0;
}
