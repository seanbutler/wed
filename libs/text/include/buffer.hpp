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

        void InsertLine(int index = 0, const std::string &line = "")
        {
            auto itor = lines.begin();
            itor += index;
            lines.insert(itor, line);
        }

        void AppendLine(const std::string &line)
        {
            lines.push_back(line);
        }

        void DeleteLine(int index = 0)
        {
            auto itor = lines.begin();
            itor += index;
            lines.erase(itor);
        }

        void Dump()
        {
            for (auto L : lines)
            {
                std::cout << L << std::endl;
            }
        }
    };
}
