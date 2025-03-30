#include <buffer.hpp>
#include <string>

int main(int argc, char **argv)
{
    text::LineBuffer line_buffer;

    line_buffer.AppendLine("First Line Appended");
    line_buffer.AppendLine("Second Line Appended");
    line_buffer.AppendLine("Third Line Appended");

    line_buffer.Dump();

    line_buffer.InsertLine(2, "First Line Inserted");


    line_buffer.Dump();
}

