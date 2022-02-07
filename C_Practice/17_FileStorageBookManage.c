#include "17_FileStorageBookManage.h"

int main()
{
	char * szReadTextBuffer;
	int nReadFileSize, nReadRetSize;
	char databaseFile[] = "D:\\Develop\\C\\workspace\\database.txt";
	char tempFile[] = "D:\\Develop\\C\\workspace\\tmp.txt";

	char szBookName[MaxBookNameLength];
	char szNewBookName[MaxBookNameLength];
	float fBookPrice;
	float fNewBookPrice;
	int nBookNumber;
	int Readflag = 0;	// User choice

	// Initial
	AppendBook(databaseFile, "1", 1, 1.0);
	AppendBook(databaseFile, "2", 2, 2.0);
	AppendBook(databaseFile, "3", 3, 3.0);
	AppendBook(databaseFile, "4", 4, 4.0);

	while (1)
	{
		printf("Enter your choice: \n");
		printf("0.Exit\n1.Append\n2.Query\n3.Modify\n4.delete\n");
		scanf("%d", &Readflag);
		switch (Readflag)
		{
		case flagExit:
			printf("Bye!\n");
			return 0;
			break;
		case flagAppend:
			printf("Enter book name: ");
			scanf("%s", szBookName);
			printf("Enter book price: ");
			scanf("%f", &fBookPrice);
			printf("Enter book number: ");
			scanf("%d", &nBookNumber);
			AppendBook(databaseFile, szBookName, nBookNumber, fBookPrice);
			break;
		case flagQuery:
			printf("Enter book name: ");
			scanf("%s", szBookName);
			QueryBook(databaseFile, szBookName);
			break;
		case flagModify:
			printf("Enter book name: ");
			scanf("%s", szBookName);
			printf("Enter book new name: ");
			scanf("%s", szNewBookName);
			printf("Enter book new number: ");
			scanf("%d", &nBookNumber);
			printf("Enter the price: ");
			scanf("%f", &fNewBookPrice);
			ModifyNode(databaseFile, tempFile, szBookName, szNewBookName, nBookNumber, fNewBookPrice);
			break;
		case flagDelete:
			printf("Enter book name: ");
			scanf("%s", szBookName);
			DeleteNode(databaseFile, tempFile, szBookName);
			break;
		default:
			printf("Invalid Input\n");
			break;
		}	
	}

	return 0;
}

// Append
void AppendBook(char *DatabaseFile, char *BookName, int BookNumber, float BookPrice)
{
	FILE * pFile;
	pFile = fopen(DatabaseFile, "at");
	char szWriteBuffer[MaxInputBufferLength] = { 0 };
	sprintf(szWriteBuffer, "%d\t%s\t%f\n", BookNumber, BookName, BookPrice);

	if (pFile == NULL)
	{
		printf("Write file failed!\n");
		exit(0);
	}
	
	printf("Write String: %s", szWriteBuffer);
	fwrite(szWriteBuffer, strlen(szWriteBuffer), 1, pFile);
	fclose(pFile);
}

// Query
void QueryBook(char *DatabaseFile, char * BookName)
{
	int nBookNumber;
	char szBookName[MaxBookNameLength];
	float fBookPrice;

	FILE * pFile;
	int nReadStringSize;
	char szReadTextBuffer[MaxOutputBufferLength];

	if ((pFile = fopen(DatabaseFile, "r")) == NULL)
	{
		printf("Open file failed!\n");
		exit(0);
	}

	while (!feof(pFile))
	{
		// Initialization buffer
		strcpy(szReadTextBuffer, "");

		// Read line from file
		fgets(szReadTextBuffer, MaxOutputBufferLength, pFile);
		nReadStringSize = strlen(szReadTextBuffer);

		if (nReadStringSize != 0)
		{
			nBookNumber = atoi(strtok(szReadTextBuffer, "\t"));
			strcpy(szBookName, strtok(NULL, "\t"));
			fBookPrice = atof(strtok(NULL, "\t"));

			// Only find one 
			if (strcmp(szBookName, BookName) == 0)
			{
				printf("Found the book\n");
				printf("%d\t%s\t%f\n", nBookNumber, szBookName, fBookPrice);
				fclose(pFile);
				return;
			}
		}
	}

	printf("404 not found!\n");
	fclose(pFile);
}

