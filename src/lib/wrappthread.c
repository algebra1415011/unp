/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  wrappthread.c
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
 * @brief Figure 1.8 Our wrapper function for pthread_mutex_lock
 */
#include "unp.h"

void Pthread_mutex_lock(pthread_mutex_t *mptr)
{
  int n;
  if ( (n = pthread_mutex_lock(mptr)) == 0)
    return;
  errno = n;
  err_sys("pthread_mutex_lock error");
}

