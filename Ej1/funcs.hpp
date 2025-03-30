#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

#include "timer.hpp"

bool str_comps(const string str1, const string str2);

suffix_t string_to_suffix(string sf);

void handle_setting(setting set, Timer& timer, string command);

void help();

void timer_console();

#endif //FUNCS_H