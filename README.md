# Kalkulate

C++-kielellä toteutettu komentorivilaskin, joka tukee peruslaskutoimituksia, potensseja ja sulkeita.

## Ominaisuudet

- **Peruslaskutoimitukset**: Yhteenlasku (`+`), vähennyslasku (`-`), kertolasku (`*`), jakolasku (`/`)
- **Potenssiin korotus**: Potenssioperaattori (`^`)
- **Sulkeet**: Täysi tuki sisäkkäisille sulkeille
- **Laskujärjestys**: Noudattaa oikeaa matemaattista laskujärjestystä
  - Potenssiin korotus ensin (`^`)
  - Kerto- ja jakolasku (`*`, `/`)
  - Yhteen- ja vähennyslasku (`+`, `-`)
- **Vianmääritystila (Debug Mode)**: Valinnainen yksityiskohtainen tuloste ongelmanratkaisua varten
- **Käyttäjäystävällinen käyttöliittymä**: Selkeä muotoilu hyödyllisillä keutteilla ja virheilmoituksilla

## Asennus

### Esivaatimukset

- C++-kääntäjä C++23-tuella (g++ suositeltu)
- Windows-käyttöjärjestelmä (build.bat toimitetaan Windowsia varten)

### Kääntöohjeet

1. Kloonaa tai lataa tietovarasto (repository)
2. Siirry projektihakemistoon
3. Suorita käännösskripti:

```bash
build.bat
```

Vaihtoehtoisesti käännä koodi manuaalisesti:

```bash
g++ -o build/Kalkulate.exe main.cpp -lstdc++exp -std=c++23
```

## Käyttö

### Peruskäyttö

1. Suorita suoritettava tiedosto:
```bash
./build/Kalkulate.exe
```

2. Syötä matemaattinen lauseke pyydettäessä
3. Paina Enter nähdäksesi tuloksen

### Esimerkkilausekkeita

```
(2^4)           → 16
3*(2+5)^2       → 147
10/2+3*4        → 17
(2+3)*(4-1)     → 15
2^3^2           → 512
```

### Vianmääritystila (Debug Mode)

Ota vianmääritystila käyttöön nähdäksesi yksityiskohtaiset laskentavaiheet:

```bash
./build/Kalkulate.exe --debug
```

Tämä näyttää:
- Jäsennellyt luvut ja operaattorit
- Laskutoimitusten vaiheittaisen suorituksen
- Sulkeiden käsittelyn
- Välitulokset

## Ohjelman rakenne

- **`evaluateExpression()`**: Käsittelee sulkeiden arvioinnin
- **`evaluateSimple()`**: Arvioi lausekkeet ilman sulkeita
- **`calculateAnswer()`**: Suorittaa yksittäiset laskutoimitukset

## Virheiden käsittely

Laskin sisältää kattavan virheiden käsittelyn muun muassa seuraaville tilanteille:
- Nollalla jakaminen
- Puuttuvat tai parittomat sulkeet
- Tyhjät lausekkeet
- Tuntemattomat operaattorit
- Virheelliset syötemuodot

## Tekijä

- **cha0s66** - [GitHub](https://github.com/cha0s66)

## Lisenssi

Tämä projekti on lisensoitu MIT-lisenssillä – katso lisätiedot alta:

```
MIT License

Copyright (c) 2026 cha0s66

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Osallistuminen (Contributing)

Kontribuutiot ovat tervetulleita! Voit vapaasti:
- Ilmoittaa virheistä
- Ehdottaa uusia ominaisuuksia
- Lähettää vetopyyntöjä (pull request)

## Versiot
**Kalkulate V4** – Paranneltu versio, jossa on parempi virheiden käsittely, vianmääritystila ja oikea laskujärjestys.