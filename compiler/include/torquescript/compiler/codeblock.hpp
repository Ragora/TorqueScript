/**
 *  Copyright 2021 Robert MacGregor
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction,
 *  including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 *  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <map>
#include <string>
#include <vector>

#include <torquescript/compiler/instructions.hpp>

namespace TorqueScript
{
    class Variable
    {
        private:
            //! The name of the variable.
            std::string mName;

            //! Whether or not this is a global variable.
            bool mGlobal;
    };

    /**
     *  @brief A function is callable subroutine from anywhere in the language.
     */
    class Function
    {
        private:
            //! The name of the function.
            std::string mName;

            //! All instructions associated with this function.
            std::vector<Instruction> mInstructions;

        public:
    };

    /**
     *  @brief A CodeBlock defines a piece of executable code generated from a single input (Ie. a file).
     *  This includes global executable code and subroutines, datablocks, etc.
     */
    class CodeBlock
    {
        private:
            //! All functions registered in this codeblock.
            std::map<std::string, Function> mFunctions;


    };
}
