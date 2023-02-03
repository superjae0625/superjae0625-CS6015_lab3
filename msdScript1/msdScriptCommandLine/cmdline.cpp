#include "cmdline.hpp"

void use_arguments(int argc, const char * argv[]){
    

    for(int i = 1; i < argc; i++){
        string argument = argv[i];
        string help = "--help";
        string test = "--test";
        string empty = "a";
        
        if(argument.compare(help)==0){
            cout << "This is the help text."<< endl;
            exit(0);
        } else if (argv[1] == test) {
            if (Catch::Session().run() != 0) {
                exit(1);
            }
        }else{
            cerr << "Invalid text"<< endl;
            exit(1);
        }
    }
}
