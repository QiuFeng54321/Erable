//
// Created by Qiufeng54321 on 2019-06-13.
// Copyright (c) Qiufeng54321 All rights reserved.
//
#pragma once
#ifndef ERABLECOMPILER_PROCESSEDDATA_HPP
#define ERABLECOMPILER_PROCESSEDDATA_HPP


#include "Headers.hpp"

namespace Erable::Compiler::Data {


    struct ProcessedData {
        Symbols::SymbolPtr type;
        DataList dataList;
        Token token;
        bool isNull = false;

        explicit ProcessedData(Token token);

        ProcessedData(Symbols::SymbolPtr type, DataList dataList);

        ProcessedData();

        bool isRule();

		bool isExactly(const std::string &);

        const Symbols::SymbolPtr &getType() const;

        void setType(const Symbols::SymbolPtr &type);

        const DataList &getDataList() const;

        void setDataList(const DataList &dataList);

        const Token &getToken() const;

        void setToken(const Token &token);

        std::string getTag();
    };

}

#endif //ERABLECOMPILER_PROCESSEDDATA_HPP
