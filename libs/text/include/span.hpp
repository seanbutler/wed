#pragma once

#include <iostream>

#include <vector>
#include <string>

namespace text
{
    struct Point
    {
        int line;
        int offset;
    };

    struct Span
    {
        Point from;
        Point to;
    };
}
