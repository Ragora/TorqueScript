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

#include "antlr4-runtime.h"
#include <TorqueBaseListener.h>

#include <torquescript/codeblock.hpp>
#include <torquescript/instructions.hpp>

namespace TorqueScript
{
    /**
     *  @brief Primary compiler class. Here we use a listener to walk the tree generated by ANTLR in order
     *  to generate executable bytecode for the virtual machine.
     */
    class Compiler : public TorqueBaseListener
    {
        public:
            /**
             *  @brief Ask the compiler to generate a codeblock from the provided stream.
             *  @param input The input to generate from.
             */
            CodeBlock* compileStream(std::istream& input);

            /**
             *  @brief Ask the compiler to generate a codeblock from the provided string.
             *  @param input The string to generate from.
             */
            CodeBlock* compileString(const std::string& input);

            /**
             *  @brief Ask the compiler to generate a codeblock from the provided file.
             *  @param path The path to load from.
             */
            CodeBlock* compileFile(const std::string& path);

        public:
            virtual void enterFunctiondeclaration(TorqueParser::FunctiondeclarationContext* context) override;
            virtual void exitFunctiondeclaration(TorqueParser::FunctiondeclarationContext* context) override;

            virtual void enterArithmetic(TorqueParser::ArithmeticContext* context) override;
            virtual void exitArithmetic(TorqueParser::ArithmeticContext* context) override;

            virtual void enterRelational(TorqueParser::RelationalContext* context) override;
            virtual void exitRelational(TorqueParser::RelationalContext* context) override;

            virtual void enterCall(TorqueParser::CallContext* context) override;
            virtual void exitCall(TorqueParser::CallContext* context) override;

            virtual void enterValue(TorqueParser::ValueContext* context) override;
            virtual void exitValue(TorqueParser::ValueContext* context) override;

            virtual void enterConcatenation(TorqueParser::ConcatenationContext* context) override;
            virtual void exitConcatenation(TorqueParser::ConcatenationContext* context) override;

            virtual void enterUnary(TorqueParser::UnaryContext* context) override;
            virtual void exitUnary(TorqueParser::UnaryContext* context) override;

            virtual void enterAssignment(TorqueParser::AssignmentContext* context) override;
            virtual void exitAssignment(TorqueParser::AssignmentContext* context) override;

            virtual void enterBitwise(TorqueParser::BitwiseContext* context) override;
            virtual void exitBitwise(TorqueParser::BitwiseContext* context) override;

            virtual void enterProgram(TorqueParser::ProgramContext* context) override;
            virtual void exitProgram(TorqueParser::ProgramContext* context) override;

            virtual void enterStatement(TorqueParser::StatementContext* context) override;
            virtual void exitStatement(TorqueParser::StatementContext* context) override;

            virtual void enterActionstatement(TorqueParser::ActionstatementContext* context) override;
            virtual void exitActionstatement(TorqueParser::ActionstatementContext* context) override;

            virtual void enterWhilecontrol(TorqueParser::WhilecontrolContext* context) override;
            virtual void exitWhilecontrol(TorqueParser::WhilecontrolContext* context) override;

            virtual void enterControlexpression(TorqueParser::ControlexpressionContext* context) override;
            virtual void exitControlexpression(TorqueParser::ControlexpressionContext* context) override;

            virtual void enterTernary(TorqueParser::TernaryContext* context) override;
            virtual void exitTernary(TorqueParser::TernaryContext* context) override;

            virtual void enterForcontrol(TorqueParser::ForcontrolContext* context) override;
            virtual void exitForcontrol(TorqueParser::ForcontrolContext* context) override;

            virtual void enterSubreference(TorqueParser::SubreferenceContext* context) override;
            virtual void exitSubreference(TorqueParser::SubreferenceContext* context) override;

            virtual void enterIfcontrol(TorqueParser::IfcontrolContext* context) override;
            virtual void exitIfcontrol(TorqueParser::IfcontrolContext* context) override;

            virtual void enterReturncontrol(TorqueParser::ReturncontrolContext* context) override;
            virtual void exitReturncontrol(TorqueParser::ReturncontrolContext* context) override;

            virtual void enterEquality(TorqueParser::EqualityContext* context) override;
            virtual void exitEquality(TorqueParser::EqualityContext* context) override;

        private:

            void pushInstructionFrame();
            void popInstructionFrame();
            std::vector<std::shared_ptr<Instruction>>& getCurrentInstructionFrame();

            //! Codeblock we are currently generating. This is only used as temporary storage space as the tree is running.
            CodeBlock* mCurrentCodeBlock;

            std::vector<std::vector<std::shared_ptr<Instruction>>> mInstructionStack;
    };
}
