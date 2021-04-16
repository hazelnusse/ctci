.. image:: https://github.com/hazelnusse/ctci/workflows/MacOS/badge.svg
  :alt: macOS build status
  :target: https://github.com/hazelnusse/ctci/actions/workflows/macos.yml
.. image:: https://github.com/hazelnusse/ctci/workflows/Style/badge.svg
  :alt: Style build status
  :target: https://github.com/hazelnusse/ctci/actions/workflows/style.yml
.. image:: https://github.com/hazelnusse/ctci/workflows/Windows/badge.svg
  :alt: Windows build status
  :target: https://github.com/hazelnusse/ctci/actions/workflows/windows.yml
.. image:: https://github.com/hazelnusse/ctci/workflows/Ubuntu/badge.svg
  :alt: Ubuntu build status
  :target: https://github.com/hazelnusse/ctci/actions/workflows/ubuntu.yml
.. image:: https://codecov.io/gh/hazelnusse/ctci/branch/main/graph/badge.svg
  :alt: Code coverage
  :target: https://codecov.io/gh/hazelnusse/ctci

{ctci}
======
This repository contains C++ implementations of the exercises in `Cracking the
coding interview, 6th edition <https://www.crackingthecodinginterview.com>`_.
It serves primarily as a place to exercise modern C++, modern CMake, and modern
C++ tooling.

Building the code and run tests
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Do this::

    $ git clone https://github.com/hazelnusse/ctci.git
    $ cd ctci
    $ cmake -S test -B build-test
    $ cmake --build --build-test
    $ ctest --test-dir build-test