// Modify
void ModifyNode(char* DatabaseFile, char* TempFile, char* BookName, char* nBookName, int nBookNumber, float nBookPrice)
{
	int foundFlag = FALSE;
	int BookNumber;
	char szBookName[MaxBookNameLength];
	float fBookPrice;

	FILE* pFile;
	FILE* tFile;
	char szReadTextBuffer[MaxOutputBufferLength] = { 0 };
	char szWriteBuffer[MaxInputBufferLength] = { 0 };
	int nReadStringSize;

	if ((pFile = fopen(DatabaseFile, "r")) == NULL)
	{
		printf("Open file failed!\n");
		exit(0);
	}

	if ((tFile = fopen(TempFile, "a")) == NULL)
	{
		printf("Open temp file failed!\n");
		exit(0);
	}

	while (!feof(pFile))
	{
		// Initialization buffer
		strcpy(szReadTextBuffer, "");
		strcpy(szWriteBuffer, "");

		// Read line from file
		fgets(szReadTextBuffer, MaxOutputBufferLength, pFile);	// ReadLine
		nReadStringSize = strlen(szReadTextBuffer);

		// Read string exists
		if (nReadStringSize != 0)
		{
			strcpy(szWriteBuffer, szReadTextBuffer);
			// Data transform
			BookNumber = atoi(strtok(szReadTextBuffer, "\t"));
			strcpy(szBookName, strtok(NULL, "\t"));
			fBookPrice = atof(strtok(NULL, "\t"));

			// Find all the same name books 
			if (strcmp(szBookName, BookName) == 0)
			{
				foundFlag = TRUE;
				printf("Found the book\n");
				printf("%d\t%s\t%f\n", BookNumber, szBookName, fBookPrice);

				sprintf(szWriteBuffer, "%d\t%s\t%f\n", nBookNumber, nBookName, nBookPrice);

				if (tFile == NULL)
				{
					printf("Write file failed!\n");
					fclose(tFile);
					return;
				}

				// Write modified line to the temp file
				printf("Write to temp file: %s\n", szWriteBuffer);
				fwrite(szWriteBuffer, strlen(szWriteBuffer), 1, tFile);
				continue;
			}
			else
			{
				// Write to temp file
				printf("Write to temp file: %s", szWriteBuffer);
				fwrite(szWriteBuffer, strlen(szWriteBuffer), 1, tFile);
			}
		}
	}

	if (foundFlag == FALSE)
	{
		printf("404 not found!\n");
	}
	
	fclose(pFile);
	fclose(tFile);
	remove(DatabaseFile);
	rename(TempFile, DatabaseFile);
}

// Delete
void DeleteNode(char* DatabaseFile, char* TempFile, char* BookName)
{
	int foundFlag = FALSE;
	int BookNumber;
	char szBookName[MaxBookNameLength];
	float fBookPrice;

	FILE* pFile;
	FILE* tFile;
	char szReadTextBuffer[MaxOutputBufferLength] = { 0 };
	char szWriteBuffer[MaxInputBufferLength] = { 0 };
	int nReadStringSize;

	if ((pFile = fopen(DatabaseFile, "r")) == NULL)
	{
		printf("Open file failed!\n");
		exit(0);
	}

	if ((tFile = fopen(TempFile, "a")) == NULL)
	{
		printf("Open temp file failed!\n");
		exit(0);
	}

	while (!feof(pFile))
	{
		// Initialization buffer
		strcpy(szReadTextBuffer, "");
		strcpy(szWriteBuffer, "");

		// Read line from file
		fgets(szReadTextBuffer, MaxOutputBufferLength, pFile);	// ReadLine
		nReadStringSize = strlen(szReadTextBuffer);

		// Read string exists
		if (nReadStringSize != 0)
		{
			strcpy(szWriteBuffer, szReadTextBuffer);
			// Data transform
			BookNumber = atoi(strtok(szReadTextBuffer, "\t"));
			strcpy(szBookName, strtok(NULL, "\t"));
			fBookPrice = atof(strtok(NULL, "\t"));

			// Find all the same name books 
			if (strcmp(szBookName, BookName) == 0)
			{
				foundFlag = TRUE;
				printf("Found the book\n");
				printf("%d\t%s\t%f\n", BookNumber, szBookName, fBookPrice);

				if (tFile == NULL)
				{
					printf("Write file failed!\n");
					fclose(tFile);
					return;
				}

				// Don not Write specify line to the temp file
				continue;
			}
			else
			{
				// Write to temp file
				printf("Write to temp file: %s", szWriteBuffer);
				fwrite(szWriteBuffer, strlen(szWriteBuffer), 1, tFile);
			}
		}
	}

	if (foundFlag == FALSE)
	{
		printf("404 not found!\n");
	}

	fclose(pFile);
	fclose(tFile);
	remove(DatabaseFile);
	rename(TempFile, DatabaseFile);
}

