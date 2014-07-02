# UNIX Network Programming Vol 1 
## Notes and Demos

This program is an all-in-one program, convinient for running code snippet in the book.

Visit [http://libpix.org/unp](http://libpix.org/unp) for notes and documents.

Bug report [yang@libpix.org](mailto:yang@libpix.org)

## Usage

In the source code path, run

    $ ./configure
    $ make

Now, you should get the binary executable, run

    $ ./unp

to get the list of programs.

    Programs:
     daytimetcpcli   1.5    TCP daytime client
     daytimetcpsrv   1.9    TCP daytime server
     byteorder       3.10   Program to determine host byte order
     daytimetcpsrv1  4.11   Daytime server that prints client IP address and port.
     tcpserv01       5.2    TCP echo server (improved in Figure 5.12)
     ...

To run a program you want, for example, byteorder, you can type

    ./unp byteorder

or you can use the figure number
    
    ./unp 3.10

The most convinient way is to use symbolic link

    $ ln -s unp byteorder

and run
 
    $ ./byteorder

Some library functions have multi-versions, run

    $ ./apue -f

to get the list of library functions.

     ...
     # str_echo      5.3    echoes data on a socket
                     5.17   str_echo function that adds two numbers
                     5.20   str_echo function that adds two binary integers
     # str_cli       5.5    client processing loop
                     5.14   str_cli that calls writen twice
                     5.19   str_cli that sends two binary integers to server
                     6.9    str_cli using select
                     6.13   str_cli using select that handles EOF correct
     ...

Functions start with '#' are multi-version functions.
Use environment variable to specify the function.
For example, to run a server add two integers:

    $ str_echo=5.17 ./unp 5.12 

and on another terminal, run

    $ ./unp 5.4 127.0.0.1
    2 3
    5
    123 456
    579

## License

The MIT License (MIT)

Copyright (c) 2014 Martin Y. Yang

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


