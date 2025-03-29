#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

enum suffix_t{
    AM, PM
};

enum setting{
    HOUR,
    MINS,
    SEGS,
    SUFFIX,
    DEFAULT
};

class Timer{
    private:
        int hour;
        int mins;
        int segs;
        suffix_t suffix;
    
    public:
        Timer();
        Timer(int h);
        Timer(int h, int m);
        Timer(int h, int m, int s);
        Timer(int h, int m, int s, suffix_t sf);
        
        void set_hour(int h);
        void set_mins(int m);
        void set_segs(int s);
        void set_suffix(suffix_t sf);
        
        int get_hour() const;
        int get_mins() const;
        int get_segs() const;
        string get_suffix() const;
        void get_full_time() const;
        void get_full_24() const;

        int check_time() const;
        string suffix_to_string(suffix_t sf) const;
};

bool str_comps(const string str1, const string str2);

suffix_t string_to_suffix(string sf);

void handle_setting(setting set, Timer& timer, string command);

void help();

void timer_console();

#endif //TIMER_H