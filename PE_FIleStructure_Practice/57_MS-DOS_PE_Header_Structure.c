#include "57_main.h"


int main()
{
	// Initial
	FILE* pFile = NULL;
	char* filePath = "C:\\test.exe";
	char* buffer;
	int nFileLength = 0;
	int imageLength = 0;

	// Get file length
	pFile = fopen(filePath, "rb");
	fseek(pFile, 0, SEEK_END);
	nFileLength = ftell(pFile);
	rewind(pFile);

	// Get image length & malloc memory
	imageLength = nFileLength * sizeof(char) + 1;
	buffer = (char*)malloc(imageLength);
	memset(buffer, 0, imageLength);
	fread(buffer, 1, imageLength, pFile);

	//// Read MS-Dos header
	//PIMAGE_DOS_HEADER ReadDosHeader;
	//ReadDosHeader = (PIMAGE_DOS_HEADER)buffer;
	//printf("MS-DOS Info:\n");
	//printf("MZ Flag: %x\n", ReadDosHeader->e_magic);
	//printf("PE Header Offset: %x\n", ReadDosHeader->e_lfanew);


	//// Read PE header(calculate read buffer offset), 32-bit
	//PIMAGE_NT_HEADERS ReadNTHeaders;
	//ReadNTHeaders = (PIMAGE_NT_HEADERS)(buffer + ReadDosHeader->e_lfanew);
	//printf("PE Header Info:\n");
	//printf("PE Flag: %x\n", ReadNTHeaders->Signature);
	//printf("Running Plateform: %x\n", ReadNTHeaders->FileHeader.Machine);
	//printf("ImageBase: %x\n", ReadNTHeaders->OptionalHeader.ImageBase);


	//// Section analysis & traversal
	//PIMAGE_SECTION_HEADER ReadSectionHeader = IMAGE_FIRST_SECTION(ReadNTHeaders);
	//PIMAGE_FILE_HEADER pFileHeader = &ReadNTHeaders->FileHeader;

	//printf("Section Header Info:\n");
	//for (int i = 0; i < pFileHeader->NumberOfSections; i++)
	//{
	//	// VOffset + VSize = next section VOffset
	//	// ROffset + RSize = next section ROffset
	//	printf("Section Name: %s\n", ReadSectionHeader[i].Name);
	//	printf("VOffset(Virtual Address): %08x\n", ReadSectionHeader[i].VirtualAddress);
	//	printf("VSize(Section Size): %08x\n", ReadSectionHeader[i].Misc.VirtualSize);
	//	printf("ROffset(File Offset): %08x\n", ReadSectionHeader[i].PointerToRawData);
	//	printf("RSize(Section Size In File): %08x\n", ReadSectionHeader[i].SizeOfRawData);
	//	printf("Flag(Section Attribute): %08x\n", ReadSectionHeader[i].Characteristics);
	//	printf("\n\n");
	//}


	// Import Tables
	//printf("Import Tables======================\n");
	//ImportTables(buffer);

	// Export Tables
	//printf("Export Tables======================\n");
	//ExportTables(buffer);

	// Relocation Tables
	printf("Relocation Tables======================\n");
	RelocationTables(buffer);

	// Free Memory
	free(buffer);
	return 0;
}


DWORD RvaToFileOffset(DWORD dwRva, char* buffer)
{
	// MS-DOS Header
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)buffer;
	// PE Header
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(pDosHeader->e_lfanew + buffer);
	// Section Tables
	PIMAGE_SECTION_HEADER pSectionHeader = IMAGE_FIRST_SECTION(pNtHeader);

	// Judge weather fall into header
	if (dwRva < pSectionHeader[0].VirtualAddress)
	{
		return dwRva;
	}

	for (int i = 0; i < pNtHeader->FileHeader.NumberOfSections; i++)
	{
		// If fall into a section
		if (dwRva >= pSectionHeader[i].VirtualAddress && 
			dwRva < pSectionHeader[i].VirtualAddress + pSectionHeader[i].Misc.VirtualSize)
		{
			// Return the offset: from the start of data directory table to the fall into sections' start of file header
			// (dwRva - pSectionHeader[i].VirtualAddress): 
			// Offset from the start of data directory table to the start of the fall into section
			return dwRva - pSectionHeader[i].VirtualAddress + pSectionHeader[i].PointerToRawData;
		}
	}
}

