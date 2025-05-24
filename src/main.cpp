#include <buffer.hpp>
#include <string>

#include <ncurses.h>

int main(int argc, char **argv)
{
    text::LineBuffer line_buffer;

    line_buffer.AppendLine("First Line Appended");
    line_buffer.AppendLine("Second Line Appended");
    line_buffer.AppendLine("Third Line Appended");
    line_buffer.InsertLine(2, "First Line Inserted");
    line_buffer.InsertText(1, 7, "Some Text Inserted ");

    initscr();

    printw("%s", line_buffer.ToString().c_str());

    refresh();

    getch();

    endwin();

}