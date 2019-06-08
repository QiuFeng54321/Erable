//
// Created by Qiufeng54321 on 2019-06-06.
// Copyright (c) Qiufeng54321 All rights reserved.
//

#ifndef ERABLECOMPILER_SYMBOLS_HPP
#define ERABLECOMPILER_SYMBOLS_HPP

#include <string>
#include <vector>


namespace Erable::Compiler::Symbols {
    //Symbol: the base class for other symbol types
    class Symbol {
    public:
        virtual std::string getType() = 0;
    };

    typedef std::unique_ptr<Symbol> SymbolPtr;

    //TokenSymbol stores a token name
    class TokenSymbol : public Symbol {
    public:
        std::string ruleName;

        explicit TokenSymbol(std::string ruleName);

        std::string getType() override;
    };

    typedef std::unique_ptr<TokenSymbol> TokenSymbolPtr;

    //RuleSymbol stores a rule name
    class RuleSymbol : public Symbol {
    public:
        std::string ruleName;

        explicit RuleSymbol(std::string ruleName);

        std::string getType() override;
    };

    typedef std::unique_ptr<RuleSymbol> RuleSymbolPtr;

    //HandlerSymbol stores branches of tokens to be processed.
    class HandlerSymbol : public Symbol {
    public:
        SymbolPtr firstSymbol, secondSymbol;

        HandlerSymbol(SymbolPtr &&firstSymbol, SymbolPtr &&secondSymbol);

        std::string getType() override;
    };

    typedef std::unique_ptr<HandlerSymbol> HandlerSymbolPtr;

    //ComplexSymbol stores list of symbols
    class ComplexSymbol : public Symbol {
    public:
        SymbolPtr firstSymbol, secondSymbol;

        ComplexSymbol(SymbolPtr &&firstSymbol, SymbolPtr &&secondSymbol);

        std::string getType() override;
    };

    typedef std::unique_ptr<ComplexSymbol> ComplexSymbolPtr;

    //A Rule defines a grammar
    class Rule : public Symbol {
    public:
        SymbolPtr rule;
        std::string ruleName;

        explicit Rule(std::string ruleName);

        std::string getType() override;
    };

    typedef std::unique_ptr<Rule> RulePtr;
}

Erable::Compiler::Symbols::SymbolPtr operator "" _RuleSymbol(const char *, std::size_t);

Erable::Compiler::Symbols::SymbolPtr operator "" _TokenSymbol(const char *, std::size_t);

Erable::Compiler::Symbols::RulePtr operator "" _Rule(const char *, std::size_t);

Erable::Compiler::Symbols::SymbolPtr
operator|(Erable::Compiler::Symbols::SymbolPtr &&, Erable::Compiler::Symbols::SymbolPtr &&);

Erable::Compiler::Symbols::SymbolPtr
operator+(Erable::Compiler::Symbols::SymbolPtr &&, Erable::Compiler::Symbols::SymbolPtr &&);

Erable::Compiler::Symbols::SymbolPtr
operator-(Erable::Compiler::Symbols::RulePtr &&, Erable::Compiler::Symbols::SymbolPtr &&);

#endif //ERABLECOMPILER_SYMBOLS_HPP
