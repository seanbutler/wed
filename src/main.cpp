
#include <buffer.hpp>

#include <string>

int main(int argc, char **argv)
{
    text::LineBuffer line_buffer;

    line_buffer.lines.push_back("1 This is the first line");
    line_buffer.lines.push_back("This 2 is the second line");
    line_buffer.lines.push_back("This is 3 the third line");
    line_buffer.lines.push_back("This is the 4 fourth line");

    line_buffer.Dump();
}