# Assignment 3 (ro)

(Versiunea în limba română 🔷💛🚩)

## Pasul 1

Faceți fork la repository-ul de pe github: <https://github.com/dezGusty/cpp-playground>

Notă: dacă ați făcut deja un fork, actualizați-l:
Ex <https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork>
(Recomandare: folosiți termenul de upstream pt. repo-ul original <https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/configuring-a-remote-for-a-fork> )
Notă: Dacă ștergeți și recreați repo-ul, ar fi bine să vă asigurați că am verificat prima temă 😊. Sau să copiați conținutul pentru prima temă în noul repo.

## Pasul 2

Dați un build folosind CMake.
Deschideți soluția (sln) generată.
Notă: și dacă aveți deschisă soluția veche, Visual Studio ar trebui să reîncarce lista de proiecte în urma unui build.

## Pasul 3

Modificați programul 06_read_file și faceți-l să funcționeze corect. Ce ar trebui să facă este să citească conținutul fișierului data/ermahgerd_berks.txt și să creeze obiecte de tipul Book.

Ar trebui ca tot codul modificat să fie între

```cpp
// TODO: BEGIN read the file -------------------------------------
și
// TODO: END read file and add to results vector ------------------
```

## Pasul 4

Modificați programul 08_lib_ini_read_book și faceți-l să funcționeze corect. Acesta este foarte similar cu cel anterior. O diferență notabilă este că folosește un 3rd party library, numit SimpleIni. Acesta este un library „header-only”: <https://github.com/brofield/simpleini>

Ce aveți de făcut:
Citiți din fișierul [data/ermahgerd_berks.ini] datele despre cărți, creați obiectele.

Indicați corect path-ul până la fișier.
Notă: sunt marcate cu TODO câteva din locurile din cod unde mă aștept să adăugați / modificați cod.

```ini
[books]
count = 4

[book.1]
name=The origin of truth
author=Gusti

[book.2]
name  = Arhanghelul Raul
author=Ovidiu Eftimie

[book.3]
name= Factfulness
author=Hans Rosling, Ola Rosling, Anna Rosling Ronnlund
[book.4]
name=Fahrenheit 451
author=Ray Bradbury

```

## Pasul 5

Completați programul 07_matrix_to_console.
Ce va trebui să facă: să poată afișa matrici de caractere. Output în consolă.
Exemple sunt date predominant cu caracterele: -XO și sunt date pentru 20x10 caractere. Dar ar trebui să funcționeze și pentru alte dimensiuni.
Atenție: puțin contrar modului obișnuit de lucru cu matrici, funcțiile cerute lucrează cu coordonate (x/y).