void ImportTables(char* buffer)
{
	// MS-DOS Header
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)buffer;
	// PE Header
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(pDosHeader->e_lfanew + buffer);
	// Locate Import Directory
	PIMAGE_DATA_DIRECTORY pImportDir = (PIMAGE_DATA_DIRECTORY)(pNtHeader->OptionalHeader.DataDirectory + IMAGE_DIRECTORY_ENTRY_IMPORT);
	// Filling Structure
	PIMAGE_IMPORT_DESCRIPTOR pImportDescriptor =
		(PIMAGE_IMPORT_DESCRIPTOR)(RvaToFileOffset(pImportDir->VirtualAddress, buffer) + buffer);

	while (pImportDescriptor->Name != NULL)
	{
		char* szDllName = (char*)(RvaToFileOffset(pImportDescriptor->Name, buffer) + buffer);
		printf("\n==================================================\n");
		printf("DLLName: %s\n", szDllName);
		printf("TimeDateStamp: %08X\n", pImportDescriptor->TimeDateStamp);
		printf("ForwarderChain: %08X\n", pImportDescriptor->ForwarderChain);
		printf("Name(Offset): %08X\n", pImportDescriptor->Name);
		printf("FirstThunk: %08X\n", pImportDescriptor->FirstThunk);
		printf("OriginalFirstThunk: %08X\n", pImportDescriptor->OriginalFirstThunk);
		printf("\n\n");

		// Point to the RVA of import address table
		PIMAGE_THUNK_DATA pThunkData = 
			(PIMAGE_THUNK_DATA)(RvaToFileOffset(pImportDescriptor->OriginalFirstThunk, buffer) + buffer);
		DWORD index = 0;
		DWORD ImportOffset = 0;

		// The number of imported function
		while (pThunkData->u1.Ordinal != 0)
		{
			printf("ThunkRVA: %08X\n", pImportDescriptor->OriginalFirstThunk + index);
			ImportOffset = RvaToFileOffset(pImportDescriptor->OriginalFirstThunk, buffer);
			printf("ThunkOffset: %08X\n", ImportOffset + index);
			index += 4;
			if ((pThunkData->u1.Ordinal & IMAGE_ORDINAL_FLAG32) != 1)
			{
				PIMAGE_IMPORT_BY_NAME pIByName = (PIMAGE_IMPORT_BY_NAME)(RvaToFileOffset(pThunkData->u1.AddressOfData, buffer) + buffer);
				printf("API Name: %s\n", pIByName->Name);
				printf("Hint: %08x\n", pIByName->Hint);
				printf("ThunkValue: %08x\n", pThunkData->u1.Function);
				printf("\n\n");
			}
			pThunkData++;
		}
		pImportDescriptor++;
	}

}

