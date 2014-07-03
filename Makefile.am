CPPFLAGS = -I $(top_builddir) -I $(top_srcdir)/src
lib_LIBRARIES = libunp.a
libunp_a_SOURCES = \
	$(top_builddir)/config.h \
	$(top_srcdir)/src/unp.h \
	$(top_srcdir)/src/lib.c \
	$(top_srcdir)/src/lib/error.c \
	$(top_srcdir)/src/lib/wrapsock.c \
	$(top_srcdir)/src/lib/sock_ntop.c \
	$(top_srcdir)/src/lib/wrapunix.c \
	$(top_srcdir)/src/lib/wraplib.c \
	$(top_srcdir)/src/lib/wrapstdio.c \
	$(top_srcdir)/src/lib/readline.c \
	$(top_srcdir)/src/lib/readn.c \
	$(top_srcdir)/src/lib/writen.c \
	$(top_srcdir)/src/lib/signal.c \
	$(top_srcdir)/src/lib/sockfd_to_family.c \
	$(top_srcdir)/src/lib/wrappthread.c \
	$(top_srcdir)/src/tcpcliserv/sigchldwaitpid.c \
	$(top_srcdir)/src/tcpcliserv/sigchldwait.c \
	\
	$(top_srcdir)/src/libfree/inet_pton_ipv4.c \
	$(top_srcdir)/src/libfree/inet_ntop_ipv4.c \
	\
	$(top_srcdir)/src/lib/str_echo.c \
	$(top_srcdir)/src/tcpcliserv/str_echo08.c \
	$(top_srcdir)/src/tcpcliserv/str_echo09.c \
	\
	$(top_srcdir)/src/lib/str_cli.c \
	$(top_srcdir)/src/tcpcliserv/str_cli11.c \
	$(top_srcdir)/src/tcpcliserv/str_cli09.c \
	$(top_srcdir)/src/select/strcliselect01.c \
	$(top_srcdir)/src/select/strcliselect02.c  \
	\
	$(top_srcdir)/src/test/readline1.c \
	$(top_srcdir)/src/lib/readline.c \
	\
	$(top_srcdir)/src/lib/dg_echo.c \
	$(top_srcdir)/src/udpcliserv/dgecholoop1.c \
	$(top_srcdir)/src/udpcliserv/dgecholoop2.c \
	\
	$(top_srcdir)/src/lib/dg_cli.c \
	$(top_srcdir)/src/udpcliserv/dgcliaddr.c \
	$(top_srcdir)/src/udpcliserv/dgcliconnect.c \
	$(top_srcdir)/src/udpcliserv/dgcliloop1.c

bin_PROGRAMS = unp

unp_SOURCES = \
	$(top_builddir)/config.h \
	$(top_srcdir)/src/unp.h \
	$(top_srcdir)/src/main.c \
	$(top_srcdir)/src/intro/daytimetcpcli.c \
	$(top_srcdir)/src/intro/daytimetcpsrv.c \
	$(top_srcdir)/src/intro/byteorder.c \
	$(top_srcdir)/src/intro/daytimetcpsrv1.c \
	$(top_srcdir)/src/tcpcliserv/tcpserv01.c \
	$(top_srcdir)/src/tcpcliserv/tcpcli01.c \
	$(top_srcdir)/src/tcpcliserv/tcpcli04.c \
	$(top_srcdir)/src/tcpcliserv/tcpserv04.c \
	$(top_srcdir)/src/tcpcliserv/tcpservselect01.c \
	$(top_srcdir)/src/tcpcliserv/tcpservpoll01.c \
	$(top_srcdir)/src/sockopt/checkopts.c \
	$(top_srcdir)/src/udpcliserv/udpserv01.c \
	$(top_srcdir)/src/udpcliserv/udpcli01.c \
	$(top_srcdir)/src/udpcliserv/udpcli09.c \
	$(top_srcdir)/src/udpcliserv/udpservselect01.c


unp_LDADD = $(top_builddir)/libunp.a
