#include "../include/buffer.hpp"

#include <stdio.h>
#include <string.h>

void lib_text_buffer_empty_size()
{
    text::LineBuffer line_buffer;

    // TEST 1 - empty buffer should have zero length
    if (line_buffer.lines.size() != 0)
    {
        exit(1);
    }
}

void lib_text_buffer_thrice_appended_size()
{
    text::LineBuffer line_buffer;

    std::string demo_string1 = "The first line appended";
    std::string demo_string2 = "The second line appended";
    std::string demo_string3 = "The third line appended";

    line_buffer.AppendLine(demo_string1);
    line_buffer.AppendLine(demo_string2);
    line_buffer.AppendLine(demo_string3);

    // TEST 2 - thrice appended buffer should have length 3
    if (line_buffer.lines.size() != 3)
    {
        exit(1);
    }
}

void lib_text_buffer_thrice_appended_content()
{
    text::LineBuffer line_buffer;

    std::string demo_string1 = "The first line appended";
    std::string demo_string2 = "The second line appended";
    std::string demo_string3 = "The third line appended";

    line_buffer.AppendLine(demo_string1);
    line_buffer.AppendLine(demo_string2);
    line_buffer.AppendLine(demo_string3);

    std::cout << line_buffer.lines[1] << std::endl;
    std::cout << demo_string2 << std::endl;
    std::cout << line_buffer.lines[1].compare(demo_string2) << std::endl;

    // TEST 3 - middle appended line content must match
    if (line_buffer.lines[1].compare(demo_string2) != 0)
    {
        exit(1);
    }
}

void lib_text_buffer_append_insert_size()
{
    text::LineBuffer line_buffer;

    std::string demo_string1 = "The first line appended";
    std::string demo_string2 = "The second line appended";
    std::string demo_string3 = "The third line appended";
    std::string demo_string4 = "First Inserted text line";

    line_buffer.AppendLine(demo_string1);
    line_buffer.AppendLine(demo_string2);
    line_buffer.AppendLine(demo_string3);

    line_buffer.InsertLine(2, demo_string4);

    // TEST 4 - thrice appended and inserted buffer should have length 4
    if (line_buffer.lines.size() != 4)
    {
        exit(1);
    }
}

void lib_text_buffer_append_insert_contents()
{
    text::LineBuffer line_buffer;

    std::string demo_string1 = "The first line appended";
    std::string demo_string2 = "The second line appended";
    std::string demo_string3 = "The third line appended";
    std::string demo_string4 = "First Inserted text line";

    line_buffer.AppendLine(demo_string1);
    line_buffer.AppendLine(demo_string2);
    line_buffer.AppendLine(demo_string3);

    line_buffer.InsertLine(2, demo_string4);

    // TEST 5 - thrice appended and inserted buffer should have length 4

    if (line_buffer.lines[0].compare(demo_string1) != 0)
    {
        exit(1);
    }

    if (line_buffer.lines[1].compare(demo_string2) == 0)
    {
        exit(1);
    }

    if (line_buffer.lines[2].compare(demo_string4) != 0)
    {
        exit(1);
    }

    if (line_buffer.lines[3].compare(demo_string3) != 0)
    {
        exit(1);
    }

}

int main(int argc, char **argv)
{
    if (argc != 0 )
    {
        std::cout << "This is a Unit Test App" << std::endl;
        exit(0);
    }

    if (argc == 1 && (strcmp(argv[1], "1") == 0))
    {
        lib_text_buffer_empty_size();
    }

    if (argc == 1 && (strcmp(argv[1], "2") == 0))
    {
        lib_text_buffer_thrice_appended_size();
    }

    if (argc == 1 && (strcmp(argv[1], "3") == 0))
    {
        lib_text_buffer_thrice_appended_content();
    }

    if (argc == 1 && (strcmp(argv[1], "4") == 0))
    {
        lib_text_buffer_append_insert_size();
    }

    if (argc == 1 && (strcmp(argv[1], "5") == 0))
    {
        lib_text_buffer_append_insert_contents();
    }

    return 0;
}
