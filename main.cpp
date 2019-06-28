#include "asciifile.h"
#include <fstream>

using namespace std;
int main( int argc, char** argv ){
    if( argc != 2 ){
        cout << "usage:\n"
             << "asciifile inputfile.tvg"
             << endl;
        return 0;
    }
    try {
        ifstream in;
        asciifile image;
        string infile = argv[1]; // Change this to command line arg

        in.open(infile);
        in >> image;
        in.close();

        image.renderImage(cout);
    } catch (...) {
        cout << "Error: an uncaught exception occured." << endl;
    }{}
    return 0;
}
