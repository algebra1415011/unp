/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  byteorder.c
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
 * @brief Figure 3.10 Program to determine host byte order
 *
 * @note You need make sure the following lines appear in you configure.ac
 *    @code
 *     AC_CANONICAL_HOST
 *     AC_DEFINE_UNQUOTED(CPU_VENDOR_OS, "$host", [CPU, vendor, and operating system])
 *    @endcode
 *    These code are used for generating CPU_VENDOR_OS MACRO.\n
 *    If you can't find, add them to configure.ac, then run
 *    @code
 *    autoreconf --install
 *    ./configure
 *    @endcode
 *
 *
 */

#include "unp.h"

int byteorder_main(int argc, char *argv[])
{
  union {
    short s;
    char c[sizeof(short)];
  } un;
  un.s = 0x0102;
  printf("%s: ", CPU_VENDOR_OS);
  if (sizeof(short) == 2) {
    if (un.c[0] == 1 && un.c[1] == 2)
      printf("big-endian\n");
    if (un.c[0] == 2 && un.c[1] == 1)
      printf("little-endian\n");
    else
      printf("unknown\n");
  } else
    printf("sizeof(short) = %d\n", sizeof(short) );
  exit(0);

}
