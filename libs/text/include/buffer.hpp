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

        void DeleteToLineEnd(int line = 0, int offset = 0)
        {
            auto itor = lines.begin();
            itor += line;

            int length = (*itor).length();
            std::string new_shorter_string;

            if (length > offset)
            {
                new_shorter_string = (*itor).substr(0, offset);
                (*itor) = new_shorter_string;
            }
        }

        void DeleteToLineStart(int line = 0, int offset = 0)
        {
            auto itor = lines.begin();
            itor += line;

            int length = (*itor).length();
            std::string new_shorter_string;

            if ((offset > 0) && (length > offset))
            {
                new_shorter_string = (*itor).substr(offset, length-offset);
                (*itor) = new_shorter_string;   
            }
        }

        void InsertText(int line, int offset, const std::string &additional_text)
        {
            auto itor = lines.begin();
            itor += line;

            (*itor).insert(offset, additional_text);
        }

        void DeleteText(int line, int offset1, int offset2)
        {
            auto itor = lines.begin();
            itor += line;

            // WORKING HERE
        }

        int GetLineLength(int line) {
            auto itor = lines.begin();
            itor += line;

            return itor->length();
        }


        void Dump()
        {
            for (auto L : lines)
            {
                std::cout << L << std::endl;
            }
        }


        std::string ToString()
        {
            std::string local;
            for (auto L : lines)
            {
                local += L + "\n";
            }
            return local;
        }        
    };
}
