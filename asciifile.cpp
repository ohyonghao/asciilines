#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "asciifile.h"

using namespace std;

asciifile::asciifile(asciifile& /*ascii*/){
    // Do copy constructor stuff
}
asciifile::asciifile(asciifile&& rhs):
    h{rhs.h},
    w{rhs.w},
    size{rhs.size},
    instrs{rhs.instrs}
{
}
asciifile& asciifile::operator=(asciifile&& rhs){
    h = rhs.h;
    w = rhs.w;
    size = rhs.size;
    instrs = move(rhs.instrs);

    return *this;
}
ostream& asciifile::renderImage(ostream& out){
    vector<char> image;
    image.resize(this->size, '.');

    for( auto it = instrs.begin(); it != instrs.end(); ++it){
        try{
            renderInstr( *it, image );
        }catch(InvalidInstructionException e){
            out << e.what() << endl;
            return out;
        }
    }
    return printImage( out, image );
}
ostream& asciifile::printImage( ostream& out, const vector<char>& image ){
    for(int i = 0; i < h; ++i){
        for(int j=0; j < w; ++j){
            out << image[i*w + j];
        }
        out << endl;
    }
    return out;
}
void asciifile::renderInstr( const Command& command, vector<char>& canvas ){
    int row = int(command.row < 0 ? 0 : command.row);
    int col = int(command.col < 0 ? 0 : command.col);

    switch(command.dir){
    case 'h':
        renderHortLine( command.c, row, col, int(command.len), canvas);
        break;
    case 'v':
        renderVertLine( command.c, row, col, int(command.len), canvas);
        break;
    default:
        throw InvalidInstructionException();
    }
}
void asciifile::renderVertLine( char c, int row, int col, int len, vector<char> &canvas ){
    for( auto i = row; i < h && i < row + len ; ++i){
        canvas[i*w + col ] = c;
    }
}
void asciifile::renderHortLine( char c, int row, int col, int len, vector<char>& canvas ){
    for( auto j = col; j < col + len && j < w; ++j){
        canvas[row*w + j ] = c;
    }
}
istream& operator>>( istream& in, asciifile& file ){
    asciifile f;
    // read in header
    in >> f.h >> f.w;
    if(in.good()){
        f.size = f.h * f.w;
    }else{ throw CorruptFileException();}
    // read in lines to instructions

    while(!in.eof()){
        Command command;
        in >> command;
        if( in.good() )
            f.instrs.push_back(command);
    }
    std::swap(file, f);

    return in;
}

ostream& operator<<( ostream& out, asciifile& /*file*/ ){
    return out;
}
