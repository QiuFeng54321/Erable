//
// Created by Qiufeng54321 on 2019-05-23.
//

#include "IOS.hpp"

namespace Erable::Native::BuiltIn {

    DEFINE_NATIVE_FUNCTION(print) {
        auto *toP = argv->getAValue<Types::Array::arrtype>().at(0);
        std::cout << toP;
        return nullptr;
    }

    DEFINE_NATIVE_FUNCTION(scan) {
        std::string get;
        std::cin >> get;
        Types::Instance *ret = new Types::String(get, self->getRetId(), desc);
        return ret;
    }
	
	DEFINE_NATIVE_FUNCTION(println) {
		auto *toP = argv->getAValue<Types::Array::arrtype>().at(0);
        std::cout << toP << std::endl;
		return nullptr;
	}
}