#pragma once
#include <stdio.h>
#include <Windows.h>
#include <wchar.h>

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

// Analyze Thread Local Storage Table
void TLSTable(char* buffer);

// Analyze Delay Load Table (Load faster)
void DelayLoadTable(char* buffer);

// Analyze Resource Table
void ResourceTable(char* buffer);

// Analyze Other Table
void DataTable(char* buffer);