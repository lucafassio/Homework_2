#include "timer.hpp"

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
    cout << "Time: " << 
        setfill('0') << setw(2) << this->hour << "h:" << 
        setfill('0') << setw(2) << this->mins << "m:" << 
        setfill('0') << setw(2) << this->segs << "s " <<
        suffix_to_string(this->suffix) << endl;
}

void Timer::get_full_24() const {
    cout << "Time: " << 
        setfill('0') << setw(2) << this->hour + 12*this->suffix << "h:" << 
        setfill('0') << setw(2) << this->mins << "m:" << 
        setfill('0') << setw(2) << this->segs << "s " << endl;
}

int Timer::check_time() const {
    if (this->hour<0 || this->hour>11) throw invalid_argument("Mal la hora.");
    if (this->mins<0 || this->mins>59) throw invalid_argument("Mal los minutos.");
    if (this->segs<0 || this->segs>59) throw invalid_argument("Mal los segundos.");
    if (suffix!=AM && suffix!=PM) throw invalid_argument("Mal el meridiano.");
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

void Timer::get_hour() const {
    cout << "Hour: " << setfill('0') << setw(2) << this->hour << "h" << endl;
}

void Timer::get_mins() const {
    cout << "Mins: " << setfill('0') << setw(2) << this->mins << "m" << endl;
}

void Timer::get_segs() const {
    cout << "Segs: " << setfill('0') << setw(2) << this->segs << "s" << endl;            
}

void Timer::get_suffix() const {
    cout << "Suffix: " << suffix_to_string(this->suffix);
}

string Timer::suffix_to_string(suffix_t sf) const {
    switch (sf){
        case AM: return "a.m."; break;
        case PM: return "p.m."; break;
        default: return ""; break;
    }
}

//misma funcion que el homework1.
bool str_comps(const string str1, const string str2){
    if (str1[0]=='\0' && str2[0]=='\0') return true;
    if (str1[0]==str2[0]) return str_comps(str1.substr(1), str2.substr(1));
    return false;
}

suffix_t string_to_suffix(string sf){
    if (str_comps(sf, "am")) return AM;
    if (str_comps(sf, "pm")) return PM; 
    throw invalid_argument("Mal el suffix.");
};

void handle_setting(setting set, Timer& timer, string command){
    int h=0, m=0, s=0;
    suffix_t sf=AM;
    string forced;
    try{
        //ignoro si hay espacios de mas y dejo el comando solo con lops numeros
        while (isspace(command[0])) command=command.substr(1);

        //si el usuario especifica cual cambiar, solo modifico ese
        switch (set){
        case HOUR: timer.set_hour(stoi(command)); break;
        case MINS: timer.set_mins(stoi(command)); break;
        case SEGS: timer.set_segs(stoi(command)); break;
        case SUFFIX: timer.set_suffix(string_to_suffix(command)); break;
        default:
            /*
             * Linea a linea de lo que hace este bloque:
             * - si se ingresa un numero de 3 digitos o mas, tiro error.
             * - paso a int (si es de un solo digito, stoi ignora el espacio).
             * - descarto el numero (no va a ser mayor de dos digitos).
             * - si quedo algun espacio lo descarto tambien.
             */
            if (isdigit(command[1]) && isdigit(command[2])) throw invalid_argument("Mal la hora.");         
            h=stoi(command.substr(0, 2));
            command=command.substr(2);
            while (isspace(command[0])) command=command.substr(1);

            //si es el final del comando fuerzo una exception para ingresar los datos.
            forced=command.substr(1);

            cout << command << endl;

            //los proximos dos bloques hacen lo mismo para mins y segs.
            if (isdigit(command[1]) && isdigit(command[2])) throw invalid_argument("Mal los mins.");
            m=stoi(command.substr(0, 2));
            command=command.substr(2);
            while (isspace(command[0])) command=command.substr(1);

            cout << command << endl;

            forced=command.substr(1);

            if (isdigit(command[1]) && isdigit(command[2])) throw invalid_argument("Mal los segs.");
            s=stoi(command.substr(0, 2));
            command=command.substr(2);
            while (isspace(command[0])) command=command.substr(1);
            
            forced=command.substr(1);

            //para el sufijo saco dos caracteres (otra opcion seria invalida).
            sf=string_to_suffix(command.substr(0, 2));
            command=command.substr(2);
            while (isspace(command[0])) command=command.substr(1);

            //si despues de descartar los espacios extra queda alguna letra, tiro un error de que agrego un argumento de mas.
            //si se termino la linea del comando, fuerzo la misma exception e ingreso los datos.
            forced=command.substr(1);
            throw invalid_argument("te pasaste de mambo.");
        }
    }
    catch(invalid_argument &e){
        cout << e.what() <<endl;
    }
    catch(exception &e){
        Timer(h, m, s, sf);
        timer.set_hour(h);
        timer.set_mins(m);
        timer.set_segs(s);
        timer.set_suffix(sf);
    }
}

void timer_console(){
    int hour, mins, segs;
    string suffix, command, forced;
    Timer timer(2, 30, 0, AM);
    while (true){
        getline(cin, command);

        //ignoro espacios y tabs iniciales.
        while (isspace(command[0])) command=command.substr(1);

        if (str_comps(command.substr(0, 5), "/help")) cout << "Help!!" << endl;
        if (str_comps(command.substr(0, 5), "/exit")) return;
        if (!str_comps(command.substr(0, 5), "/time")) cout << "Mal comando." << endl;

        //la primera parte del comando esta bien, la descarto.
        command=command.substr(6);
        while (isspace(command[0])) command=command.substr(1);

        if (str_comps(command.substr(0, 3), "get")){
            try {
                //descarto "get".
                command=command.substr(4);

                //ignoro espacios y tabs.
                while (isspace(command[0])) command=command.substr(1);

                //chequeo si se quiere algo en especifico.
                if (str_comps(command.substr(0, 4), "hour")) {timer.get_hour(); continue;}
                if (str_comps(command.substr(0, 4), "mins")) {timer.get_mins(); continue;}
                if (str_comps(command.substr(0, 4), "segs")) {timer.get_segs(); continue;}
                if (str_comps(command.substr(0, 6), "suffix")) {timer.get_suffix(); continue;}
                if (str_comps(command.substr(0, 4), "24")) {timer.get_full_24(); continue;}

                //fuerzo throw exception si sobran espacios o tabs.
                forced=command.substr(1);

                //cualquier especificacion erronea.
                throw invalid_argument("Comando mal ingresado.");
            }
            catch(invalid_argument &e){
                cout << e.what() << endl;
            }
            //aprovecho que cuando string trata de conseguir un substring en una posicion mas alla del final lanza un exception
            //por si no se ingresa nada ("/time get" muestra la hora completa de 12hs).
            catch(exception &e){
                timer.get_full_time();
            }
            
        } 
        else if (str_comps(command.substr(0, 3), "set")){
            int h=0, m=0, s=0;
            suffix_t sf=AM;
            try {
                //descarto "set".
                command=command.substr(4);

                //ignoro espacios y tabs.
                while (isspace(command[0])) command=command.substr(1);

                //chequeo que se quiere settear.
                if (str_comps(command.substr(0, 4), "hour")) {handle_setting(HOUR, timer, command.substr(5)); continue;}
                if (str_comps(command.substr(0, 4), "mins")) {handle_setting(MINS, timer, command.substr(5)); continue;}
                if (str_comps(command.substr(0, 4), "segs")) {handle_setting(SEGS, timer, command.substr(5)); continue;}
                if (str_comps(command.substr(0, 6), "suffix")) {handle_setting(SUFFIX, timer, command.substr(7)); continue;}
                if (isdigit(command[0])) {handle_setting(DEFAULT, timer, command); continue;}
            }
            catch(...){
                cout << "error?" << endl;
            }
        }
        else{
            cout << "Command '" << command << "' not found." << endl;
        }
    }
}