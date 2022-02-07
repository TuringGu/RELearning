#include <stdio.h>
#include <string.h>
//#include <stdlib.h>


// Debug: err,hr
int main()
{
	// File Read
	FILE * pFile; 
	char * szReadTextBuffer;
	int nReadFileSize, nReadRetSize;
	char readFileDir[] = "C:\\BK\\Develop\\C\\temp\\test1.txt";
	char writeFileDir[] = "C:\\BK\\Develop\\C\\temp\\test2.txt";

	pFile = fopen(readFileDir,"rb");    // read, write, binary
	if (pFile == NULL)
	{
		printf("Open file failed!");
		exit(0);
	}

	fseek(pFile, 0, SEEK_END);    // Set file stream(read&write) pointer to the end(SEEK_END) of the file
	nReadFileSize = ftell(pFile);    // Get the offset bytes number of the file current location pointer to the file start
	rewind(pFile);    // Set file stream pointer to the start of the file
	szReadTextBuffer = (char *)malloc((nReadFileSize * sizeof(char)) + 1);
	if (szReadTextBuffer == NULL)
	{
		printf("Malloc memory failed!");
		exit(0);
	}

	memset(szReadTextBuffer, 0, nReadFileSize + 1);
	nReadRetSize = fread(szReadTextBuffer, 1, nReadFileSize, pFile);
	if (nReadRetSize != nReadFileSize)
	{
		printf("Read file failed!");
		exit(0);
	}

	puts(szReadTextBuffer);
	fclose(pFile);



	// File Write
	char * szWriteBuffer = "AAAAAAAAAAAAAA\n\n   BBBB";
	int nWriteSize = 0;
	pFile = fopen(writeFileDir, "wb");
	if (pFile == NULL)
	{
		printf("Write file failed!");
		exit(0);
	}

	fwrite(szWriteBuffer, strlen(szWriteBuffer), 1, pFile);
	fclose(pFile);


	return 0;
}

