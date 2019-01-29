#include "pgm.hpp"

#include <string.h>

PGMBitmap::PGMBitmap( const int width, const int height )
	: m_ptr( NULL ), m_width( width ), m_height ( height )
{
	m_ptr = new uchar[m_width * m_height * 1];
	memset( m_ptr, 0, m_width * m_height * 1 );
}

PGMBitmap::PGMBitmap( const char *const name )
	: m_ptr( NULL ), m_width( 0 ), m_height ( 0 )
{
	std::ifstream file( name, std::ios::in | std::ios::binary );
	if ( !file ) {
		std::cerr << "Cannot open PPM file " << name << std::endl;
		exit( EXIT_FAILURE );
	}
	std::string MagicNumber, line;

	// MagicNumber
	getLine( file, line );
	std::istringstream iss1( line );
	iss1 >> MagicNumber;
	if ( MagicNumber != "P5" ) { // Binary ? or nothing ?
		std::cerr << "Error reading PGM file " << name << ": unknown Magic Number \"" << MagicNumber
			 << "\". Only P5 is supported" << std::endl << std::endl;
		exit( EXIT_FAILURE );
	}

	// Image size
	getLine( file, line );
	std::istringstream iss2( line );
	iss2 >> m_width >> m_height;
	if ( m_width <= 0 || m_height <= 0 ) {
		std::cerr << "Wrong image size " << m_width << " x " << m_height << std::endl;
		exit( EXIT_FAILURE );
	}

	// Max channel value
	int maxChannelVal;
	getLine( file, line );
	std::istringstream iss3( line );
	iss3 >> maxChannelVal;
	if ( maxChannelVal > 255 ) {
		std::cerr << "Max channel value too high in " << name << std::endl;
		exit( EXIT_FAILURE );
	}

	size_t size = m_height * m_width * 1;
	// Allocate pixels
	m_ptr = new uchar[size];

	// Read pixels
	for ( int y = m_height; y-- > 0; ) { // Reading each line
		file.read( reinterpret_cast<char *>( m_ptr + y * m_width ), m_width );
	}
}

void PGMBitmap::getLine( std::ifstream &file, std::string &s ) const {
	for (;;) {
		if (!std::getline( file, s ) ) {
			std::cerr << "Error reading PGM file" << std::endl;
			exit( EXIT_FAILURE );
		}
		std::string::size_type index = s.find_first_not_of( "\n\r\t " );
		if ( index != std::string::npos && s[index] != '#' )
			break;
	}
}

void PGMBitmap::saveTo( const char *name ) const {
	std::ofstream file( name, std::ios::out | std::ios::trunc | std::ios::binary );
	file << "P5" << std::endl;						// Magic Number !
	file << m_width << " " << m_height << std::endl;// Image size
	file << "255" << std::endl;						// Max R G B

	for ( int y = m_height; y-- > 0; ) { // Writing each line
		file.write( (char *)( m_ptr + y * m_width), m_width );
	}
	file.close();
}
