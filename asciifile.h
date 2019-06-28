#include <iostream>
#include <exception>
#include <vector>
#include <list>

#include "Command.h"

class asciifile{
    int h{0};
    int w{0};
    int size{0};

    std::list<Command> instrs;
public:
    asciifile() = default;
    asciifile(asciifile &filename);
    asciifile(asciifile&&);
    asciifile& operator=(asciifile&&);

    std::ostream& renderImage( std::ostream& );

private:
    void renderInstr( const Command& instr, std::vector<char>& canvas );
    void renderVertLine(char c, int row, int col, int len, std::vector<char> &canvas );
    void renderHortLine(char c, int row, int col, int len, std::vector<char> &canvas );
    std::ostream& printImage(std::ostream& out, const std::vector<char> &canvas);
    friend std::istream& operator>>( std::istream&, asciifile& );
    friend std::ostream& operator<<( std::ostream&, const asciifile& );
};

class CorruptFileException: public std::exception{
    inline const char * what() const noexcept{
        return "Corrupt File";
    }
};

class InvalidInstructionException: public std::exception{
public: inline const char * what() const noexcept{
        return "Invalid Instruction";
    }
};
