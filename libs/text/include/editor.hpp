#include <buffer.hpp>

#pragma once

class Editor
{
public:
    Editor(text::LineBuffer &buffer)
        : cursor_x(0), cursor_y(0), line_buffer(buffer)
    {
    }

    virtual ~Editor()
    {
    }

    void MoveUp()
    {
        --cursor_y;
        if (cursor_x > line_buffer.GetLineLength(cursor_y) - 1)
        {
            cursor_x = line_buffer.GetLineLength(cursor_y) - 1;
        }
    }

    void MoveDown()
    {
        ++cursor_y;

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
    }

    void MoveRight()
    {

        if (cursor_x < line_buffer.GetLineLength(cursor_y) )
        {
            ++cursor_x;
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

    void InsertLine(std::string additional_text = "") {
        line_buffer.InsertLine(cursor_y, additional_text);        
    }

    void SplitLine()
    {
        line_buffer.InsertLine(cursor_y);
    }

    void Overwrite()
    {
    }

    void Delete()
    {
    }

    void SaveFile()
    {
    }

    void LoadFile()
    {
    }

    int cursor_x;
    int cursor_y;
    text::LineBuffer &line_buffer;
};
