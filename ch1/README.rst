{Chapter 1}
===========

Exercise 1.1: Is Unique
~~~~~~~~~~~~~~~~~~~~~~~
Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?

I implemented three functions taking a `std::string_view` and returning a
boolean indicating whether the string has all unique characters or not. The
three functions represent the following three approaches:

Using a bit-field
  Allocate an array of bytes with sufficient bits for each unique character in
  the string (32 bytes in the case of 8-bit characters).  Iterate over the
  string and check if the bit associated with the current character is set,
  return false if so, otherwise set the bit; if the end of the string is
  reached, return true.

Brute force
  Iterate over ever character of the string, comparing it to each preceding
  character and returning false as soon as two characters compare equal, or
  true otherwise.

Using sort
  Make a copy of the string_view, sort it in place, then iterate over the
  sorted string and returning false if two adjacent characters are equal, or
  true otherwise.

All three approaches benefit from some early return optimizations based on the
fact that a string with 0 or 1 characters is always unique, and a string with
more characters than there are characters in the character set is necessarily
not unique. Performance characteristics for strings in between these two sizes
are measurable.

Stack usage of the three different implementations was measured by making use
of the `-fstack-usage` flag when compiling the `is_unique` library, which
yielded the following results::

    bool is_unique::using_bitfield(std::string_view)    64    static
    bool is_unique::brute_force(std::string_view)        8    static
    bool is_unique::using_sort(std::string_view)       128    static

Runtime performance was as follows::

    -----------------------------------------------------------------
    Benchmark                       Time             CPU   Iterations
    -----------------------------------------------------------------
    BM_using_bitfield/1          1.98 ns         1.97 ns    356348250
    BM_using_bitfield/2          3.84 ns         3.84 ns    182436756
    BM_using_bitfield/4          6.02 ns         6.02 ns    112105950
    BM_using_bitfield/8          10.1 ns         10.1 ns     67170907
    BM_using_bitfield/16         18.4 ns         18.3 ns     30099121
    BM_using_bitfield/32         35.3 ns         35.3 ns     19784436
    BM_using_bitfield/64         69.2 ns         69.2 ns      9823179
    BM_using_bitfield/128         147 ns          147 ns      4722967
    BM_using_bitfield/256         286 ns          286 ns      2435102
    BM_using_bitfield_BigO       1.12 N          1.12 N    
    BM_using_bitfield_RMS           3 %             3 %    
    BM_using_bitfield/512        2.27 ns         2.27 ns    305807659
    BM_using_bitfield/1024       2.28 ns         2.28 ns    305279332
    BM_using_bitfield/2048       2.28 ns         2.28 ns    303488748
    BM_using_bitfield/4096       2.29 ns         2.28 ns    304127436
    BM_using_bitfield_BigO       2.28 (1)        2.28 (1)  
    BM_using_bitfield_RMS           0 %             0 %    
    BM_brute_force/1             1.24 ns         1.24 ns    556801452
    BM_brute_force/2             3.14 ns         3.13 ns    220115895
    BM_brute_force/4             7.23 ns         7.23 ns     91030920
    BM_brute_force/8             22.1 ns         22.0 ns     31467124
    BM_brute_force/16            56.5 ns         56.4 ns     11773656
    BM_brute_force/32             227 ns          227 ns      3063777
    BM_brute_force/64             990 ns          989 ns       684790
    BM_brute_force/128           3403 ns         3400 ns       205624
    BM_brute_force/256          11186 ns        11179 ns        60552
    BM_brute_force_BigO          0.17 N^2        0.17 N^2  
    BM_brute_force_RMS             12 %            12 %    
    BM_brute_force/512           1.72 ns         1.72 ns    406128637
    BM_brute_force/1024          1.72 ns         1.72 ns    401964135
    BM_brute_force/2048          1.72 ns         1.72 ns    402553176
    BM_brute_force/4096          1.72 ns         1.72 ns    404444110
    BM_brute_force_BigO          1.72 (1)        1.72 (1)  
    BM_brute_force_RMS              0 %             0 %    
    BM_using_sort/1              2.41 ns         2.41 ns    287303854
    BM_using_sort/2              11.0 ns         11.0 ns     62752373
    BM_using_sort/4              14.0 ns         14.0 ns     49516905
    BM_using_sort/8              16.4 ns         16.4 ns     42282012
    BM_using_sort/16             36.5 ns         36.5 ns     19137843
    BM_using_sort/32             93.6 ns         93.6 ns      7392007
    BM_using_sort/64              198 ns          198 ns      3494852
    BM_using_sort/128             504 ns          504 ns      1342312
    BM_using_sort/256            1089 ns         1088 ns       631442
    BM_using_sort_BigO           0.54 NlgN       0.54 NlgN 
    BM_using_sort_RMS               5 %             5 %    
    BM_using_sort/512            2.22 ns         2.22 ns    311945992
    BM_using_sort/1024           2.22 ns         2.21 ns    312103297
    BM_using_sort/2048           2.21 ns         2.21 ns    312896501
    BM_using_sort/4096           2.22 ns         2.22 ns    312549831
    BM_using_sort_BigO           2.22 (1)        2.22 (1)  
    BM_using_sort_RMS               0 %             0 %    

The take home here is that for strings larger than 256, all algorithms were
effectively identical run-time cost, but for strings with size in [2, 256], the
big O was linear for the bit-field approach, quadratic for the brute force
approach, and N log(N) for the sort approach. Specific applications would need
to assess the relative cost of run-time performance, stack usage, code size,
and compile time dependencies to decide which implementation is most
appropriate.

The code size of each implementation is as follows::

    $ nm -C --size-sort -t d ch1/CMakeFiles/is_unique.dir/*.o | rg is_unique | rg " T "
    0000000000000201 T is_unique::brute_force(std::basic_string_view<char, std::char_traits<char> >)
    0000000000000350 T is_unique::using_bitfield(std::basic_string_view<char, std::char_traits<char> >)
    0000000000000444 T is_unique::using_sort(std::basic_string_view<char, std::char_traits<char> >)

While the first two are self-contained aside from calls to
`std::string_view::{begin,end,size}`, the sort approach relies on `std::sort`
which involves a number of calls into the C++ standard library, which can be
seen from the size of the object files::

    $ size ch1/CMakeFiles/is_unique.dir/*.o
       text    data     bss     dec     hex filename
        535       0       0     535     217 ch1/CMakeFiles/is_unique.dir/is_unique_brute_force.cpp.o
        684       0       0     684     2ac ch1/CMakeFiles/is_unique.dir/is_unique_using_bitfield.cpp.o
      12752       8       0   12760    31d8 ch1/CMakeFiles/is_unique.dir/is_unique_using_sort.cpp.o

Clearly the use of `std::sort` is bringing in a lot of code.
