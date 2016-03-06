using namespace std;

#include <iostream>

#include <cstdlib>

class Str_Buff
{

public:
    Str_Buff();
    ~Str_Buff();
    Str_Buff(const Str_Buff&);
    Str_Buff(char*, int);
	void append(char);
	int len() const;
    void reserve(int);
    char charAt(int) const;
    
    
    Str_Buff& operator=(const Str_Buff& that);

private:
    char * _stringbuff;
	int x;
	int y;
	int z;
	int i;
	int _buffersize;
	int getback;
    mutable bool _isOwner;
    int _len;
    
    
    void release_ownership() const
	{

        this->_isOwner = false;

    }
