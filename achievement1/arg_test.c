#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

//The goal of this first part is to find the argument we need for the game, which is the file containing words.
void parse_opt(int argc, char* argv[])
{
  if(argc <= 1)
    {
      printf( "at least one argument is required\n" );
      exit(EXIT_SUCCESS);
    }
  int opt;
  while ((opt = getopt(argc, argv, "s:")) != -1)
    {
      switch (opt)
	{
	case 's':
	  break;
	default: /* '?' */
	  fprintf(stderr, "Usage: %s [-s nsecs] name\n",
		  argv[0]);
	  exit(EXIT_FAILURE);
	}
    }

  if (optind >= argc)
    {
      fprintf(stderr, "Expected argument after options\n");
      exit(EXIT_SUCCESS);
    }
}

void test_file(FILE* file)
{
  if( file == NULL )
    {
      printf("Please enter an existing file\n");
      exit(EXIT_SUCCESS);
    }
  fseek(file,0,SEEK_END);
  if(ftell(file) == 0)
    {
      printf("Please enter a non empty file\n");
      exit(EXIT_SUCCESS);
    }
  fseek(file,0,SEEK_SET);
}
