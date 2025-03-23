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

        void get_full_time() const {
            cout << "Time: " << 
                setfill('0') << setw(2) << hour << "h:" << 
                setfill('0') << setw(2) << mins << "m:" << 
                setfill('0') << setw(2) << segs << "s " <<
                suffix_to_string(suffix) << endl;
        }

        void get_full_24() const {
            cout << "Time: " << 
                setfill('0') << setw(2) << hour + 12*suffix << "h:" << 
                setfill('0') << setw(2) << mins << "m:" << 
                setfill('0') << setw(2) << segs << "s " << endl;
        }

        int check_time() const {
            if (hour<0 || hour>11) throw invalid_argument("Mal la hora.");
            if (mins<0 || mins>59) throw invalid_argument("Mal los minutos.");
            if (segs<0 || segs>59) throw invalid_argument("Mal los segundos.");
            if (suffix!=AM && suffix!=PM) throw invalid_argument("Mal el meridiano.");
            return 0;
        }

        void set_hour(int h){
            Timer(h).check_time();
            hour=h;
        }

        void set_mins(int m){
            Timer(0, m).check_time();
            mins=m;
        }

        void set_segs(int s){
            Timer(0, 0, s).check_time();
            segs=s;
        }

        void set_suffix(suffix_t sf){
            Timer(0, 0, 0, sf).check_time();
            suffix=sf;
        }

        void get_hour() const {
            cout << "Hour: " << setfill('0') << setw(2) << hour << "h" << endl;
        }

        void get_mins() const {
            cout << "Mins: " << setfill('0') << setw(2) << mins << "m" << endl;
        }

        void get_segs() const {
            cout << "Segs: " << setfill('0') << setw(2) << segs << "s" << endl;            
        }

        void get_suffix() const {
            cout << "Suffix: " << suffix_to_string(suffix);
        }

        string suffix_to_string(suffix_t sf) const {
            switch (sf){
                case AM: return "a.m."; break;
                case PM: return "p.m."; break;
                default: return ""; break;
            }
        }

        void reset(){
            hour=0; mins=0; segs=0; suffix=AM;
        }
};

bool str_comps(const string str1, const string str2);

void timer_console();

#endif //TIMER_H