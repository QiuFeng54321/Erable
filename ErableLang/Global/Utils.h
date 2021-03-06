#include <utility>

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Utils.h
 * Author: Qiufeng54321
 *
 * Created on 2019年4月18日, 下午7:47
 */
#pragma once
#ifndef UTILS_H
#define UTILS_H

//#pragma comment("UTIL_START")
#include <vector>
#include <string>
#include <ostream>
#include <sstream>
#include "Exceptions.hpp"

namespace Erable::Utils {
    template<typename T>

    std::ostream &operator<<(std::ostream &os, const std::vector<T> &obj) {
        os << "[";
        for (int i = 0; i < obj.size(); ++i) {
            os << (int) obj[i];
            if (i < obj.size() - 1)os << ",";
        }
        os << "]";
        return os;
    }

    /*                  *\
     *                  *|
     *                  *|
     *       Enum       *|
     *                  *|
     *                  *|
     *                  *|
     \*                 */
    template<class ValueType>
    struct EnumElement {
        std::string name;
        ValueType value;
    public:

        EnumElement(std::string name, ValueType value) :
                name(std::move(name)), value(value) {
        }

    };

    template<class ValueType>
    class Enum {
    public:
        std::vector<EnumElement<ValueType>> elements;

        Enum<ValueType>();

        inline void addEnum(std::string name, ValueType value) {
            auto ele = EnumElement<ValueType>(name, value);
            this->addEnum(name, ele);
        };

        inline void addEnum(const std::string &name, EnumElement<ValueType> value) {
            this->elements.push_back(value);
        };

        inline void removeEnum(const std::string &name) {
            int index = 0;
            for (EnumElement<ValueType> element : this->elements) {
                if (element.name == name) {
                    break;
                }
                ++index;
            }
            this->removeEnum(index);
        };

        inline void removeEnum(int index) {
            this->elements.erase(index);
        };

        inline EnumElement<ValueType> find(std::string name) {
            for (EnumElement<ValueType> element : this->elements) {
                if (element.name == name) {
                    return element;
                }
            }
            Exceptions::ValidateException("No element found: '" + name + "'").throwException();
        };

        inline int findIndex(std::string name) {
            int ind = 0;
            for (EnumElement<ValueType> element : this->elements) {
                if (element.name == name) {
                    return ind;
                }
                ++ind;
            }
            return -1;
        };

        inline EnumElement<ValueType> find(int index) {
            return this->elements[index];
        };
    };

    template<class ValueType>
    Enum<ValueType>::Enum() = default;

    /*                  *\
     *                  *|
     *                  *|
     *     BitUtils     *|
     *  Implementation  *|
     *     of Java      *|
     *                  *|
     *                  *|
     *                  *|
     \*                 */
    class BitUtils_t {
    public:
        template<typename R>
        inline R getLE(std::vector<char> b, int off, int size) {
            R r = 0;
            int bit = 0;
            //std::cout<<"Doing BitUtils::get: " << b <<std::endl;
            for (int i = size - 1; i > -1; --i, bit += 8) {
                int bitr = (int) b[i];
                //std::cout<<"BitR: " <<bitr << ", Offset: " << (off + i) <<std::endl;
                if (i != 0)bitr &= 0xFF;
                //std::cout<<"BitR bitand 0xFF: "<<bitr<<std::endl;
                r += (bitr << bit);
                //std::cout<<"Shift: "<<bit<<" to " << r<< " with " << bitr << std::endl;
            }
            return r;
        }

        template<typename R>
        inline R getBE(std::vector<char> b, int off, int size) {
            R r = 0;
            int bit = 0;
            //std::cout<<"Doing BitUtils::get: " << b <<std::endl;
            for (int i = 0; i < size; ++i, bit += 8) {
                int bitr = (int) b[i];
                //std::cout<<"BitR: " <<bitr << ", Offset: " << (off + i) <<std::endl;
                if (i != 0)bitr &= 0xFF;
                //std::cout<<"BitR bitand 0xFF: "<<bitr<<std::endl;
                r += (bitr << bit);
                //std::cout<<"Shift: "<<bit<<" to " << r<< " with " << bitr << std::endl;
            }
            return r;
        }

