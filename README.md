# Simple-Blockchain
2-oji užduotis: supaprastintos blokų grandinės kūrimas

v0.1 Funkcionalumai:

* Galima generuoti blockchain'ą remiantis sukurtomis Blockchain ir Block klasėmis.
* Galima sukurti norimą vartotojų skaičių, kurių informacija(vardas, public_hash ir valiuta) yra saugoma User klasėje.
* Galima sugeneruoti norimą transakcijų skaičių, kurių informacija saugoma laikiname bloke, o tada perkeliama į blockchainą.
* Kas 100 sugeneruotų transakcijų jos yra priskiriamos naujam blockui, kuris panaudojus PoW procesą yra sukuriamas. Sunkumo lygmenį galima pakeisti bloko klasėje.

v0.2 Funkcionalumai:

* Sugeneravus atsitiktinę transakciją įsitikinama, ar ją galima atlikti, jei ne, ji pašalinama
* Kiekviena transakcija yra tikrinama pagal generuojamą hash'ą ir transakcijos ID.
* Patobulintas blokų kasimas, sukurūrus atsitiktines tranakcijos jos paskirstomos po 5 transakcijų vektorius ir pradedant nuo 100000 bandymų mėginama kol kuriam nors vektoriui pavyks iškasti bloką.

v0.3 Funkcionalumai:

* Pagal pateiktą kodo pavyzdį sukuriamas Merkle medžio hash generavimas, kuris yra Block klasėje
