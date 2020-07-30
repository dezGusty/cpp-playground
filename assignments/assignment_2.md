# Assignment 2 (ro)

(Versiunea în limba română 🔷💛🚩)

## Pasul 1

Faceți fork la repository-ul de pe github: https://github.com/dezGusty/cpp-playground

Notă: dacă ați făcut deja un fork, actualizați-l:
Ex https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork
(Recomandare: folosiți termenul de upstream pt. repo-ul original https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/configuring-a-remote-for-a-fork )

Notă: Dacă ștergeți și recreați repo-ul, ar fi bine să vă asigurați că am verificat prima temă 😊. Sau să copiați conținutul pentru prima temă în noul

## Pasul 2

Dați un build folosind CMake.
Deschideți soluția (sln) generată.
Notă: și dacă aveți deschisă soluția veche, Visual Studio ar trebui să reîncarce lista de proiecte în urma unui build.

## Pasul 3

Modificați programul 03_armstrong și faceți-l să funcționeze corect. Găsiți și în cod modul așteptat de funcționare:

```cpp
       // What is this program expected to do?
       // - Shows whether an argument is an armstrong number.
       // (what?)
       // -   An Armstrong number is a number that is equal to the sum of cubes of its digits.
       //           For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
       //           Let's try to understand why 153 is an Armstrong number:
       //                  1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
       //
       // How to launch it?
       // - Execute the binary and pass a parameter to it?
       // - E.g. Open CMD in bin/Debug or bin/Release
       //             03_armstrong.exe 1       => Output: Armstrong
       //             03_armstrong.exe 2       => Output: Armstrong
       //             03_armstrong.exe               => Output: No program arguments found.
       //             03_armstrong.exe ABC           => Undefined output (do whatever).
       //             03_armstrong.exe 153           => Output: Armstrong
       //             03_armstrong.exe 154           => Output: NOT Armstrong
```

Notă: sunt marcate cu `TODO` locurile din cod unde mă aștept să adăugați / modificați cod.

## Pasul 4

Modificați programul 04_display_book și faceți-l să funcționeze corect. Găsiți și în main.cpp din acest proiect cum ar trebui să se comporte.

- Modificați codul pentru a face să încapă numele complete ale autorilor.
- Titlul trebuie să rămână la 50 de caractere limita.
- Afișați toți autorii unei cărți
- Asigurați-vă că nu se afișează ceva dincolo de limitele de memorie prevăzute.
- Adăugați încă o carte, păstrând în programul principal modul stabilit deja de creare/încărcare de date în cărți. Nu orice carte, ci asta
  https://www.amazon.com/Clean-Architecture-Craftsmans-Software-Structure/dp/0134494164

Notă: sunt marcate cu `TODO` câteva din locurile din cod unde mă aștept să adăugați / modificați cod.

## Pasul 5

Adăugați voi încă un program în soluție (show_args).
Faceți asta prin CMakeLists și urmați standardul de nume stabilit (ex: 05_nume).
Folosiți și convenția de a pune codul sursă în directoarele src (fișiere cpp) și include (fișiere .h dacă e cazul)
Ce va trebui să facă programul:

- Afișați toți parametrii trimiși din linie de comandă programului (fiecare parametru pe altă linie)
  - Ex: `program.exe AB C`  
    Output:
    - AB
    - C
