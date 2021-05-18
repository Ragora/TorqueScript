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

#include <memory>
#include <string>

#include <torquescript/storedvalue.hpp>

namespace TorqueScript
{
    class Interpreter;
    class ExecutionScope;
    class SimObject;

    /**
     *  @brief Storage class for a floating point value.
     */
    class StoredFieldReferenceValue : public StoredValue
    {
        public:
            StoredFieldReferenceValue(std::shared_ptr<SimObject> object, const std::string& name, Interpreter* interpreter);

            virtual int toInteger(ExecutionScope* scope) override;
            virtual float toFloat(ExecutionScope* scope) override;
            virtual std::string toString(ExecutionScope* scope) override;
            virtual bool setValue(std::shared_ptr<StoredValue> newValue, ExecutionScope* scope) override ;

        protected:
            //! The Sim object reference.
            std::shared_ptr<SimObject> mSimObject;

            //! The stored field name.
            std::string mName;
    };
}
