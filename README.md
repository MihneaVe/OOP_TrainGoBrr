# Nordlink

## Sistem de gestiune a aproape tuturor cerintelor unei gari:
(i.e Gara de nord din Bucuresti)
- afisare tranuri in/out bound
- afisare rute disponibile + bilete vandute automat
- optiune pentru raportarea si solutionarea problemelor
- optiuni de gestionare a informatiilor (doar de catre admini, in meniu dedicat!)

## Cerințe obligatorii 

Nerespectarea duce la nepunctarea proiectului

- programul va fi scris în C++
- programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
- programul nu are erori de compilare
- programul nu are warning-uri (folosind -Wall)
- existența a minim un punct din fiecare cerință
- fară variabile globale
- datele membre private
- fara headere specifice unui sistem de operare (<windows.h>)
- teste unitare pentru cerințele implementate (unde se poate, dacă nu apar probleme cu setup-ul de teste 😅)

## Tema 1

#### Cerințe
- [o] definirea a minim **2-3 clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (5p)
  - pentru o clasă:
    - [o] constructori de inițializare
    - [o] constructor supraîncărcat
    - [1] constructori de copiere
    - [o] `operator=` de copiere
    - [o] destructor
    - [o] `operator<<` pentru afișare (std::ostream)
    - [o] `operator>>` pentru citire (std::istream)
    - [o] alt operator supraîncărcat ca funcție membră
    - [o] alt operator supraîncărcat ca funcție non-membră
  - pentru celelalte clase se va definii doar ce e nevoie
- [o] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe (3p)
- nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector 
- [ ] scenariu de utilizare a claselor definite (1p):
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [o] opțiune pentru citirea și afișarea a n obiecte (1p)

## Recomandare Tema

* rezolvați tema 1 cu niște itemi generali ca să puteți extinde tema cu ușurință la următoarele teme.
  - coș de cumpărături + produse
  - sistem de validare a documentelor + documente de identitate
  - sistem de gestionare a biletelor + bilet 
* funcționalitatea creată să folosească metode ale obiectului generic 
* ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^
* branch-uri + commit-uri punctuale
