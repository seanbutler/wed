#include <buffer.hpp>

#pragma once

class View
{
public:
    View()
        : buffer_cursor_x(0)
        , buffer_cursor_y(0)
        , screen_cursor_x(0)
        , screen_cursor_y(0)
        , rows(0)
        , cols(0)
    {

    }

    virtual ~View()
    {

    }

    //
    // where in the line buffer is the cursor
    //
    int buffer_cursor_x;
    int buffer_cursor_y;

    //
    // size of the screen
    //
    int rows;
    int cols;

    //
    // where on the screen is the cursor
    //
    int screen_cursor_x;
    int screen_cursor_y;
};
