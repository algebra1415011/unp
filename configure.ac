#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([unp], [0.1], [yang@libpix.org])
AC_CONFIG_SRCDIR([src/unp.h])
AC_CONFIG_HEADERS([src/config.h])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_FILES([Makefile])

# Detect host cpu and os info, used by figure 3.10
AC_CANONICAL_HOST
AC_DEFINE_UNQUOTED(CPU_VENDOR_OS, "$host", [CPU, vendor, and operating system])

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h netdb.h stdlib.h string.h strings.h sys/time.h unistd.h])
AC_CHECK_HEADERS([sys/select.h sys/sysctl.h poll.h sys/event.h sys/ioctl.h sys/fileio.h sys/sockio.h pthread.h])
AC_CHECK_HEADERS([sys/socket.h net/if_dl.h netinet/sctp.h netinet/in.h arpa/inet.h])
# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT64_T


# Checks for library functions.
AC_CHECK_FUNCS(bzero)
AC_CHECK_FUNCS(getaddrinfo)
AC_CHECK_FUNCS(gethostname)
AC_CHECK_FUNCS(gethostbyname2)
AC_CHECK_FUNCS(gethostbyname_r)
AC_CHECK_FUNCS(getnameinfo)
AC_CHECK_FUNCS(hstrerror)
AC_CHECK_FUNCS(if_nametoindex)
AC_CHECK_FUNCS(inet_aton)
AC_CHECK_FUNCS(inet_pton)
AC_CHECK_FUNCS(inet6_rth_init)
AC_CHECK_FUNCS(kqueue kevent)
AC_CHECK_FUNCS(mkstemp)
AC_CHECK_FUNCS(poll)
AC_CHECK_FUNCS(pselect)
AC_CHECK_FUNCS(snprintf)
AC_CHECK_FUNCS(sockatmark)
AC_CHECK_FUNCS(vsnprintf)

AC_OUTPUT
