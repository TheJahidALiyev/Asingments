#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * fgets ( char * str, int num, FILE * stream);
size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );

int main()
{
  FILE * pFile;
  char mystring [100];
  long lSize;
  char * buffer;
  size_t result;
  pFile = fopen ( "cahid_lab.txt" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  printf("outfile is:\n");
  printf("%s", buffer);
  // terminate
  fclose (pFile);
  free (buffer);
  return 0;
}
