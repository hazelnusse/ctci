{ctci}
======
This repository contains C++ implementations of the exercises in `Cracking the
coding interview, 6th edition <https://www.crackingthecodinginterview.com>`_.
It serves primarily as a place to exercise modern C++, modern CMake, and modern
C++ tooling.

Building the code
~~~~~~~~~~~~~~~~~
To build from git sources::

    $ git clone https://github.com/hazelnusse/ctci.git
    $ cd ctci
    $ mkdir build
    $ cd build
    $ cmake ..
    $ cmake --build .


Running the tests
~~~~~~~~~~~~~~~~~
Tests are enabled by default and can be run with CTest (from the build
directory)::

    $ ctest