void ExportTables(char* buffer)
{
	// MS-DOS Header
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)buffer;
	// PE Header
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(pDosHeader->e_lfanew + buffer);
	// Locate Export Directory
	PIMAGE_DATA_DIRECTORY pExportDir = pNtHeader->OptionalHeader.DataDirectory + IMAGE_DIRECTORY_ENTRY_EXPORT;
	// Fill Export Dirctory Structure
	PIMAGE_EXPORT_DIRECTORY pExport = (PIMAGE_EXPORT_DIRECTORY)(RvaToFileOffset(pExportDir->VirtualAddress, buffer) + buffer);
	char* szName = (char*)(RvaToFileOffset(pExport->Name, buffer) + buffer);

	if (pExport->AddressOfFunctions == 0)
	{
		printf("No export tables!\n");
		return;
	}

	printf("Export tables offset: %08X\n", RvaToFileOffset(pExportDir->VirtualAddress, buffer));
	printf("Characteristics: %08X\n", pExport->Characteristics);
	printf("Base: %08X\n", pExport->Base);
	printf("Name offset: %08X\n", pExport->Name);
	printf("Name: %s\n", szName);
	printf("NumberOfFunctions: %08X\n", pExport->NumberOfFunctions);
	printf("NumberOfNames: %08X\n", pExport->NumberOfNames);
	printf("AddressOfFunctions: %08X\n", pExport->AddressOfFunctions);
	printf("AddressOfNames: %08X\n", pExport->AddressOfNames);
	printf("AddressOfNameOrdinals: %08X\n", pExport->AddressOfNameOrdinals);

	// Functions Number
	DWORD dwNumOfFunc = pExport->NumberOfFunctions;
	// Function names number
	DWORD dwNumOfFuncName = pExport->NumberOfNames;
	// Base
	DWORD dwBase = pExport->Base;
	// Export address table
	PDWORD pEat32 = (PDWORD)(RvaToFileOffset(pExport->AddressOfFunctions, buffer) + buffer);
	// Export name table
	PDWORD pEnt32 = (PDWORD)(RvaToFileOffset(pExport->AddressOfNames, buffer) + buffer);
	// Export ordinal table
	PWORD pEot32 = (PWORD)(RvaToFileOffset(pExport->AddressOfNameOrdinals, buffer) + buffer);

	for (DWORD i = 0; i < dwNumOfFunc; i++)
	{
		if (pEat32[i] == 0)
		{
			continue;
		}
		DWORD Id = 0;
		for (; Id < dwNumOfFuncName; Id++)
		{
			if (pEot32[Id] == i)
			{
				break;
			}
		}
		if (Id == dwNumOfFuncName)
		{
			printf("Id: %x  Address: 0x%08X Name[NULL]\n", i + dwBase, pEat32[i]);
		}
		else
		{
			char* szFuncName = (char*)(RvaToFileOffset(pEnt32[Id], buffer) + buffer);
			printf("Id: %x  Address: 0x%08X Name[%s]\n", i + dwBase, pEat32[i], szFuncName);
		}
	}
}

void RelocationTables(char* buffer)
{
	// Bit Filed
	typedef struct _TYPE {
		WORD Offset : 12;	// 12bit, max(4096/1000h)
		WORD Type : 4;		// 4bit, max(16/10h)
	}TYPE,*PTYPE;

	// MS-DOS Header
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)buffer;
	// PE Header
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(pDosHeader->e_lfanew + buffer);
	// Locate Section
	PIMAGE_SECTION_HEADER pSection = IMAGE_FIRST_SECTION(pNtHeader);
	// Locate Relocation Directory
	PIMAGE_DATA_DIRECTORY pRelocDir = (pNtHeader->OptionalHeader.DataDirectory + IMAGE_DIRECTORY_ENTRY_BASERELOC);
	// Filling relocation directory structure
	PIMAGE_BASE_RELOCATION pReloc = (PIMAGE_BASE_RELOCATION)(RvaToFileOffset(pRelocDir->VirtualAddress, buffer) + buffer);
	
	while (pReloc->SizeOfBlock != 0)
	{
		// Find the start location of 0x1000 byte
		DWORD dwCount = (pReloc->SizeOfBlock - 8) / 2;
		DWORD dwRVA = pReloc->VirtualAddress;
		PTYPE pRelocArr = (PTYPE)(pReloc + 1);
		printf("======================================\n");
		printf("Section: %s\n", pSection->Name);
		printf("RVA: %08X\n", dwRVA);
		printf("Items: %Xh / %dd\n", pReloc->SizeOfBlock, pReloc->SizeOfBlock);

		// Find the start location of the next 0x1000 byte
		pReloc = (PIMAGE_BASE_RELOCATION)((char*)pReloc + pReloc->SizeOfBlock);

		for (int i = 0; i < dwCount; i++)
		{
			PDWORD pData = (PDWORD)(RvaToFileOffset(pRelocArr[i].Offset + dwRVA, buffer) + buffer);
			DWORD pDataOffset = RvaToFileOffset(pRelocArr[i].Offset + dwRVA, buffer);
			printf("RVA: %08X\n", pRelocArr[i].Offset + dwRVA);
			printf("Section: %08X\n", *pData);
			printf("Offset: %08X\n", pDataOffset);
			printf("\n");
		}
	}

}



// VA: Virtual Address (00000000h - 0fffffffh)  = base address + RVA
// RVA: Relative Virtual Address
// FOA: File Offset Address