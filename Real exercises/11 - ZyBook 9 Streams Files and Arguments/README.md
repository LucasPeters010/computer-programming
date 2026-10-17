# ZyBook Chapter 9 - Gradual Practice

**19 original exercises**, based on the seven Chapter 9 files you uploaded.
This is a separate practice chapter, not a replacement for earlier exercises.

| Part | Contents | Progression |
|---|---|---|
| [A - String Streams](A%20-%20String%20Streams/README.md) | 9.3 and 9.4, then validation | Very easy -> easy -> medium -> hard |
| [B - File Streams](B%20-%20File%20Streams/README.md) | 9.5, 9.8, then a 9.7-style task | Very easy -> easy -> medium -> hard |
| [C - Command Line from Zero](C%20-%20Command%20Line%20from%20Zero/README.md) | 9.11 ONLY, starting from argc | Very easy -> easy -> medium |
| [D - Command Line and Files](D%20-%20Command%20Line%20and%20Files/README.md) | 9.12, one new step at a time | Very easy -> easy -> medium |

## Choose your starting point

For streams/files: begin at A01. For the unfamiliar command-line topics: you can
start at C01 immediately. C is independent of A and B. Do not combine them yourself.
D introduces the specific combination required by 9.12 only after command-line basics.
A05 and B06 are harder finishes, not prerequisites for C.

Every exercise contains README.md, exercise.hpp, solution.cpp and main.cpp.
Only solution.cpp is your work. Early tasks supply comments and small numbered hints;
C02 and D01 supply most of the function so you fill one output/open statement.
No completed reference solutions are committed.

## Checks and tools

The play button continues to run automatic tests. Test fixtures are created in
unique temporary directories and removed afterward. No need to add test files or
edge cases yourself, and tests do not overwrite your existing files.
The helper test_support.hpp uses filesystem tools only for testing; you do not need
to learn those to do any exercise. C/D READMEs explain how to build a separate app.exe
to experiment with real command-line arguments as well as the automatic tests.

## Stream facts to keep straight

- istringstream reads FROM a string with >>.
- ostringstream builds text with <<; str() returns that text.
- ifstream reads FROM a file; ofstream writes TO a file.
- ostream& lets a caller choose the output destination.
- while (input >> value) tests whether extraction succeeded, not simply eof().
  A successful final read can set eofbit while still producing a valid value.
- eof() reports whether a previous operation encountered the end; it does not predict a read.
- After successful extraction, std::ws consumes remaining whitespace before a strict end check.
- clear() resets error flags; str(newText) replaces a stringstream's buffer.
  A fresh stream per line avoids carrying error flags into the next line.

## Source coverage

Read from the uploaded current files: Input string stream (9.3), 9.4 Output string stream,
9.5 File input, 9.7 Parsing and validating input, 9.8 File output,
9.11 Command-line arguments, and 9.12 Command-line arguments and files.
The new tasks use original examples and explicit contracts. B06 simplifies the
textbook's optional-statistics format to fixed pairs of lines so errors cannot steal
input from the following record. No binary-file or advanced command-line-parser topics.
