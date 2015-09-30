#pragma once
#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

namespace logger {
    extern std::ofstream code;
    extern std::ofstream log;
    void init(std::string fname);
    void close();
    extern std::string code_pre;
    extern std::string log_pre;
    extern uint32 line;
}

#define LOG(ans) if (!logger::log.is_open() ) { logger::init("default"); }                                              \
    try {                                                                                                               \
        std::cout << "(" << logger::line << ")" << logger::log_pre << "LOG:" << ans << std::endl;                       \
        logger::log << "(" << logger::line << ")" << logger::log_pre << ans << std::endl;                               \
    } catch(std::exception e)   {                                                                                       \
        std::cout << std::endl << "An error occurred: " << e.what() << std::endl;                                       \
        std::cout << "Attempted log: " << #ans << std::endl;                                                            \
        exit(-1); }

#define CODE(ans) if (!logger::code.is_open() ) { logger::init("default"); }                                            \
    try {                                                                                                               \
        std::cout << "    #" << logger::code_pre << ans << std::endl;                                                   \
        logger::code << logger::code_pre << ans << std::endl;                                                           \
        logger::line++;                                                                                                 \
    } catch(std::exception e)   {                                                                                       \
        std::cout << std::endl << "An error occurred: " << e.what() << std::endl;                                       \
        std::cout << "Attempted code: " << #ans << std::endl;                                                           \
        exit(-1); }

#define ENTER_FUNC(name) LOG("Entering function " << name)                                                              \
    logger::log_pre += "  ";

#define LEAVE_FUNC(name, ret) logger::log_pre.pop_back(); logger::log_pre.pop_back();                                   \
    LOG("Leaving function " << name)                                                                                    \
    return ret;

#define LEAVE_FUNC_VOID(name) logger::log_pre.pop_back(); logger::log_pre.pop_back();                                   \
    LOG("Leaving function " << name << ", returning void.")                                                             \
    return;