#include <iostream>

class asciifile{

    friend std::ostream& operator<<( std::ostream&, asciifile& );
};
