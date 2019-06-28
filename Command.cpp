#include "Command.h"

using namespace std;
Command::Command()
{

}

istream& operator>>(istream& in, Command& command){
    in >> command.c;
    in >> command.row;
    in >> command.col;
    in >> command.dir;
    in >> command.len;
    return in;
}

ostream& operator<<(ostream& out, const Command& command){
    out << command.c   << ' ';
    out << command.row << ' ';
    out << command.col << ' ';
    out << command.dir << ' ';
    out << command.len << ' ';
    return out;
}
