// This comes with no warranty, implied or otherwise

// This data structure was designed to support Proportional fonts
// on Arduinos. It can however handle any ttf font that has been converted
// using the conversion program. These could be fixed width or proportional 
// fonts. Individual characters do not have to be multiples of 8 bits wide. 
// Any width is fine and does not need to be fixed.

// The data bits are packed to minimize data requirements, but the tradeoff
// is that a header is required per character.

// ubuntu_mono.c
// Point Size   : 14
// Memory usage : 2963 bytes
// # characters : 225

// Header Format (to make Arduino UTFT Compatible):
// ------------------------------------------------
// Character Width (Used as a marker to indicate use this format. i.e.: = 0x00)
// Character Height
// First Character (Reserved. 0x00)
// Number Of Characters (Reserved. 0x00)


const unsigned char tft_ubuntu_mono[] = 
{
0x00, 0x0D, 0x00, 0x00,

// Individual Character Format:
// ----------------------------
// Character Code
// Adjusted Y Offset
// Width
// Height
// xOffset
// xDelta (the distance to move the cursor. Effective width of the character.)
// Data[n]

// NOTE: You can remove any of these characters if they are not needed in
// your application. The first character number in each Glyph indicates
// the ASCII character code. Therefore, these do not have to be sequential.
// Just remove all the content for a particular character to save space.

// ' '
0x20,0x0D,0x00,0x00,0x00,0x07,

// '!'
0x21,0x04,0x02,0x09,0x03,0x07,
0xFF,0xF3,0xC0,
// '"'
0x22,0x03,0x05,0x04,0x00,0x07,
0xDE,0xF7,0xB0,
// '#'
0x23,0x04,0x07,0x09,0x00,0x07,
0x14,0x2B,0xFF,0xF2,0x9F,0xFF,0xA8,0x50,
// '$'
0x24,0x03,0x06,0x0B,0x00,0x07,
0x31,0xEF,0xF0,0xF1,0xE1,0xC3,0xFD,0xC3,0x00,
// '%'
0x25,0x04,0x07,0x09,0x00,0x07,
0x45,0x52,0xA3,0x82,0x04,0x92,0xA5,0x8C,
// '&'
0x26,0x04,0x08,0x09,0x00,0x07,
0x30,0x78,0x48,0x70,0x74,0xDC,0xCC,0xFC,0x7E,
// '''
0x27,0x03,0x02,0x04,0x01,0x07,
0xFF,
// '('
0x28,0x03,0x05,0x0C,0x01,0x07,
0x19,0x98,0xCC,0x63,0x18,0x63,0x0C,0x30,
// ')'
0x29,0x03,0x05,0x0C,0x01,0x07,
0xC3,0x0C,0x61,0x8C,0x63,0x31,0x98,0x80,
// '*'
0x2A,0x04,0x05,0x05,0x01,0x07,
0x25,0x7E,0x47,0x00,
// '+'
0x2B,0x06,0x06,0x06,0x00,0x07,
0x30,0xCF,0xFF,0x30,0xC0,
// ','
0x2C,0x0A,0x03,0x05,0x02,0x07,
0xFD,0x88,
// '-'
0x2D,0x09,0x04,0x02,0x02,0x07,
0xFF,
// '.'
0x2E,0x0A,0x03,0x03,0x02,0x07,
0xFF,0x80,
// '/'
0x2F,0x03,0x06,0x0C,0x00,0x07,
0x0C,0x31,0x86,0x18,0xC3,0x0C,0x31,0x86,0x18,
// '0'
0x30,0x04,0x06,0x09,0x00,0x07,
0x79,0xEC,0xFF,0xFF,0x3C,0xDE,0x78,
// '1'
0x31,0x04,0x06,0x09,0x00,0x07,
0x31,0xCF,0x0C,0x30,0xC3,0x3F,0xFC,
// '2'
0x32,0x04,0x06,0x09,0x00,0x07,
0x39,0xF0,0xC3,0x18,0xC2,0x1F,0x7C,
// '3'
0x33,0x04,0x05,0x09,0x01,0x07,
0x77,0xC6,0xE7,0x0C,0x7F,0xF0,
// '4'
0x34,0x04,0x07,0x09,0x00,0x07,
0x0C,0x38,0xF3,0x6C,0xDF,0xFF,0x86,0x0C,
// '5'
0x35,0x04,0x06,0x09,0x00,0x07,
0x7D,0xF6,0x1E,0x7C,0x30,0xFF,0xF8,
// '6'
0x36,0x04,0x06,0x09,0x00,0x07,
0x1D,0xF6,0x3C,0xFF,0x3C,0xFF,0x78,
// '7'
0x37,0x04,0x06,0x09,0x00,0x07,
0xFF,0xF0,0xC6,0x30,0xC3,0x18,0x60,
// '8'
0x38,0x04,0x06,0x09,0x00,0x07,
0x7B,0xFC,0xF3,0x7B,0x7C,0xFF,0x78,
// '9'
0x39,0x04,0x05,0x09,0x01,0x07,
0x77,0xF7,0xBF,0xBC,0xEE,0x60,
// ':'
0x3A,0x06,0x03,0x07,0x02,0x07,
0xFF,0x8F,0xF8,
// ';'
0x3B,0x06,0x03,0x09,0x02,0x07,
0xFF,0x8F,0xD8,0x80,
// '<'
0x3C,0x03,0x06,0x09,0x00,0x07,
0x04,0x73,0xDC,0x61,0xC3,0xC7,0x04,
// '='
0x3D,0x07,0x05,0x05,0x01,0x07,
0xFF,0xC1,0xFF,0x80,
// '>'
0x3E,0x03,0x05,0x09,0x01,0x07,
0x86,0x3C,0x71,0x9F,0xD8,0x80,
// '?'
0x3F,0x04,0x05,0x09,0x01,0x07,
0x77,0xC6,0x33,0x30,0x0C,0x60,
// '@'
0x40,0x04,0x07,0x0B,0x00,0x07,
0x3C,0x87,0x7D,0xFB,0x36,0xED,0xDF,0xDE,0x80,0xF0,
// 'A'
0x41,0x04,0x07,0x09,0x00,0x07,
0x38,0x70,0xE1,0x66,0xCF,0x9F,0x63,0xC6,
// 'B'
0x42,0x04,0x06,0x09,0x00,0x07,
0xFB,0xFC,0xFE,0xFF,0x3C,0xFF,0xF8,
// 'C'
0x43,0x04,0x06,0x09,0x00,0x07,
0x39,0xFE,0x70,0xC3,0x0E,0x5F,0x38,
// 'D'
0x44,0x04,0x06,0x09,0x00,0x07,
0xF3,0xED,0xF3,0xCF,0x3D,0xFE,0xF0,
// 'E'
0x45,0x04,0x05,0x09,0x01,0x07,
0xFF,0xF1,0xEF,0x63,0x1F,0xF8,
// 'F'
0x46,0x04,0x05,0x09,0x01,0x07,
0xFF,0xF1,0x8F,0xFF,0x18,0xC0,
// 'G'
0x47,0x04,0x06,0x09,0x00,0x07,
0x3D,0xFE,0x30,0xCF,0x3E,0xDF,0x3C,
// 'H'
0x48,0x04,0x06,0x09,0x00,0x07,
0xCF,0x3C,0xFF,0xFF,0x3C,0xF3,0xCC,
// 'I'
0x49,0x04,0x06,0x09,0x00,0x07,
0xFF,0xF3,0x0C,0x30,0xC3,0x3F,0xFC,
// 'J'
0x4A,0x04,0x05,0x09,0x01,0x07,
0xFF,0xC6,0x31,0x8C,0x7F,0x70,
// 'K'
0x4B,0x04,0x06,0x09,0x01,0x07,
0xCF,0x6D,0xBC,0xF3,0xCD,0xB6,0xCC,
// 'L'
0x4C,0x04,0x05,0x09,0x00,0x07,
0xC6,0x31,0x8C,0x63,0x1F,0xF8,
// 'M'
0x4D,0x04,0x06,0x09,0x01,0x07,
0xCB,0x2F,0xBF,0xFF,0xFC,0xF3,0xCC,
// 'N'
0x4E,0x04,0x06,0x09,0x00,0x07,
0xCF,0x3E,0xFB,0xDF,0x7D,0xF3,0xCC,
// 'O'
0x4F,0x04,0x06,0x09,0x00,0x07,
0x79,0xEC,0xF3,0xCF,0x3C,0xDE,0x78,
// 'P'
0x50,0x04,0x06,0x09,0x00,0x07,
0xFB,0xFC,0xF3,0xFF,0xEC,0x30,0xC0,
// 'Q'
0x51,0x04,0x06,0x0B,0x00,0x07,
0x79,0xEC,0xF3,0xCF,0x3C,0xDE,0x78,0xF0,0xC0,
// 'R'
0x52,0x04,0x06,0x09,0x00,0x07,
0xFB,0xFC,0xF3,0xFF,0xCD,0xB6,0xCC,
// 'S'
0x53,0x04,0x06,0x09,0x00,0x07,
0x7F,0xFC,0x3C,0x78,0x78,0xFF,0x78,
// 'T'
0x54,0x04,0x06,0x09,0x00,0x07,
0xFF,0xF3,0x0C,0x30,0xC3,0x0C,0x30,
// 'U'
0x55,0x04,0x06,0x09,0x00,0x07,
0xCF,0x3C,0xF3,0xCF,0x3C,0xFF,0x78,
// 'V'
0x56,0x04,0x06,0x09,0x00,0x07,
0xCF,0x3C,0xD2,0x49,0xE7,0x8C,0x30,
// 'W'
0x57,0x04,0x06,0x09,0x00,0x07,
0xCF,0x3C,0xFF,0xFF,0xFF,0xF3,0xCC,
// 'X'
0x58,0x04,0x07,0x09,0x00,0x07,
0xC6,0xD9,0xF1,0xC3,0x87,0x1B,0x36,0xC6,
// 'Y'
0x59,0x04,0x06,0x09,0x00,0x07,
0xCF,0x36,0x9E,0x30,0xC3,0x0C,0x30,
// 'Z'
0x5A,0x04,0x05,0x09,0x00,0x07,
0xFF,0xC4,0x62,0x21,0x1F,0xF8,
// '['
0x5B,0x03,0x04,0x0C,0x02,0x07,
0xFF,0xCC,0xCC,0xCC,0xCC,0xFF,
// '\'
0x5C,0x03,0x05,0x0C,0x01,0x07,
0xC6,0x18,0xC6,0x30,0xC6,0x31,0x86,0x30,
// ']'
0x5D,0x03,0x04,0x0C,0x01,0x07,
0xFF,0x33,0x33,0x33,0x33,0xFF,
// '^'
0x5E,0x04,0x07,0x05,0x00,0x07,
0x38,0x71,0xB3,0x64,0x40,
// '_'
0x5F,0x0D,0x07,0x02,0x00,0x07,
0xFF,0xFC,
// '`'
0x60,0x03,0x03,0x02,0x02,0x07,
0xCC,
// 'a'
0x61,0x06,0x06,0x07,0x00,0x07,
0x79,0xF0,0xDF,0xCF,0xF7,0xC0,
// 'b'
0x62,0x03,0x06,0x0A,0x00,0x07,
0xC3,0x0C,0x3E,0xFF,0x3C,0xF3,0xFB,0xC0,
// 'c'
0x63,0x06,0x06,0x07,0x00,0x07,
0x3D,0xFE,0x30,0xC1,0xF3,0xC0,
// 'd'
0x64,0x03,0x06,0x0A,0x00,0x07,
0x0C,0x30,0xDF,0xFF,0x3C,0xF3,0x7D,0xF0,
// 'e'
0x65,0x06,0x07,0x07,0x00,0x07,
0x38,0xFB,0x37,0xEC,0x0F,0x8F,0x00,
// 'f'
0x66,0x03,0x07,0x0A,0x00,0x07,
0x1E,0x7C,0xC7,0xEF,0xC6,0x0C,0x18,0x30,0x60,
// 'g'
0x67,0x06,0x06,0x09,0x00,0x07,
0x7F,0xFC,0xF3,0xFD,0xF0,0xFF,0xF8,
// 'h'
0x68,0x03,0x06,0x0A,0x00,0x07,
0xC3,0x0C,0x3E,0xFF,0x3C,0xF3,0xCF,0x30,
// 'i'
0x69,0x03,0x07,0x0A,0x00,0x07,
0x30,0x60,0x07,0x8F,0x06,0x0C,0x18,0x3C,0x38,
// 'j'
0x6A,0x03,0x06,0x0C,0xFF,0x07,
0x18,0x60,0x1F,0x7C,0x30,0xC3,0x0D,0x37,0xDE,
// 'k'
0x6B,0x03,0x07,0x0A,0x00,0x07,
0xC1,0x83,0x06,0x6D,0x9E,0x3C,0x6C,0xCD,0x8C,
// 'l'
0x6C,0x03,0x06,0x0A,0x00,0x07,
0xF3,0xC3,0x0C,0x30,0xC3,0x0C,0x3C,0x70,
// 'm'
0x6D,0x06,0x07,0x07,0x00,0x07,
0xFD,0xFF,0x5E,0xBC,0x78,0xF1,0x80,
// 'n'
0x6E,0x06,0x06,0x07,0x00,0x07,
0xFB,0xFC,0xF3,0xCF,0x3C,0xC0,
// 'o'
0x6F,0x06,0x06,0x07,0x00,0x07,
0x79,0xEC,0xF3,0xCD,0xE7,0x80,
// 'p'
0x70,0x06,0x06,0x09,0x00,0x07,
0xF3,0xEC,0xF3,0xCF,0xFF,0xB0,0xC0,
// 'q'
0x71,0x06,0x06,0x09,0x00,0x07,
0x3D,0xFC,0xF3,0xCF,0xF7,0xC3,0x0C,
// 'r'
0x72,0x06,0x05,0x07,0x00,0x07,
0xFF,0xF1,0x8C,0x63,0x00,
// 's'
0x73,0x06,0x05,0x07,0x00,0x07,
0x7F,0xF0,0xE1,0xFF,0xC0,
// 't'
0x74,0x04,0x07,0x09,0x00,0x07,
0x30,0x63,0xFF,0xF3,0x06,0x0C,0x1F,0x1E,
// 'u'
0x75,0x06,0x06,0x07,0x00,0x07,
0xCF,0x3C,0xF3,0xCF,0xF7,0xC0,
// 'v'
0x76,0x06,0x06,0x07,0x00,0x07,
0xCD,0x34,0x9E,0x78,0xC3,0x00,
// 'w'
0x77,0x06,0x07,0x07,0x00,0x07,
0xC7,0xAF,0x5F,0xF6,0xCD,0x9B,0x00,
// 'x'
0x78,0x06,0x07,0x07,0x00,0x07,
0xE6,0xD8,0xE1,0xC3,0xCD,0xB1,0x80,
// 'y'
0x79,0x06,0x07,0x09,0x00,0x07,
0x66,0xCC,0xD1,0xE3,0xC3,0x06,0x08,0xE0,
// 'z'
0x7A,0x06,0x05,0x07,0x00,0x07,
0xFF,0xCC,0x44,0x7F,0xE0,
// '{'
0x7B,0x03,0x06,0x0C,0x01,0x07,
0x1C,0xF3,0x0C,0x33,0x8E,0x0C,0x30,0xC3,0xC7,
// '|'
0x7C,0x03,0x02,0x0C,0x03,0x07,
0xFF,0xFF,0xFF,
// '}'
0x7D,0x03,0x05,0x0C,0x01,0x07,
0xC7,0x18,0xC6,0x1C,0xEC,0x63,0x39,0x80,
// '~'
0x7E,0x08,0x07,0x03,0x00,0x07,
0x77,0xFF,0x70,
// ''
0x7F,0x02,0x06,0x0B,0x01,0x07,
0xFE,0x18,0x61,0x86,0x18,0x61,0x86,0x1F,0xC0,
// '�'
0x80,0x02,0x06,0x0B,0x01,0x07,
0xFE,0x18,0x61,0x86,0x18,0x61,0x86,0x1F,0xC0,
// '�'
0x81,0x02,0x06,0x0B,0x01,0x07,
0xFE,0x18,0x61,0x86,0x18,0x61,0x86,0x1F,0xC0,
// '�'
0x82,0x02,0x06,0x0B,0x01,0x07,
0xFE,0x18,0x61,0x86,0x18,0x61,0x86,0x1F,0xC0,
// '�'
0x84,0x02,0x06,0x0B,0x01,0x07,
0xFE,0x18,0x61,0x86,0x18,0x61,0x86,0x1F,0xC0,
// '�'
0xA0,0x0D,0x00,0x00,0x00,0x07,

// '�'
0xA1,0x06,0x02,0x09,0x03,0x07,
0xF3,0xFF,0xC0,
// '�'
0xA2,0x04,0x06,0x0B,0x00,0x07,
0x18,0x63,0xDF,0xC3,0x0C,0x1F,0x3C,0x61,0x80,
// '�'
0xA3,0x04,0x05,0x09,0x01,0x07,
0x3B,0xD8,0xCF,0x79,0x8F,0x78,
// '�'
0xA4,0x06,0x07,0x06,0x00,0x07,
0x44,0xF9,0x32,0x67,0xC8,0x80,
// '�'
0xA5,0x04,0x07,0x09,0x00,0x07,
0xC6,0xD8,0xA1,0xC7,0xC2,0x1F,0x08,0x10,
// '�'
0xA6,0x03,0x02,0x0C,0x03,0x08,
0xFF,0xC3,0xFF,
// '�'
0xA7,0x04,0x05,0x0A,0x01,0x07,
0x7F,0xF1,0xED,0xED,0xE3,0xFF,0x80,
// '�'
0xA8,0x03,0x05,0x02,0x01,0x07,
0xDE,0xC0,
// '�'
0xA9,0x06,0x07,0x07,0x00,0x07,
0x38,0x8A,0x6D,0x19,0xA8,0x8E,0x00,
// '�'
0xAA,0x04,0x05,0x05,0x01,0x07,
0xF0,0x5F,0x17,0x80,
// '�'
0xAB,0x06,0x07,0x06,0x00,0x07,
0x22,0xCF,0x36,0x66,0x64,0x40,
// '�'
0xAC,0x08,0x05,0x05,0x01,0x07,
0xFF,0xC2,0x10,0x80,
// '�'
0xAD,0x09,0x04,0x02,0x02,0x07,
0xFF,
// '�'
0xAE,0x06,0x07,0x07,0x00,0x07,
0x38,0x8A,0xED,0xDA,0xA8,0x8E,0x00,
// '�'
0xAF,0x04,0x04,0x01,0x02,0x07,
0xF0,
// '�'
0xB0,0x03,0x04,0x04,0x02,0x07,
0x69,0x96,
// '�'
0xB1,0x04,0x06,0x09,0x01,0x07,
0x30,0xCF,0xFF,0x30,0xC0,0x3F,0xFC,
// '�'
0xB2,0x04,0x03,0x05,0x02,0x07,
0xF5,0xCE,
// '�'
0xB3,0x04,0x04,0x05,0x02,0x07,
0xEA,0x62,0xE0,
// '�'
0xB4,0x03,0x03,0x02,0x02,0x07,
0x78,
// '�'
0xB5,0x06,0x05,0x09,0x01,0x07,
0xDE,0xF7,0xBD,0xFF,0xF8,0xC0,
// '�'
0xB6,0x04,0x07,0x0B,0x00,0x07,
0x7F,0xFF,0xDF,0xB7,0x66,0xCD,0x9B,0x36,0x6C,0xD8,
// '�'
0xB7,0x07,0x03,0x03,0x02,0x07,
0xFF,0x80,
// '�'
0xB8,0x0D,0x03,0x02,0x02,0x07,
0x3C,
// '�'
0xB9,0x04,0x03,0x05,0x02,0x07,
0x59,0x2E,
// '�'
0xBA,0x04,0x05,0x07,0x01,0x07,
0x77,0xE7,0x39,0xFD,0xC0,
// '�'
0xBB,0x06,0x07,0x06,0x01,0x07,
0x90,0xB1,0xB3,0x65,0x92,0x00,
// '�'
0xBC,0x04,0x07,0x09,0x00,0x07,
0x44,0x91,0x22,0x82,0x05,0x93,0x2F,0x84,
// '�'
0xBD,0x04,0x07,0x09,0x00,0x07,
0x45,0x91,0x22,0x81,0x04,0xC8,0xA2,0x4E,
// '�'
0xBE,0x04,0x07,0x09,0x00,0x07,
0xE4,0xC8,0xA7,0x41,0x02,0x8B,0x27,0x44,
// '�'
0xBF,0x06,0x05,0x09,0x00,0x07,
0x31,0x80,0x66,0x63,0x3F,0x70,
// '�'
0xC0,0x01,0x07,0x0C,0x00,0x07,
0x30,0x30,0x01,0xC3,0x87,0x0B,0x36,0x7C,0xFB,0x1E,0x30,
// '�'
0xC1,0x01,0x07,0x0C,0x00,0x07,
0x18,0x60,0x01,0xC3,0x87,0x0B,0x36,0x7C,0xFB,0x1E,0x30,
// '�'
0xC2,0x00,0x07,0x0D,0x00,0x07,
0x10,0x70,0xA0,0x03,0x87,0x0E,0x16,0x6C,0xF9,0xF6,0x3C,0x60,
// '�'
0xC3,0x01,0x07,0x0C,0x00,0x07,
0x24,0xB0,0x01,0xC3,0x87,0x0B,0x36,0x7C,0xFB,0x1E,0x30,
// '�'
0xC4,0x01,0x07,0x0C,0x00,0x07,
0x6C,0xD8,0x01,0xC3,0x87,0x0B,0x36,0x7C,0xFB,0x1E,0x30,
// '�'
0xC5,0x01,0x07,0x0C,0x00,0x07,
0x00,0x70,0xA1,0xC3,0x87,0x0A,0x36,0x7C,0xFB,0x1E,0x30,
// '�'
0xC6,0x04,0x07,0x09,0x00,0x07,
0x1E,0x7C,0xE1,0x66,0xCF,0x1E,0x67,0xCE,
// '�'
0xC7,0x04,0x07,0x0B,0x00,0x07,
0x3C,0xFF,0x8E,0x0C,0x18,0x38,0x3F,0x3C,0x10,0xE0,
// '�'
0xC8,0x01,0x05,0x0C,0x01,0x07,
0x61,0x81,0xFF,0xE3,0xDE,0xC6,0x3F,0xF0,
// '�'
0xC9,0x01,0x05,0x0C,0x01,0x07,
0x33,0x01,0xFF,0xE3,0xDE,0xC6,0x3F,0xF0,
// '�'
0xCA,0x00,0x05,0x0D,0x01,0x07,
0x23,0x94,0x0F,0xFF,0x1E,0xF6,0x31,0xFF,0x80,
// '�'
0xCB,0x01,0x05,0x0C,0x01,0x07,
0xDE,0xC1,0xFF,0xE3,0xDE,0xC6,0x3F,0xF0,
// '�'
0xCC,0x01,0x06,0x0C,0x00,0x07,
0x60,0xC0,0x3F,0xFC,0xC3,0x0C,0x30,0xCF,0xFF,
// '�'
0xCD,0x01,0x06,0x0C,0x00,0x07,
0x31,0x80,0x3F,0xFC,0xC3,0x0C,0x30,0xCF,0xFF,
// '�'
0xCE,0x00,0x06,0x0D,0x00,0x07,
0x21,0xC5,0x00,0xFF,0xF3,0x0C,0x30,0xC3,0x3F,0xFC,
// '�'
0xCF,0x01,0x06,0x0C,0x00,0x07,
0x6D,0xB0,0x3F,0xFC,0xC3,0x0C,0x30,0xCF,0xFF,
// '�'
0xD0,0x04,0x07,0x09,0x00,0x07,
0x78,0xF9,0xBB,0x3F,0x6C,0xDB,0xBE,0x78,
// '�'
0xD1,0x01,0x06,0x0C,0x00,0x07,
0x25,0x60,0x33,0xCF,0xBE,0xF7,0xDF,0x7C,0xF3,
// '�'
0xD2,0x01,0x06,0x0C,0x00,0x07,
0x60,0xC0,0x1E,0x7B,0x3C,0xF3,0xCF,0x37,0x9E,
// '�'
0xD3,0x01,0x06,0x0C,0x00,0x07,
0x31,0x80,0x1E,0x7B,0x3C,0xF3,0xCF,0x37,0x9E,
// '�'
0xD4,0x00,0x06,0x0D,0x00,0x07,
0x10,0xE2,0x80,0x79,0xEC,0xF3,0xCF,0x3C,0xDE,0x78,
// '�'
0xD5,0x01,0x06,0x0C,0x00,0x07,
0x25,0x60,0x1E,0x7B,0x3C,0xF3,0xCF,0x37,0x9E,
// '�'
0xD6,0x01,0x06,0x0C,0x00,0x07,
0x6D,0xB0,0x1E,0x7B,0x3C,0xF3,0xCF,0x37,0x9E,
// '�'
0xD7,0x07,0x05,0x06,0x01,0x07,
0x8B,0x9C,0xE9,0x80,
// '�'
0xD8,0x04,0x07,0x0A,0x00,0x07,
0x3C,0xFB,0x3E,0xFD,0x7E,0xFB,0xBE,0x78,0x80,
// '�'
0xD9,0x01,0x06,0x0C,0x00,0x07,
0x60,0xC0,0x33,0xCF,0x3C,0xF3,0xCF,0x3F,0xDE,
// '�'
0xDA,0x01,0x06,0x0C,0x00,0x07,
0x18,0xC0,0x33,0xCF,0x3C,0xF3,0xCF,0x3F,0xDE,
// '�'
0xDB,0x00,0x06,0x0D,0x00,0x07,
0x10,0xE2,0x80,0xCF,0x3C,0xF3,0xCF,0x3C,0xFF,0x78,
// '�'
0xDC,0x01,0x06,0x0C,0x00,0x07,
0x6D,0xB0,0x33,0xCF,0x3C,0xF3,0xCF,0x3F,0xDE,
// '�'
0xDD,0x01,0x06,0x0C,0x00,0x07,
0x18,0xC0,0x33,0xCD,0xA7,0x8C,0x30,0xC3,0x0C,
// '�'
0xDE,0x04,0x06,0x09,0x00,0x07,
0xC3,0xEF,0xF3,0xCF,0xFF,0xB0,0xC0,
// '�'
0xDF,0x03,0x07,0x0A,0x00,0x07,
0x79,0xFB,0x36,0x6D,0x9B,0x33,0x63,0xDF,0xB8,
// '�'
0xE0,0x03,0x06,0x0A,0x00,0x07,
0x30,0x60,0x1E,0x7C,0x37,0xF3,0xFD,0xF0,
// '�'
0xE1,0x03,0x06,0x0A,0x00,0x07,
0x18,0xC0,0x1E,0x7C,0x37,0xF3,0xFD,0xF0,
// '�'
0xE2,0x02,0x06,0x0B,0x00,0x07,
0x10,0xE2,0x80,0x79,0xF0,0xDF,0xCF,0xF7,0xC0,
// '�'
0xE3,0x03,0x06,0x0A,0x00,0x07,
0x25,0x60,0x1E,0x7C,0x37,0xF3,0xFD,0xF0,
// '�'
0xE4,0x03,0x06,0x0A,0x00,0x07,
0x6D,0xB0,0x1E,0x7C,0x37,0xF3,0xFD,0xF0,
// '�'
0xE5,0x02,0x06,0x0B,0x00,0x07,
0x38,0xA3,0x80,0x79,0xF0,0xDF,0xCF,0xF7,0xC0,
// '�'
0xE6,0x06,0x08,0x07,0x00,0x07,
0x7C,0x7E,0x1A,0x7E,0xD8,0xFE,0x7E,
// '�'
0xE7,0x06,0x06,0x09,0x00,0x07,
0x3D,0xFE,0x30,0xC1,0xF3,0xC6,0x38,
// '�'
0xE8,0x03,0x07,0x0A,0x00,0x07,
0x60,0x60,0x01,0xC7,0xD9,0xBF,0x60,0x7C,0x78,
// '�'
0xE9,0x03,0x07,0x0A,0x00,0x07,
0x18,0x60,0x01,0xC7,0xD9,0xBF,0x60,0x7C,0x78,
// '�'
0xEA,0x02,0x07,0x0B,0x00,0x07,
0x10,0x70,0xA0,0x03,0x8F,0xB3,0x7E,0xC0,0xF8,0xF0,
// '�'
0xEB,0x03,0x07,0x0A,0x00,0x07,
0x6C,0xD8,0x01,0xC7,0xD9,0xBF,0x60,0x7C,0x78,
// '�'
0xEC,0x03,0x06,0x0A,0x01,0x07,
0x60,0xC0,0x3C,0xF0,0xC3,0x0C,0x3C,0x70,
// '�'
0xED,0x03,0x06,0x0A,0x01,0x07,
0x31,0x80,0x3C,0xF0,0xC3,0x0C,0x3C,0x70,
// '�'
0xEE,0x02,0x06,0x0B,0x01,0x07,
0x21,0xC5,0x00,0xF3,0xC3,0x0C,0x30,0xF1,0xC0,
// '�'
0xEF,0x03,0x06,0x0A,0x01,0x07,
0xDB,0x60,0x3C,0xF0,0xC3,0x0C,0x3C,0x70,
// '�'
0xF0,0x03,0x06,0x0A,0x01,0x07,
0x21,0xF7,0x83,0x7F,0xFC,0xF3,0xF9,0xE0,
// '�'
0xF1,0x03,0x06,0x0A,0x00,0x07,
0x4A,0xC0,0x3E,0xFF,0x3C,0xF3,0xCF,0x30,
// '�'
0xF2,0x03,0x06,0x0A,0x00,0x07,
0x60,0xC0,0x1E,0x7B,0x3C,0xF3,0x79,0xE0,
// '�'
0xF3,0x03,0x06,0x0A,0x00,0x07,
0x18,0xC0,0x1E,0x7B,0x3C,0xF3,0x79,0xE0,
// '�'
0xF4,0x02,0x06,0x0B,0x00,0x07,
0x21,0xC5,0x00,0x79,0xEC,0xF3,0xCD,0xE7,0x80,
// '�'
0xF5,0x03,0x06,0x0A,0x00,0x07,
0x25,0x60,0x1E,0x7B,0x3C,0xF3,0x79,0xE0,
// '�'
0xF6,0x03,0x06,0x0A,0x00,0x07,
0x6D,0xB0,0x1E,0x7B,0x3C,0xF3,0x79,0xE0,
// '�'
0xF7,0x06,0x05,0x07,0x01,0x07,
0x31,0x81,0xF0,0x18,0xC0,
// '�'
0xF8,0x05,0x07,0x09,0x00,0x07,
0x00,0x7D,0xF6,0x7D,0x7C,0xDF,0x3E,0x00,
// '�'
0xF9,0x03,0x06,0x0A,0x00,0x07,
0x60,0xC0,0x33,0xCF,0x3C,0xF3,0xFD,0xF0,
// '�'
0xFA,0x03,0x06,0x0A,0x00,0x07,
0x18,0xC0,0x33,0xCF,0x3C,0xF3,0xFD,0xF0,
// '�'
0xFB,0x02,0x06,0x0B,0x00,0x07,
0x10,0xE2,0x80,0xCF,0x3C,0xF3,0xCF,0xF7,0xC0,
// '�'
0xFC,0x03,0x06,0x0A,0x00,0x07,
0x6D,0xB0,0x33,0xCF,0x3C,0xF3,0xFD,0xF0,
// '�'
0xFD,0x03,0x07,0x0C,0x00,0x07,
0x18,0x60,0x03,0x36,0x66,0x8F,0x1E,0x18,0x30,0x47,0x00,
// '�'
0xFE,0x03,0x06,0x0C,0x00,0x07,
0xC3,0x0C,0x3E,0xFB,0x3C,0xF3,0xFF,0xEC,0x30,
// '�'
0xFF,0x03,0x07,0x0C,0x00,0x07,
0x6C,0xD8,0x03,0x36,0x66,0x8F,0x1E,0x18,0x30,0x47,0x00,

// Terminator
0xFF
};
