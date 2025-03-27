#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace text
{
    class LineBuffer
    {
    public:
        std::vector<std::string> lines;

        void Dump()
        {
            for (auto L : lines)
            {
                std::cout << L << std::endl;
            }
        }
    };
}