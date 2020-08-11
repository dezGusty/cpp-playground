# Assignment 5 (ro)

(Versiunea în limba română 🔷💛🚩)

## Pasul 1

Faceți fork la repository-ul de pe github: <https://github.com/dezGusty/cpp-playground>

Notă: dacă ați făcut deja un fork, actualizați-l:
Ex <https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/syncing-a-fork>
(Recomandare: folosiți termenul de upstream pt. repo-ul original <https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/configuring-a-remote-for-a-fork> )
Notă: Dacă ștergeți și recreați repo-ul, ar fi bine să vă asigurați că am verificat prima temă 😊. Sau să copiați conținutul pentru prima temă în noul repo.

## Pasul 2

Downloadați și construiți library-ul grafic SFML: <https://github.com/SFML/SFML>

Notă: se recomandă același mod de generare de soluție cu CMake.

```sh
git clone https://github.com/SFML/SFML.git
cd SFML
mkdir build
cd build
cmake ..
```

Deschideți soluția și dați un build (Ex pentru Visual Studio: `SFML.sln`)

Dacă ați făcut build cu opțiunile implicite, sub Windows ar trebui să aveți generat un director cu binarele rezultate.

Ex: pentru Debug build: `SFML\build\lib\Debug 📁`

- 📜 sfml-audio-d-2.dll
- 📜 sfml-graphics-d-2.dll
- 📜 sfml-network-d-2.dll
- 📜 sfml-system-d-2.dll
- 📜 sfml-window-d-2.dll

## Pasul 3

### (RE)Construiți cpp-playground

Dați un build folosind CMake.
Aveți nevoie de directorul în care ați făcut build la SFML (Ex: `D:/work/cpp/SFML/build`)

Puteți face fie din CMake fie din CMakeGUI

#### Din command line

```cmd
cmake .. -DBUILD_SAMPLES_EXTERNAL_DEPS=ON -DSFML_DIR=D:/work/cpp/SFML/build
```

#### Din GUI

Deschideți CMakeGUI și bifați / activați `BUILD_SAMPLES_EXTERNAL_DEPS=ON`

De asemenea, setați variabila `SFML_DIR` la `D:/work/cpp/SFML/build`.

## Pasul 4

Copiați binarele necesare pentru execuția programului în folderul de output pentru proiectul `20_sfml_lib_sample`. De exemplu, sub Windows, folosind subdirectorul `build`, acesta ar putea fi 📁`cpp-playground\bin\Debug`.

Asigurați-vă că puteți executa fără probleme programul.

```cmd
20_sfml_lib_sample.exe
```

## Pasul 5

Creați un nou proiect numit `23_sfml_game_of_life`, care să fie o copie a proiectului `20_sfml_lib_sample`.
Recomandare: copiați configurația de `CMakeLists.txt` din `20_sfml_lib_sample`. Nu uitați să redenumiți numele proiectului după copierea fișierului.

> Notă: copiați și fișierele de cod sursă.

## Pasul 6

Modificați programul (23_sfml_game_of_life) pentru a îl transforma într-un Game Of Life.

> Notă: nu aveți nevoie să citiți user input pentru dimensiunea lumii de joc sau pentru starea inițială (forme trasate inițial).
>
> Le puteți hard-coda.

Puteți modifica / reorganiza tot codul. Dar pentru simplitate vă recomand să începeți lucrul din 📜`sfml_app.cpp`, unde funcția `updateWorld` vă permite să începeți repede lucrul și să vedeți rezultate.

Puteți modifica totul, dar vă recomand pentru a vă fi mai ușor să folosiți `setCellColor` pentru a actualiza starea unei celule.

Puteți să modificați

## Pasul 7 (bonus / opțional)

Faceți posibilă modificarea în timp real a lumii cu mouse-ul.
De exemplu: să pot da pauză, apoi să desenez cu mouse-ul o formă, dau resume iar lumea să evolueze ulterior conform așteptărilor.

De exemplu: <https://www.youtube.com/watch?v=GfmFIIm0HGo>

## Pasul 8 (bonus / opțional)

Faceți posibilă configurarea programului într-un fișier INI.

> Recomand stocarea în 📜`data/23_sfml_game_of_life.ini`.

Creați-vă propriile setări. Ce aș pune eu acolo ar fi setările hard-codate. Asta va permite modificarea comportamentului programului fără recompilare.
De exemplu, dacă vreau ca dimensiunea celulelor să nu mai fie 5x5, aș înlocui

```cpp
  preferred_cell_size.first = 5;
  preferred_cell_size.second = 5;
```

cu citirea lor din fișierul ini, unde ar putea fi definite poate așa

```ini
[world]
cell_size.x = 5
cell_size.y = 5

```

Alte setări ce ar putea fi mutate în INI:

- culorile folosite
- fereastra
- viteza animației
- orice altceva mai vreți voi
