# D - Command Line and Files

Start only after C01-C05 and the easy file exercises B01-B03.
This is the ONLY place command-line arguments meet files, matching ZyBook 9.12.
D01 supplies everything except one open statement. D02 adds a word loop.
D03 adds a search word. There is no abrupt jump to strict numeric parsing or formatted reports.

A filename is just text in argv[1]. Opening it with ifstream connects that text
to an actual file. A relative filename is resolved from the terminal's current
working directory, not automatically from wherever solution.cpp lives.
Open the terminal in the exercise folder to use the included sample.txt.
Quote paths containing spaces: .\app.exe "my words.txt".
Tests create their own files; sample.txt is only for your manual app runs.

| Exercise | Level | ZyBook |
|---|---|---|
| [01 - Open the Argument Filename](01%20-%20Very%20Easy%20-%20Open%20the%20Argument%20Filename/README.md) | Very Easy | 9.12 |
| [02 - Count Words in the Chosen File](02%20-%20Easy%20-%20Count%20Words%20in%20the%20Chosen%20File/README.md) | Easy | 9.12 |
| [03 - Find a Word from Arguments](03%20-%20Medium%20-%20Find%20a%20Word%20from%20Arguments/README.md) | Medium | 9.12 |
