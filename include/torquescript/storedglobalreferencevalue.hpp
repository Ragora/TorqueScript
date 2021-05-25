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

#include <string>
#include <memory>

#include <torquescript/storedvalue.hpp>

namespace TorqueScript
{
    class Interpreter;
    class ExecutionState;

    /**
     *  @brief Storage class for a reference to a global value.
     */
    class StoredGlobalReferenceValue : public StoredValue
    {
        public:
            StoredGlobalReferenceValue(const std::string& name);

            virtual int toInteger(std::shared_ptr<ExecutionState> state) override;
            virtual float toFloat(std::shared_ptr<ExecutionState> state) override;
            virtual std::string toString(std::shared_ptr<ExecutionState> state) override;
            virtual std::shared_ptr<StoredValue> getReferencedValueCopy(std::shared_ptr<ExecutionState> state) override;
            virtual bool isInteger(std::shared_ptr<ExecutionState> state) override;

            bool setValue(std::shared_ptr<StoredValue> value, std::shared_ptr<ExecutionState> state) override;
            virtual std::string getRepresentation() override;

        protected:
            //! The name of the referenced variable.
            std::string mName;
    };
}
