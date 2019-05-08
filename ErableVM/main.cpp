/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Descriptor.hpp"
#include "Program.hpp"

/*
 * File:   main.cpp
 * Author: Qiufeng54321
 *
 * Created on 2019年4月18日, 上午11:22
 */



#include <cstdlib>
#include <iostream>
#include "Program.hpp"
#include "Descriptor.hpp"
#include "Metadata.hpp"

/*
 *
 */
int main(int argc, char** argv) {
    Erable::Descriptor desc;
    std::cout << "INITIALISED" << std::endl;
    desc.setInput(new Erable::Program::ProgramInputStream("../test/test.ec"));
    std::cout << "EXECUTE..." << std::endl;
    desc.doAll();
    std::cout << "TERMINATED..." << std::endl;
    return 0;
}
