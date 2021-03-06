//
// Created by Qiufeng54321 on 2019-07-01.
// Copyright (c) Qiufeng54321 All rights reserved.
//

#ifndef ERABLELANG_SYMBOLS_HPP
#define ERABLELANG_SYMBOLS_HPP

#include "Headers.hpp"

namespace Erable::Compiler::Symbols {
	enum class SymbolType {
		TOKEN,
		COMBINATION,
		RULE
	};

	struct Symbol {
	public:
		static int currentUid;
		int uid = currentUid++;
		int ruleId;
		std::string tag;
		Parser::IterationNode *connectedTo = nullptr;
		SymbolPtr connectedToSymbol = nullptr;
		int dotPosition = 0;
		///It doesn't show the list of lookaheads, but shows all  possible lookaheads that will call reduce.
		LookaheadSet lookahead;
		SymbolType type = SymbolType::TOKEN;

		explicit Symbol(std::string tag);

		/**
		 * @return the tag the current symbol has
		 */
		virtual std::string getTag();

		/**
		 * @return the type of the symbol.
		 */

		virtual SymbolType getType();

		/**
		 * Full clones the whole symbol but without cloning dotPosition, connectedTo, connectedToSymbol, and lookAhead.
		 * @return the cloned Symbol Pointer
		 */
		virtual SymbolPtr fullClone();

		/**
		 * Full clones the whole symbol and set the dotPosition to UNKNOWN(-1)
		 * @return the cloned Symbol Pointer
		 */
		SymbolPtr fullCloneWithNeg1Dot();

		/**
		 * increase the dotPosition by 1.
		 */
		virtual void shiftDot();

		/**
		 * A wrapper for getting the very front token of the current symbol. (Wraps TokenSymbolList getFront(SymbolList &)
		 * @return tokens that may be at the very front
		 */
		virtual LookaheadSet getFront();

		/**
		 * Gets the very front token of the current symbol.
		 * @param symbolList records already-checked symbols in case for two rules that references each other at start.
		 * @return tokens that may be at the very front
		 */
		virtual LookaheadSet getFirst(SymbolList &symbolList);

		/**
		 * Makes a string containing some infos about the symbol.
		 * @return string made
		 */
		virtual std::string toString();

		/**
		 * Compares this and that and see if they are the same beside connectedTo, connectedToSymbol, and dotPosition.
		 * @param that another Symbol which takes part in the comparison
		 * @return the result comparing
		 */
		virtual bool is(SymbolPtr that);

		/**
		 * "Kernel" which gets the very front token of the current symbol.
		 * @param exp a single symbol
		 * @return tokens that is at the very front
		 */
		static LookaheadSet getFront(SymbolList &, SymbolPtr exp);

		static LookaheadSet getLookahead(SymbolPtr exp, SymbolList symbolList, int startOffset);

		/**
		 * returns the 'lookahead' of a symbol.
		 * Internally, it first checks if exp is a combination(production).
		 * If it is, returns _getLookahead(the next symbol of the symbol followed by the dot in exp)
		 * else, returns _getLookahead(exp).
		 * @param duplicateSymbol to avoid duplicate symbols caused by recursive referencing, etc.
		 * @param exp the symbol to find lookahead for
		 * @return exp's lookahead set
		 */
		static LookaheadSet
		getLookahead(SymbolList &duplicateSymbol, SymbolPtr exp, SymbolList symbolList, int startOffset);

	};

	struct CombineSymbol : public Symbol {
		SymbolList list;

		CombineSymbol(std::string tag, SymbolList list);

		CombineSymbol(SymbolList list);

		SymbolType getType() override;

		SymbolPtr fullClone() override;

//		LookaheadSet getFront() override;

		LookaheadSet getFirst(SymbolList &list) override;

		std::string toString() override;

		bool is(SymbolPtr that) override;
	};

	///End Of Token
	inline auto EOT = "$"_token;
	inline auto EPSILON = "ε"_token;
	inline Token EOT_TOKEN = {"$"};
	inline auto EMPTY_PLACEHOLDER = "__null"_rule;
	inline std::string ANONYMOUS = "_anonymous";
}


#endif //ERABLELANG_SYMBOLS_HPP
