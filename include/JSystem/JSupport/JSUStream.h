#ifndef _JSYSTEM_JSUINPUTSTREAM_H
#define _JSYSTEM_JSUINPUTSTREAM_H

#include "JSystem/JKernel/JKRFile.h"
#include "types.h"

// Named after standard C++ constants with the exact same meaning.
enum JSUStreamSeekFrom { SEEK_SET = 0, SEEK_CUR, SEEK_END };

struct JSUIosBase {
	inline JSUIosBase()
	    : mIsEOFMaybe(0)
	{
	}

	virtual ~JSUIosBase() { } //_08 (weak)

	// _00 VTBL
	u8 mIsEOFMaybe; // _04
};

struct JSUInputStream : public JSUIosBase {
	virtual ~JSUInputStream();             // _08
	virtual int getAvailable() const = 0;  // _0C
	virtual s32 skip(long);                // _10
	virtual int readData(void*, long) = 0; // _14

	s32 read(void*, long);
	char* read(char*);

	/** @fabricated */
	inline bool readBool()
	{
		bool temp;
		read(&temp, 1);
		return temp;
	}

	inline u8 readByte()
	{
		u8 byte;
		read(&byte, 1);
		return byte;
	}

	/** @fabricated */
	inline s16 readS16()
	{
		s16 temp;
		read(&temp, 2);
		return temp;
	}

	/** @fabricated */
	inline f32 readS16ToFloat()
	{
		s16 temp;
		read(&temp, 2);
		return temp;
	}

	/** @fabricated */
	inline u16 readU16()
	{
		u16 temp;
		read(&temp, 2);
		return temp;
	}

	/** @fabricated */
	inline f32 readU16ToFloat()
	{
		u16 temp;
		read(&temp, 2);
		return temp;
	}

	/** @fabricated */
	inline u32 readU32()
	{
		u32 temp;
		read(&temp, 4);
		return temp;
	}

	// _00		= VTBL
	// _00-_08	= JSUIosBase
};

struct JSURandomInputStream : public JSUInputStream {
	virtual ~JSURandomInputStream() { }                                      // _08 (weak)
	virtual int getAvailable() const { return getLength() - getPosition(); } // _0C (weak)
	virtual s32 skip(long);                                                  // _10
	virtual int readData(void*, long)            = 0;                        // _14
	virtual int getLength() const                = 0;                        // _18
	virtual int getPosition() const              = 0;                        // _1C
	virtual int seekPos(long, JSUStreamSeekFrom) = 0;                        // _20

	u32 align(s32);
	size_t peek(void*, long);
	void seek(long, JSUStreamSeekFrom);

	// _00		= VTBL
	// _00-_08	= JSUIosBase
};

struct JSUMemoryInputStream : public JSURandomInputStream {
	virtual ~JSUMemoryInputStream() { }                   // _08 (weak)
	virtual int readData(void*, long);                    // _14
	virtual int getLength() const { return mLength; }     // _18 (weak)
	virtual int getPosition() const { return mPosition; } // _1C (weak)
	virtual int seekPos(long, JSUStreamSeekFrom);         // _20

	void setBuffer(const void*, long);

	// _00		= VTBL
	// _00-_08	= JSUIosBase
	const void* mObject; // _08
	long mLength;        // _0C
	int mPosition;       // _10
};

// Size: 0x10
struct JSUFileInputStream : public JSURandomInputStream {
	JSUFileInputStream(JKRFile*);

	virtual ~JSUFileInputStream() { }                                            // _08 (weak)
	virtual int readData(void*, long);                                           // _14
	virtual int getLength() const { return ((JKRFile*)mObject)->getFileSize(); } // _18 (weak)
	virtual int getPosition() const { return mLength; }                          // _1C (weak)
	virtual int seekPos(long, JSUStreamSeekFrom);                                // _20

	// _00		= VTBL
	// _00-_08	= JSUIosBase
	const void* mObject; // _08
	long mLength;        // _0C
	int mPosition;       // _10
};

/* Not much remains of this. */
struct JSUOutputStream : public JSUIosBase {
	virtual ~JSUOutputStream(); // _08
	/* No calls to this appear to have survived. */
	virtual void _0C(); // _0C
	/* Just a guess. No instances of this survived in vanilla. */
	virtual long writeData(const void*, long) = 0; // _10

	int write(const void*, long);
	void write(const char*);

	// _00		= VTBL
	// _00-_08	= JSUIosBase
};

struct JSUMemoryOutputStream : public JSUOutputStream {
	// Unused/inlined:
	virtual ~JSUMemoryOutputStream();             // _08
	virtual long writeData(const void*, long);    // _10
	virtual int getLength() const;                // _14?
	virtual int getPosition() const;              // _18?
	virtual int seekPos(long, JSUStreamSeekFrom); // _1C?

	void setBuffer(void*, long);
};

#endif
