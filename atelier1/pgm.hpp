#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

typedef unsigned char uchar;

class PGMBitmap {
public:

private:
	uchar	*m_ptr;

	int m_width;
	int m_height;

	PGMBitmap() {}; // undefined
public:
	PGMBitmap( const int width, const int height );
	PGMBitmap( const char *const name );
	~PGMBitmap() { delete m_ptr; }

	int		getWidth()	const	{ return m_width; }
	int		getHeight()	const	{ return m_height; }
	size_t	getSize()	const	{ return m_width * m_height * 1; }
	uchar *	getPtr()	const	{ return m_ptr; }

	uchar getPixel( const unsigned x, const unsigned y ) const {
		return m_ptr[ x + y * m_width];
	}
	void setPixel( const unsigned x, const unsigned y, const uchar col ) {
		m_ptr[ x + y * m_width ] = col;
	}

	void setAllPixel(unsigned char *pixels){
		m_ptr = pixels;
	}

	void getLine( std::ifstream &file, std::string &s ) const;

	void saveTo( const char *name ) const;
};
