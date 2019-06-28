#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class Command{

    friend std::istream& operator>>( std::istream&, Command&);
    friend std::ostream& operator<<( std::ostream&, const Command&);
public:
    char c{0};
    int row{0};
    int col{0};
    char dir{0};
    int len{0};
    Command();
    Command( char c, int row, int col, char dir, int len):
        c{c},
        row{row},
        col{col},
        dir{dir},
        len{len}{}
    Command( const Command& rhs):
    c{rhs.c},
    row{rhs.row},
    col{rhs.col},
    dir{rhs.dir},
    len{rhs.len}{}
    Command(Command&& rhs):
        c{rhs.c},
        row{rhs.row},
        col{rhs.col},
        dir{rhs.dir},
        len{rhs.len}{}
    Command& operator=(Command&& rhs){
        c = rhs.c;
        row = rhs.row;
        col = rhs.col;
        dir = rhs.dir;
        len = rhs.len;
        return *this;
    }

};

#endif // COMMAND_H
