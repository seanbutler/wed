#include <buffer.hpp>

#pragma once

class Editor
{
public:
    int cursor_x;
    int cursor_y;
    text::LineBuffer &line_buffer;

    Editor(text::LineBuffer &buffer)
        : cursor_x(0), cursor_y(0), line_buffer(buffer)
    {
    }

    virtual ~Editor()
    {
    }

    void MoveUp()
    {
        if (cursor_y > 0)
        {
            --cursor_y;
        }

        if (cursor_x > line_buffer.GetLineLength(cursor_y))
        {
            cursor_x = line_buffer.GetLineLength(cursor_y);
        }
    }

    void MoveDown()
    {
        if (cursor_y < line_buffer.lines.size())
        {
            ++cursor_y;
        }

        if (cursor_x > line_buffer.GetLineLength(cursor_y))
        {
            cursor_x = line_buffer.GetLineLength(cursor_y);
        }
    }

    void MoveLeft()
    {
        if (cursor_x > 0)
        {
            --cursor_x;
        }
        else
        {
            --cursor_y;
            cursor_x = line_buffer.GetLineLength(cursor_y);
        }
    }

    void MoveRight()
    {
        if (cursor_x < line_buffer.GetLineLength(cursor_y))
        {
            ++cursor_x;
        }
        else
        {
            ++cursor_y;
            cursor_x = 0;
        }
    }

    void MoveToLineStart()
    {
        cursor_x = 0;
    }

    void MoveToLineEnd()
    {
        cursor_x = line_buffer.GetLineLength(cursor_y);
    }

    void InsertText(std::string additional_text)
    {
        line_buffer.InsertText(cursor_y, cursor_x, additional_text);
    }

    void InsertLine(std::string additional_text = "")
    {
        line_buffer.InsertLine(cursor_y, additional_text);
    }

    void SplitLine()
    {
        std::string tmp_buffer;
        tmp_buffer = line_buffer.lines[cursor_y];

        std::string tmp_buffer1 = tmp_buffer.substr(0, cursor_x);
        std::string tmp_buffer2 = tmp_buffer.substr(cursor_x, tmp_buffer.length() - cursor_x);

        line_buffer.DeleteLine(cursor_y);

        line_buffer.InsertLine(cursor_y, tmp_buffer1);
        line_buffer.InsertLine(++cursor_y, tmp_buffer2);
        cursor_x = 0;
    }


    void JoinLines()
    {
        cursor_x = line_buffer.lines[cursor_y-1].length();
        line_buffer.lines[cursor_y-1]+=line_buffer.lines[cursor_y];

        std::vector<std::string>::iterator line_iterator;
        line_iterator = line_buffer.lines.begin() + cursor_y;
        line_buffer.lines.erase(line_iterator);
        
    }

    void Overwrite()
    {
    }

    void Backspace()
    {
        if (cursor_y <= line_buffer.lines.size())
        {
            if (cursor_x > 0)
            {
                --cursor_x;

                if (cursor_x < line_buffer.GetLineLength(cursor_y))
                {
                    line_buffer.DeleteText(cursor_y, cursor_x, 1);
                }
            }
            else
            {
                if (cursor_y > 0)
                {
                    // append the current line on to the end previous line
                    JoinLines();
                    --cursor_y;
                }
            }
        }
    }

    void Delete()
    {
        if (cursor_x < line_buffer.GetLineLength(cursor_y))
        {
            line_buffer.DeleteText(cursor_y, cursor_x, 1);
        }
    }

    void NextPage()
    {
    }

    void PreviousPage()
    {
    }

    void SaveFile(std::string filename)
    {
        line_buffer.ToFile(filename);
    }

    void LoadFile(std::string filename)
    {
        line_buffer.FromFile(filename);
    }
};
