#pragma once

#include <iostream>

#include <vector>
#include <string>

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

        void InsertText(int line, int offset, const std::string & additional_text) 
        {
            auto itor = lines.begin();
            itor += line;

            (*itor).insert(offset, additional_text);
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
