Users of Unix platforms should read "Unix Note" at the end of this
file before continuing.

To run this demo, open two terminal windows. In the first window,
start the IceBox server:

      icebox --Ice.Config=config.icebox

Please note that depending on your platform and C++ environment
you will need to use different icebox executables. The names are
as follows:

       "iceboxd" for a Windows debug build.
       "icebox++11" for a Linux C++11 build.
       "icebox32" for a Linux 32-bit build.
       "icebox32++11" for a Linux 32-bit C++11 build.

You can find more details in our online documentation.

https://doc.zeroc.com/display/Ice36/Starting+the+IceBox+Server

In the second window, run the client:

      client

To shut down IceBox, use iceboxadmin:

      iceboxadmin --Ice.Config=config.admin shutdown
