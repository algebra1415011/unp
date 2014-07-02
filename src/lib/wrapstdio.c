/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  wrapstdio.c
 *
 *         Editor:  vim :set et ts=2 sts=2 sw=2
 *
 *         Author:  Martin Y. Yang , yang@libpix.org
 *
 *    Description:  
 *
 * =============================================================
 */

/**
 * @file
 * @brief wrap of stdio
 */

#include "unp.h"

void Fclose(FILE *fp)
{
  if (fclose(fp) != 0)
    err_sys("fclose error");
}

FILE * Fdopen(int fd, const char *type)
{
  FILE *fp;
  
  if ((fp = fdopen(fd, type)) == NULL)
    err_sys("fdopen error");

  return fp;
}

char * Fgets(char *ptr, int n, FILE *stream)
{
  char *rptr;

  if ((rptr = fgets(ptr, n, stream)) == NULL && ferror(stream))
    err_sys("fgets error");
  return rptr;
}

FILE * Fopen(const char *filename, const char *mode)
{
  FILE *fp;

  if ((fp = fopen(filename, mode)) == NULL)
    err_sys("fopen error");

  return fp;
}

void Fputs(const char *ptr, FILE *stream)
{
  if (fputs(ptr, stream) == EOF)
    err_sys("fputs error");
}
