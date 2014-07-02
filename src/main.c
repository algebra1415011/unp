/*
 * =============================================================
 *
 *        Project:  unp
 *
 *       Filename:  main.c
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
 * @brief Entry
 */

#include "unp.h"

int daytimetcpcli_main(int argc, char *argv[]); /* Figure 1.5 */
int daytimetcpsrv_main(int argc, char *argv[]); /* Figure 1.9 */
int byteorder_main(int argc, char *argv[]);     /* Figure 3.10 */
int daytimetcpsrv1_main(int argc, char *argv[]);/* Figure 4.11 */
int tcpserv01_main(int argc, char *argv[]);     /* Figure 5.1 */
int tcpcli01_main(int argc, char *argv[]);      /* Figure 5.4 */
int tcpcli04_main(int argc, char *argv[]);      /* Figure 5.9 */
int tcpserv04_main(int argc, char *argv[]);     /* Figure 5.12 */
int tcpservselect01_main(int argc , char *argv[]); /* Figure 6.22 */
int tcpservpoll01_main(int argc, char *argv[]); /* Figure 6.26 */
int checkopts_main(int argc, char *argv[]);     /* Figure 7.4 */
int udpserv01_main(int argc, char *argv[]);     /* Figure 8.3 */
int udpcli01_main(int argc , char *argv[]);     /* Figure 8.7 */
int udpcli09_main(int argc, char *argv[]);      /* Figure 8.23 */
int udpservselect01_main(int argc, char *argv[]); /* Figure 8.25 */

typedef struct {
  const char * figure;
  int (*fn) (int argc , char *argv[]);
  const char * name;
  const char * msg;
} item_t;

item_t map[] =
{
  { "1.5" , daytimetcpcli_main , "daytimetcpcli" , "TCP daytime client" } ,
  { "1.9" , daytimetcpsrv_main , "daytimetcpsrv" , "TCP daytime server" } ,
  { "3.10" , byteorder_main , "byteorder" , "Program to determine host byte order" },
  { "4.11" , daytimetcpsrv1_main , "daytimetcpsrv1" , \
    "Daytime server that prints client IP address and port." },
  { "5.2" , tcpserv01_main , "tcpserv01" , "TCP echo server (improved in Figure 5.12)" },
  { "5.4" , tcpcli01_main , "tcpcli01" , "TCP echo client." },
  { "5.9" , tcpcli04_main , "tcpcli04" , "TCP client that establishes five connections with server."},
  { "5.12", tcpserv04_main , "tcpserv04" , \
    "Final(correct) version of TCP server that handles an error of EINTR from accept." },
  { "6.22", tcpservselect01_main , "tcpservselect01" , \
    "TCP server using a single process and select" },
  { "6.26", tcpservpoll01_main , "tcpservpoll01", \
    "TCP server using poll" },
  { "7.4", checkopts_main , "checkopts", "check the socket options" },
  { "8.3", udpserv01_main , "udpserv01", "UDP echo server" },
  { "8.7", udpcli01_main , "udpcli01", "UDP echo client" },
  { "8.23", udpcli09_main , "udpcli09", "UDP program that uses connect to determine outgoing interface" },
  { "8.25", udpservselect01_main , "udpservselect01", "Echo server that handles TCP and UDP using select" },
  { 0 , 0 , 0 , 0 }
};

typedef struct {
  const char *name;
  const char *figure;
  const char *msg;
} libitem_t;

static libitem_t libmap[] = {
  { "# inet_pton", "3.12", "Simple version of inet_pton that supports only IPv4" },
  { "# inet_ntop", "3.13", "Simple version of inet_ntop that supports only IPv4" },
  { "sock_ntop", "3.14", "Our sock_ntop function" },
  { "readn", "3.15", "Read n bytes from a descriptor" },
  { "writen", "3.16", "Write n bytes to a descriptor" },
  { "# readline", "3.17", "Read a text line from a descriptor, one byte at a time" },
  { "" , "3.18" , "Better version of readline function" },
  { "# str_echo" , "5.3", "echoes data on a socket" },
  { "",            "5.17", "str_echo function that adds two numbers" },
  { "",            "5.20", "str_echo function that adds two binary integers" },


  { "# str_cli", "5.5",  "client processing loop" },
  { "",          "5.14", "str_cli that calls writen twice" },
  { "",          "5.19", "str_cli that sends two binary integers to server" },
  { "",          "6.9",  "str_cli using select" },
  { "",          "6.13", "str_cli using select that handles EOF correctly" },

  { "# signal", "5.6", "signal function that calls the POSIX sigaction function" },
  { "# sig_chld" , "5.7",  " Version of SIGCHLD signal handler that calls wait" },
  { "" ,           "5.11", " Final (correct) version of sig_chld function that calls waitpid" },
  { "# dg_echo", "8.4",  "echo lines on a datagram socket" },
  { "",          "8.20", "dg_echo function that counts received datagrams" },
  { "",          "8.22", "dg_echo function that increases the size of the socket receive queue" },
  { "# dg_cli", "8.8",  "client processing loop" },
  { "",         "8.9",  "dg_cli function that verifies returned socket address" },
  { "",         "8.17", "dg_cli function that calls connect" },
  { "",         "8.19", "dg_cli function that writes a fixed number of datagrams to the server" },
  



  
  { 0 , 0 , 0 }
};

const char *basename(const char *path)
{
  const char *p = strrchr(path , '/');
  if (!p) return path;
  return p + 1;
}
void showapp()
{
  item_t *p = map;
  printf("Programs:\n");
  while (p->figure) {
    printf(" %-15s %-6s %s\n" , p->name, p->figure, p->msg);
    p++;
  }
}

void showlib()
{
  libitem_t *p = libmap;
  printf("Functions:\n");
  while (p->name) {
    printf(" %-15s %-6s %s\n", p->name, p->figure, p->msg);
    p++;
  }
}
int main(int argc, char *argv[])
{
  item_t *p = map;
  const char *cmd = basename(argv[0]);
  char **arg = argv;
  if (strcmp(cmd , "unp") == 0) {
    arg ++;
    argc --;
    cmd = *arg;
  }

  if (argc > 0) {
   if (strcmp(cmd, "-f") == 0) {
      showlib();
      exit(0);
    }
    while (p->figure) {
      if (strcmp(cmd , p->figure) == 0 || strcmp(cmd , p->name) == 0) {
        setenv("figure", p->figure, 1);
        return p->fn(argc , arg);
      }
      p++;
    }
  }
  printf("UNIX Network Programming Vol. 1 3e Demos\n");
  printf("http://www.libpix.org/unp\n\n");
  printf("Usage: $ ./unp                              # to get the list of programs\n");
  printf("       $ ./unp -f                           # to get the list of functions\n");
  printf("       $ ./unp byteorder                    # to run a program in the list\n");
  printf("       $ ln -s unp byteorder; ./byteorder   # to run a program in the list\n");
  printf("       $ str_echo=5.17 ./unp 5.12           # to specify a version of function\n\n");

  showapp();
  
  return 0;
}
