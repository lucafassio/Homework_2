#include "funcs.hpp"
#include "timer.hpp"

//misma funcion que el homework1.
bool str_comps(const string str1, const string str2){
    if (str1[0]=='\0' && str2[0]=='\0') return true;
    if (str1[0]==str2[0]) return str_comps(str1.substr(1), str2.substr(1));
    return false;
}

suffix_t string_to_suffix(string sf){
    if (str_comps(sf, "am")) return AM;
    if (str_comps(sf, "pm")) return PM; 
    throw invalid_argument("Invalid suffix.");
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
        case HOUR: timer.set_hour(stoi(command)); cout << "Hour set to: " << setfill('0') << setw(2) << timer.get_hour() << "h" << endl; break;
        case MINS: timer.set_mins(stoi(command)); cout << "Mins set to: " << setfill('0') << setw(2) << timer.get_hour() << "m" << endl; break;
        case SEGS: timer.set_segs(stoi(command)); cout << "Segs set to: " << setfill('0') << setw(2) << timer.get_hour() << "s" << endl; break;
        case SUFFIX: timer.set_suffix(string_to_suffix(command)); cout << "Suffix set to: " << setfill('0') << setw(2) << timer.get_suffix() << endl; break;
        default:
            /*
             * Linea a linea de lo que hace este bloque:
             * - si se ingresa un numero de 3 digitos o mas, tiro error.
             * - paso a int (si es de un solo digito, stoi ignora el espacio).
             * - descarto el numero (no va a ser mayor de dos digitos).
             * - si quedo algun espacio lo descarto tambien.
             */
            if (isdigit(command[1]) && isdigit(command[2])) throw invalid_argument("Invalid hour.");         
            h=stoi(command.substr(0, 2));
            command=command.substr(2);
            while (isspace(command[0])) command=command.substr(1);

            //si es el final del comando fuerzo una exception para ingresar los datos.
            forced=command.substr(1);

            //los proximos dos bloques hacen lo mismo para mins y segs.
            if (isdigit(command[1]) && isdigit(command[2])) throw invalid_argument("Invalid mins.");
            m=stoi(command.substr(0, 2));
            command=command.substr(2);
            while (isspace(command[0])) command=command.substr(1);

            forced=command.substr(1);

            if (isdigit(command[1]) && isdigit(command[2])) throw invalid_argument("Invalid segs.");
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
            throw invalid_argument("to much arguments.");
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
        cout << "Timer set to: ";
        timer.get_full_time();
    }
}

void help(){
    cout << "Command guide:" << endl;
    cout << "/time get -> shows the timer in 12hs format." << endl;
    cout << "/time get <24> -> shows the timer in 24hs format." << endl;
    cout << "/time get <hour/mins/segs/suffix> -> shows an especific part of the timer." << endl;
    cout << "/time set <hour/mins/segs/suffix> -> sets an especific part of the timer." << endl;
    cout << "/time set <hour> <OPTIONAL:mins> <OPTIONAL:segs> <OPTIONAL:am/pm> -> sets the entire timer." << endl;
    cout << "/help -> command guide." << endl;
    cout << "/exit -> ends the program." << endl;
}

void timer_console(){
    cout << "========== Ej 1: Timer ==========" << endl;
    cout << "Enter '/help' for command guide." << endl;
    string command, forced;
    Timer timer;
    while (true){
        cout << endl << "> ";
        getline(cin, command);

        //ignoro espacios y tabs iniciales.
        while (isspace(command[0])) command=command.substr(1);

        if (str_comps(command.substr(0, 5), "/help")) {help(); continue;}
        if (str_comps(command.substr(0, 5), "/exit")) return;
        if (str_comps(command.substr(0, 11), "/time reset")) {timer=Timer(0, 0, 0, AM); continue;}
        if (!str_comps(command.substr(0, 5), "/time")) {cout << "Command '" << command << "' not found." << endl; continue;}

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
                throw invalid_argument("Wrong input.");
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
            catch(exception &e){
                cout << e.what() << endl;
            }
        }
        else{
            cout << "Command '" << command << "' not found." << endl;
        }
    }
}