        inline bool getBoolean(std::vector<char> b, int off) {
            return b[off] != 0;
        }

        inline char getChar(std::vector<char> b, int off) {
//                return (char) ((b[off + 1] & 0xFF) +
//                        (b[off] << 8));
            return getLE<char>(b, off, 2);
        }

        inline short getShort(std::vector<char> b, int off) {
//                return (short) ((b[off + 1] & 0xFF) +
//                        (b[off] << 8));
            return getLE<short>(b, off, 2);
        }

        inline int getInt(std::vector<char> b, int off) {
//                return ((b[off + 3] & 0xFF)) +
//                        ((b[off + 2] & 0xFF) << 8) +
//                        ((b[off + 1] & 0xFF) << 16) +
//                        ((b[off ]) << 24);
            return getLE<int>(b, off, 4);
        }

        inline long getLong(std::vector<char> b, int off) {
//                return ((b[off + 7] & 0xFFL)) +
//                        ((b[off + 6] & 0xFFL) << 8) +
//                        ((b[off + 5] & 0xFFL) << 16) +
//                        ((b[off + 4] & 0xFFL) << 24) +
//                        ((b[off + 3] & 0xFFL) << 32) +
//                        ((b[off + 2] & 0xFFL) << 40) +
//                        ((b[off + 1] & 0xFFL) << 48) +
//                        (((long) b[off]) << 56);
            return getLE<long>(b, off, 8);
        }

        inline float getFloat(std::vector<char> b, int off) {
            return (float) getBE<long>(b, off, 8);
        }

        inline double getDouble(std::vector<char> b, int off) {
            return (double) (getBE<long>(b, off, 8));
        }


    };

    inline BitUtils_t BitUtils;

    /*                  *\
     *                  *|
     *                  *|
     *    ArrayUtils    *|
     *                  *|
     *                  *|
     *                  *|
     \*                 */
    class ArrayUtils {
    public:

        template<typename ori, typename type>
        inline static std::vector<type> transformType(std::vector<ori> t) {
            std::vector<type> res;
            for (ori ele : t) {
                res.push_back((type) ele);
            }
            return res;
        }

        template<typename type>
        inline static std::string toString(std::vector<type> t) {
            std::stringstream ss;
            int i = 0;
            if (not t.empty()) {
                for (type ty : t) {
                    if (i > 0)
                        ss << ",";
                    if (typeid(ty) == typeid(char) or typeid(ty) == typeid(unsigned char)) {
                        ss << (int) ty;
                    } else {
                        ss << ty;
                    }
                    ++i;
                }
            }
            return ss.str();
        }

        inline static std::vector<std::string> split(const std::string &s, const std::string &c) {
            std::string::size_type pos1, pos2;
            std::vector<std::string> v;
            pos2 = s.find(c);
            pos1 = 0;
            while (std::string::npos != pos2) {
                v.push_back(s.substr(pos1, pos2 - pos1));

                pos1 = pos2 + c.size();
                pos2 = s.find(c, pos1);
            }
            if (pos1 != s.length())
                v.push_back(s.substr(pos1));
            return v;
        }

        template<typename T>
        inline static int indexOf(std::vector<T> vector, T element) {
            int ind = 0;
            for (auto &ele : vector) {
                if (element == ele) return ind;
                ind++;
            }
            return -1;
        }
    };


    class StringUtils {
    public:
        inline static bool startsWith(std::string str, std::string start) {
            return str.find(start) == 0;
        }

        inline static bool endsWith(std::string str, std::string end) {
            return str.rfind(end) == str.length() - end.length();
        }
    };

}

//#pragma comment("UTIL_END")

#endif /* UTILS_H */

