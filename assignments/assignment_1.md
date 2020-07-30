# Assignment 1 (ro)

(Versiunea în limba română 🔷💛🚩)

## Pasul 1

Faceți fork la repository-ul de pe github: https://github.com/dezGusty/cpp-playground

## Pasul 2

Dați un build folosind CMake. Un lucru în plus față de ce am făcut la curs este că acum ar trebui să rezulte o soluție (sln) cu 2 proiecte.
Recomandare: folosiți ca output un folder [build] chiar din directorul cu README.md
Exemplu:
├───01_hello_world
│ └───src
├───02_odd_even
│ └───src
├───bin
└───build

## Pasul 3

Modificați programul 01_hello_world și puneți numele vostru în placeholder.

## Pasul 4

Modificați programul 02_odd_even și faceți-l să meargă. Găsiți și în main.cpp din acest proiect cum ar trebui să se comporte.
Aici trebuie să faceți programul să afișeze ODD, EVEN sau No program arguments found, în funcție de input-ul (program arguments) primiți.

```cpp
// 02_odd_even.exe 1     => Output: ODD
// 02_odd_even.exe 2     => Output: EVEN
// 02_odd_even.exe       => Output: No program arguments found.
// 02_odd_even.exe ABC   => Undefined output (do whatever).
```

Pentru a testa, încercați să apelați din [bin/Debug] sau [bin/Release] (din command line):

```cmd
02_odd_even.exe 1
02_odd_even.exe 2
02_odd_even.exe
```

Bonus: faceți ca pentru parametri non-numerici (ex: `Serios?`) să fie afișat mesajul NAN (not a number)

```cmd
02_odd_even.exe Serios?
NAN
```

## Pasul 5

Trimiteți pe mail link la repo-ul vostru.
