#pragma once

#include <string>

namespace text
{
    struct Point
    {
        int line = 0;
        int offset = 0;
    };

    class IOp
    {
    public:
        IOp()
        {
        }

        ~IOp()
        {
        }

    };

    class Insert : public IOp
    {
    public:
        Insert(const std::string &text, const Point &at)
            : IOp()
            , text_(text)
            , at_(at)
        {
        }

        Point at_;
        std::string text_;
    };


    class Delete : public IOp
    {
    public:
        Delete(const Point &at, const Point &to)
            : at_(at), to_(to)
        {
        }

        Point at_;
        Point to_;
    };

}
