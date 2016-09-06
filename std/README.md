* Tabs are the only allowed indentation - tabs and spaces may *NEVER* touch
* All lines must be 80 characters or less
* Inline initialization should use brace initialization
  - E.g. `sf::IntRect{20, 30}`
* Blocks must always be surrounded by braces
  - E.g. `if(cond()) then();` is *bad*
* C++11 features are fair game, avoid C++14
* Avoid getting rid of namespaces, prefer renaming them to be shorter
* Constants and macros are CAPITALIZED, types are CamelCase, methods are
  javaCase, functions and variables are snake_case
* Pointers are type-oriented (`int* x`, not `int *x`)
* Avoid auto in general unless the type is excessively verbose
  - E.g. `std::vector<util::Type<int>>::const_iterator`
* Use pointers (`int*`), not references (`int&`)
  - No caller ambiguity of what's being passed
  - Exception: getter utility methods, e.g. `int& get(int x, int y)`
* Avoid casual use of char, short, int, and unsigned, prefer u* or i*
  - Provides range guarantees
* Avoid touching the members of other structures, but don't go so far
  as to write getters and setters
* Global state is strictly forbidden
  - Exactly one exception: the `debug` object, which does nothing when DEBUG is
    off
* Prefer returning errors to throwing exceptions
  - Treat exceptions as "something unexpected happened and the program can't
   continue" and, if used at all, use Pythonic error structs
* Prefer indexing and foreach iteration to pointer arithmetic
* All pointers are required to have a documented "owner"
  - The owner is the context/object responsible for destroying it
* These rules are a guideline, exceptions may arise
