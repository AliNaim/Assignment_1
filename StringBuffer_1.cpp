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

Str_Buff::Str_Buff()
{

    _len = -1;
    _stringbuff = NULL;
    _buffersize = -1;

}

Str_Buff::~Str_Buff()
{

    if (_stringbuff != NULL)

	{

        delete [] _stringbuff;

    }

}

Str_Buff::Str_Buff(const Str_Buff& that)
{

        
    this->_stringbuff = new char[that._buffersize];
    this->_buffersize = that._buffersize;
    this->_len = that._len;

    for (i = 0; i < that.len(); i++)
	{

        this->_stringbuff[i] = that._stringbuff[i];
    }
    
 }

void Str_Buff::append(char c) 
{

    if (_len < _buffersize){
        _stringbuff[_len] = c;
        _len++;
        return;

    }

    throw 'i';

}

char Str_Buff::charAt(int index) const
{
    
    if (index >= 0 && index < _len)

	{

        return _stringbuff[index];

    }

    throw 'i';
}

void Str_Buff::reserve(int size)
{

    if (_stringbuff != NULL)
	{

        delete [] _stringbuff;

    }
    
    _stringbuff = new char[size];
    _len = 0;
    _buffersize = size;

}

int Str_Buff::len() const

{

    return _len;

}


Str_Buff& Str_Buff::operator= (const Str_Buff& that)
{
    
    if (this != &that)
	{
        
        if (this->_stringbuff != NULL)
            delete [] this->_stringbuff;
       
        this->_stringbuff = new char[that._buffersize];
        this->_buffersize = that._buffersize;
    
        for (i = 0; i < that.len(); i++) {
            this->_stringbuff[i] = that._stringbuff[i];

        }
    
        this->_len = that._len;
    }
    
    return *this;
}

void print_str(Str_Buff& replace) 
{
	int i;
    for (i = 0; i < replace.len(); i++)

	{

        cout << replace.charAt(i);

    }

    cout << "\n \n";

}


int main(int argc, char** argv)
{
    
    Str_Buff replace;
    
    replace.reserve(10);
    
    replace.append('a');

    replace.append('l');

    replace.append('i');

    replace.append('a');

    replace.append('l');

    replace.append('i');
    
    print_str(replace); 
    
    Str_Buff copy;
    copy.reserve(20);
    copy = replace;
    
    print_str(copy);
    
    return 0;

}

