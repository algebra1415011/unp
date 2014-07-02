/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  wraplib.c
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
 * @brief wrap inet_ntop and inet_pton
 */
#include "unp.h"
/*
 * @brief wrap for inet_ntop
 */

const char * Inet_ntop(int family, const void *addrptr, char *strptr, size_t len)
{
  const char *ptr;

  if (strptr == NULL)                           /* check for old code*/
    err_quit("NULL 3rd argument to inet_ntop");
  if ( (ptr = inet_ntop(family, addrptr, strptr, len)) == NULL)
    err_sys("inet_ntop error");                 /* sets errno */
  return ptr;
}
/*
 * @brief wrap for inet_pton
 */

void Inet_pton(int family, const char *strptr, void *addrptr)
{
  int n;

  if ((n = inet_pton(family, strptr, addrptr)) < 0)
    err_sys("inet_pton error for %s", strptr);  /* errno set */
  else if (n == 0)
    err_quit("inet_pton error for %s", strptr); /* errno not set */
  /* nothing to return */
}


