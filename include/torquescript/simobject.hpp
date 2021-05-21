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
#include <memory>

#include <torquescript/storedvalue.hpp>

namespace TorqueScript
{
    class Interpreter;
    class ExecutionScope;
    class Interpreter;

    /**
     *  @brief Storage class used to keep variable values in-memory of arbitrary data types.
     *  This is the base class and should not be instantiated directly.
     */
    class SimObject
    {
        public:
            std::shared_ptr<StoredValue> getField(const std::string& name);
            void setField(const std::string& name, std::shared_ptr<StoredValue> value);

            unsigned int getID(Interpreter* interpreter);
            std::string getName(Interpreter* interpreter);

        protected:
            std::map<std::string, std::shared_ptr<StoredValue>> mValueMap;
    };
}
