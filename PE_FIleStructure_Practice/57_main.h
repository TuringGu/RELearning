#pragma once
#include <stdio.h>
#include <Windows.h>

// Return the offset: RAW(File Offset)
// dwRva: a virtual address of data directory table
// buffer: the buffer read from PE file
DWORD RvaToFileOffset(DWORD dwRva, char* buffer);

// Analyze import table
void ImportTables(char* buffer);

// Analyze export table
void ExportTables(char* buffer);

// Analyze relocation table
void RelocationTables(char* buffer);