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

    bool isOwner() 
	{

        return this->_isOwner;

    }
    
};

Str_Buff::~Str_Buff()
{

    if (_stringbuff != NULL && _isOwner)
	{

        delete [] _stringbuff;

    }

}

Str_Buff::Str_Buff()
{

    _len = -1;
    _stringbuff = NULL;
    _buffersize = -1;
    _isOwner = true;

}

Str_Buff::Str_Buff(const Str_Buff& that)
{


    if (this != &that) 
	{

        this->_isOwner = that._isOwner;
        this->_stringbuff = that._stringbuff;
        this->_buffersize = that._buffersize;
        this->_len = that._len;

        that.release_ownership();

    }

}

int Str_Buff::len() const
{

    return _len;

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
        
        if (_isOwner)
            delete [] _stringbuff;

    }

    _stringbuff = new char[size];
    _len = 0;
    _buffersize = size;
     
    _isOwner = true;

}

void Str_Buff::append(char c) 
{

    if (_len < _buffersize)

	{

		_stringbuff[_len] = c;
        _len++;
        return;

    }
    
    throw 'i';

}

Str_Buff& Str_Buff::operator=(const Str_Buff& that)
{

    if (this != &that)
	{

        if (this->_stringbuff != that._stringbuff)
		{
            
            if (this->_isOwner && this->_stringbuff != NULL) 
			{

                delete [] this->_stringbuff;

            }

        }

        this->_isOwner = that._isOwner;
        this->_stringbuff = that._stringbuff;
        this->_buffersize = that._buffersize;
        this->_len = that._len;

        that.release_ownership();

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
	int result_print;

    replace.reserve(10);

    replace.append('a');

    replace.append('l');

    replace.append('i');

    replace.append('a');

    replace.append('l');

    replace.append('i');

    print_str(replace);

    Str_Buff copy;
    copy = replace;
    replace.~Str_Buff();
    print_str(copy);

    return 0;

}
