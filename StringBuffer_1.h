using namespace std;

#include <iostream>

#include <cstdlib>

class Str_Buff

{
    
public:
    Str_Buff();
    ~Str_Buff();
    Str_Buff (const Str_Buff&);
    
    Str_Buff(char*, int);
    char charAt(int) const;
    int len() const;
	void append(char);
	int result_print;
    void reserve(int);
    

    Str_Buff& operator= (const Str_Buff& that);
    
private:
	int _buffersize;
    char * _stringbuff;
	int x;
	int y;
	int z;
	int i;
    int _len;
   
};
