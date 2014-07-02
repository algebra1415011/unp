/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  sigchldwaitpid.c
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
 * @brief Figure 5.11 Final(correct) version of sig_chld function that calls waitpid.
 * @see sigchldwait.c
 */
#include "unp.h"

void sig_chld2(int signo)
{
  pid_t pid;
  int stat;
  while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
    printf("child %d terminated\n", pid);
  return;
}



