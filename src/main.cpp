#include <buffer.hpp>
#include <editor.hpp>
#include <string>

#include <ncurses.h>
#include <cctype>

#define KEY_ESC 27

int main(int argc, char **argv)
{
    text::LineBuffer my_line_buffer;
    Editor editor(my_line_buffer);

    std::string filename("README.md");

    if (argc == 2)
    {
        filename = argv[1];
    }

    my_line_buffer.FromFile(filename);

    initscr();

    raw();                // we dont want to buffer until carriage return, we want keypresses immediatly
    // cbreak();

    keypad(stdscr, TRUE); // needed for function keys and arrow keys
    noecho();             // we want to be interactive so let the programe handle what keypresses become text and what are commands

    int screen_cols, screen_rows;
    getmaxyx(stdscr, screen_rows, screen_cols);

    int buffer_x, buffer_y;
    int cursor_x, cursor_y;

    // printw("%s", my_line_buffer.ToString().c_str());

    enum EditMode
    {
        MODE_EDIT,
        MODE_COMMAND
    };
    enum EditMode edit_mode = MODE_EDIT;

    bool running = true;
    while (running == true)
    {

        int ch;
        ch = getch();

        switch (edit_mode)
        {
        case MODE_EDIT:
            if (ch == KEY_ESC)
                edit_mode = MODE_COMMAND;
            break;

        case MODE_COMMAND:
            if (ch == KEY_ESC)
                edit_mode = MODE_EDIT;
            break;
        }

        switch (edit_mode)
        {
        case MODE_EDIT:

            getyx(stdscr, editor.cursor_y, editor.cursor_x);
            /* get the current curser position */

            switch (ch)
            {
            case KEY_F(12):
                running = false;
                break;

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

            case KEY_ENTER:
                editor.SplitLine();
                break;

            default:
                if (std::isprint(ch))
                {
                    editor.InsertText(std::string(1, ch));
                    editor.MoveRight();
                }
                break;
            }

            break;
        }

#if 1
        move(screen_rows - 1, 0);
        attron(A_REVERSE);

        std::string status_line_text = "[" + std::to_string(editor.cursor_y) + " " + std::to_string(editor.cursor_x) + "]";

        int pad_size = screen_cols - status_line_text.length();
        std::string status_line = status_line_text + std::string(pad_size, ' ');

        printw("%s", status_line.c_str());
        attroff(A_REVERSE);
#endif


        attroff(A_REVERSE | A_BLINK);
        move(0, 0);

        // HERE - adjust this so we only print out a screen's worth of lines

        printw("%s", my_line_buffer.ToString().c_str());

        attron(A_REVERSE | A_BLINK);
        move(editor.cursor_y, editor.cursor_x);
        attroff(A_REVERSE | A_BLINK);



        refresh();
    }
    endwin();

    std::cout << my_line_buffer.ToString();

    return 0;
}
