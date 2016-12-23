#ifdef _MSC_VER
#ifdef MP4PARSERLIB_EXPORTS
#define MP4PARSERLIB_API __declspec(dllexport)
#else
#define MP4PARSERLIB_API __declspec(dllimport)
#endif
#endif

#include "Include.h"


// MP4 parsing error codes...
const int kMP4ParserError_NoError = 0;
const int kMP4ParserError_NullFileName = -1;
const int kMP4ParserError_OpenInputFileFailed = -2;

class MP4PARSERLIB_API CMP4Parser
{
public:
	CMP4Parser(const char *inputMP4FileName);
	~CMP4Parser();

	int Parse();

private:
	const char    *m_fileName;		// input file name...
	UINT64        m_fileSize;		// input file size in bytes...
	BYTE          *m_fileBuf;		// buffer pointer of input file...
	UINT64        m_bytesCnt;		// bytes counter processed...

	std::ifstream m_inFileStream;	// input file stream...
	int		open_input_file();		// open input file by file name...
	void	close_input_file();		// close input file...
};