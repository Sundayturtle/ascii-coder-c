# ASCII Coder

A simple C program that encodes text into numbers using the ASCII table.  
Each character is converted to a number. Optionally, a modifier (random numbers) can be applied to slightly change the output. The modifier is saved in `mod.cfg`.

The program reads and writes two files:

- `data.dat` — stores the encoded text  
- `mod.cfg` — stores the modifier array

It can also read `data.dat` and decode it back to the original text.

---

## Build and run

Compile with GCC:

```bash
gcc main.c -o ascii_coder
```
Run:
```bash
gcc main.c -o ascii_coder
```
The program will:
- generate a new modifier if needed and save it to mod.cfg
- encode the text and save it to data.dat
- decode and print the result to the screen

#Settings

In main.c you can change:
```bash
char data[] = "Hello from STURTLE"; // text to encode
int mod_able = TRUE;                // enable or disable modifier
int generate = TRUE;                // generate a new modifier
```

#Project structure
```bash
ASCII_coder/
├─ main.c
├─ data.dat      # created automatically
├─ mod.cfg       # created automatically
└─ README.md
```

Project will be changed and upgraded. Now I just learning a new things and this project my first on github. 
