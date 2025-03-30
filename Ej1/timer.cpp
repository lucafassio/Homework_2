#include "timer.hpp"
#include "funcs.hpp"

Timer::Timer():
    hour(0), mins(0), segs(0), suffix(AM)
{check_time();}

Timer::Timer(int h):
    hour(h), mins(0), segs(0), suffix(AM)
{check_time();}

Timer::Timer(int h, int m):
    hour(h), mins(m), segs(0), suffix(AM)
{check_time();}

Timer::Timer(int h, int m, int s):
    hour(h), mins(m), segs(s), suffix(AM)
{check_time();}

Timer::Timer(int h, int m, int s, suffix_t sf):
    hour(h), mins(m), segs(s), suffix(sf)
{check_time();}

void Timer::get_full_time() const {
    cout << 
        setfill('0') << setw(2) << this->hour << "h:" << 
        setfill('0') << setw(2) << this->mins << "m:" << 
        setfill('0') << setw(2) << this->segs << "s " <<
        suffix_to_string(this->suffix) << endl;
}

void Timer::get_full_24() const {
    cout <<
        setfill('0') << setw(2) << this->hour + 12*this->suffix << "h:" << 
        setfill('0') << setw(2) << this->mins << "m:" << 
        setfill('0') << setw(2) << this->segs << "s " << endl;
}

int Timer::check_time() const {
    if (this->hour<0 || this->hour>11) throw invalid_argument("Invalid hour.");
    if (this->mins<0 || this->mins>59) throw invalid_argument("Invalid mins.");
    if (this->segs<0 || this->segs>59) throw invalid_argument("Invalid segs.");
    if (suffix!=AM && suffix!=PM) throw invalid_argument("Invalid suffix.");
    return 0;
}

void Timer::set_hour(int h){
    Timer t(h);
    this->hour=h;
}

void Timer::set_mins(int m){
    Timer(0, m);
    this->mins=m;
}

void Timer::set_segs(int s){
    Timer(0, 0, s);
    this->segs=s;
}

void Timer::set_suffix(suffix_t sf){
    Timer(0, 0, 0, sf);
    this->suffix=sf;
}

int Timer::get_hour() const {
    return this->hour;
}

int Timer::get_mins() const {
    return this->mins;
}

int Timer::get_segs() const {
    return this->segs;
}

string Timer::get_suffix() const {
    return suffix_to_string(this->suffix);
}

string Timer::suffix_to_string(suffix_t sf) const {
    switch (sf){
        case AM: return "a.m."; break;
        case PM: return "p.m."; break;
        default: return ""; break;
    }
}