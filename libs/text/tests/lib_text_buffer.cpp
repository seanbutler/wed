#include "../include/buffer.hpp"

#include <stdio.h>
#include <string.h>

int lib_text_buffer_empty_size()
{
    text::LineBuffer line_buffer;

    // TEST 1 - empty buffer should have zero length
    if (line_buffer.lines.size() != 0)
    {
        return 1;
    }

    return 0;
}

int lib_text_buffer_thrice_appended_size()
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
        return 1;
    }

    return 0;
}

int lib_text_buffer_thrice_appended_content()
{
    text::LineBuffer line_buffer;

    std::string demo_string1 = "The first line appended";
    std::string demo_string2 = "The second line appended";
    std::string demo_string3 = "The third line appended";

    line_buffer.AppendLine(demo_string1);
    line_buffer.AppendLine(demo_string2);
    line_buffer.AppendLine(demo_string3);

    // std::cout << line_buffer.lines[1] << std::endl;
    // std::cout << demo_string2 << std::endl;
    // std::cout << line_buffer.lines[1].compare(demo_string2) << std::endl;

    // TEST 3 - middle appended line content must match
    if (line_buffer.lines[1].compare(demo_string2) != 0)
    {
        return 1;
    }

    return 0;
}

int lib_text_buffer_append_insert_size()
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
        return 1;
    }

    return 0;
}

int lib_text_buffer_append_insert_contents()
{
    text::LineBuffer line_buffer;

    std::string demo_string1 = "The first line appended";
    std::string demo_string2 = "The second line appended";
    std::string demo_string3 = "The third line appended";

    line_buffer.AppendLine(demo_string1);
    line_buffer.AppendLine(demo_string2);
    line_buffer.AppendLine(demo_string3);

    std::string demo_inserted_string = "First Inserted line";

    line_buffer.InsertLine(2, demo_inserted_string);

    // TEST 5 - thrice appended and inserted buffer should have length 4

    line_buffer.Dump();

    if (line_buffer.lines[0].compare(demo_string1) != 0)
    {
        return (1);
    }

    if (line_buffer.lines[1].compare(demo_string2) != 0)
    {
        return (1);
    }

    if (line_buffer.lines[2].compare(demo_inserted_string) != 0)
    {
        return (1);
    }

    if (line_buffer.lines[3].compare(demo_string3) != 0)
    {
        return (1);
    }

    return 0;
}

int lib_text_buffer_line_insert_text()
{
    text::LineBuffer line_buffer;

    std::string demo_string1 = "The first line appended";
    std::string demo_string2 = "The second line appended";
    std::string demo_string3 = "The third line appended";

    line_buffer.AppendLine(demo_string1);
    line_buffer.AppendLine(demo_string2);
    line_buffer.AppendLine(demo_string3);


    std::string demo_string4 = "Inserted Text ";
    std::string demo_goal = "The second line Inserted Text appended";

    line_buffer.InsertText(1, 16, demo_string4);

    line_buffer.Dump();

    if (line_buffer.lines[1].compare(demo_goal) != 0)
    {
        return 1;
    }

    return 0;
}



int lib_text_buffer_delete_to_line_end()
{
    text::LineBuffer line_buffer;

    std::string demo_string1 = "The first line appended";
    std::string demo_string2 = "The second line appended";
    std::string demo_string3 = "The third line appended";

    line_buffer.AppendLine(demo_string1);
    line_buffer.AppendLine(demo_string2);
    line_buffer.AppendLine(demo_string3);

    std::string demo_goal = "The second";

    line_buffer.DeleteToLineEnd(1, 10);

    line_buffer.Dump();

    if (line_buffer.lines[1].compare(demo_goal) != 0)
    {
        return 1;
    }

    return 0;
}


int lib_text_buffer_delete_to_line_start()
{
    text::LineBuffer line_buffer;

    std::string demo_string1 = "The first line appended";
    std::string demo_string2 = "The second line appended";
    std::string demo_string3 = "The third line appended";

    line_buffer.AppendLine(demo_string1);
    line_buffer.AppendLine(demo_string2);
    line_buffer.AppendLine(demo_string3);

    std::string demo_goal = "XXX";

    line_buffer.DeleteToLineStart(1, 16);

    line_buffer.Dump();

    if (line_buffer.lines[1].compare(demo_goal) != 0)
    {
        return 1;
    }

    return 0;
}


int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Unit Test App " << argv[0] << " : Include a Command Line Argument for the Test Number to Run" << std::endl;
        return 1;
    }

    if (argc == 2)
    {
        if ((strcmp(argv[1], "1") == 0))
        {
            return lib_text_buffer_empty_size();
        }
        else if ((strcmp(argv[1], "2") == 0))
        {
            return lib_text_buffer_thrice_appended_size();
        }
        else if ((strcmp(argv[1], "3") == 0))
        {
            return lib_text_buffer_thrice_appended_content();
        }
        else if ((strcmp(argv[1], "4") == 0))
        {
            return lib_text_buffer_append_insert_size();
        }
        else if ((strcmp(argv[1], "5") == 0))
        {
            return lib_text_buffer_append_insert_contents();
        }
        else if ((strcmp(argv[1], "6") == 0))
        {
            return lib_text_buffer_line_insert_text();
        }
        else if ((strcmp(argv[1], "7") == 0))
        {
            return lib_text_buffer_delete_to_line_end();
        }
        else if ((strcmp(argv[1], "8") == 0))
        {
            return lib_text_buffer_delete_to_line_start();
        }
        else
        {
            return 1;
        }
    }

    return 0;
}
