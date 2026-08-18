#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;

bool DEBUG = false; // Aseta true-arvoksi debug-tulostuksen aktivoimiseksi

// Ennakkoilmoitukset
float evaluateExpression(const std::string& expr);

// Suorittaa aritmeettisia operaatioita operaattorin perusteella
float calculateAnswer(float a, float b, char op) {
    float result = 0;
    switch (op) {
        case '+':
            result = a + b;
            if (DEBUG) std::println("➕  Yhteenlasku: {} + {} = {}", a, b, result);
            return result;
        case '-':
            result = a - b;
            if (DEBUG) std::println("➖  Vähennyslasku: {} - {} = {}", a, b, result);
            return result;
        case '*':
            result = a * b;
            if (DEBUG) std::println("✖️  Kertolasku: {} × {} = {}", a, b, result);
            return result;
        case '/':
            if (b != 0) {
                result = a / b;
                if (DEBUG) std::println("➗  Jakolasku: {} ÷ {} = {}", a, b, result);
                return result;
            } else {
                std::println("\n❌  VIRHE: Nollalla jakaminen ei ole sallittu! ({} / {})", a, b);
                return 0;
            }
        case '^':
            result = pow(a, b);
            if (DEBUG) std::println("⬆️  Eksponentiointi: {} ^ {} = {}", a, b, result);
            return result;
        default:
            std::println("\n❌ VIRHE: Tuntematon operaattori: '{}'", op);
            return 0;
    }
}

// Evaluoi yksinkertaisen lausekkeen ilman sulkeita
float evaluateSimple(const std::string& expr) {
    vector<float> digitBuffer;  // Puskuri numeroille
    vector<char> opBuffer;      // Puskuri operaattoreille
    
    int i = 0;
    // Käydään läpi jokainen merkki merkkijonossa
    while (i < expr.length()) {
        // Ohita välilyönnit
        if (expr[i] == ' ') {
            i++;
            continue;
        }
        // If the character is a digit or a negative sign at the start or after an operator, parse the number
        if (isdigit(expr[i]) || (expr[i] == '-' && (i == 0 || expr[i-1] == '(' || expr[i-1] == '^' || expr[i-1] == '*' || expr[i-1] == '/'))) {
            std::string numStr = "";    // Puskurimerkki numerolle
            if (expr[i] == '-') {       // Jos negatiivinen merkki, lisää se numStr:ään
                numStr += '-';          // Lisää negatiivinen merkki numStr:ään
                i++;                    // Siirry seuraavaan merkkiin
            }
            // Jatka numeron lukemista, kunnes saavutetaan ei-numeroinen merkki
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.')) {
                numStr += expr[i];  // Lisää merkki numStr:ään
                i++;                // Siirry seuraavaan merkkiin
            }
            // Muunna numStr liukuluvuksi ja lisää digitBufferiin
            digitBuffer.push_back(std::stof(numStr));
            // if (DEBUG) std::println("[DEBUG] Jäsennetty numero: {}", numStr);  
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '*' || expr[i] == '^') {
            opBuffer.push_back(expr[i]); // Jos merkki on operaattori, lisää operaattori opBufferiin
            // if (DEBUG) std::println("[DEBUG] Löytyi operaattori: {}", expr[i]);
            i++; // Siirry seuraavaan merkkiin
        } else {
            i++; // Siirry seuraavaan merkkiin, jos merkki ei ole numero tai operaattori
        }
    }

    if (digitBuffer.empty()) {
        std::println("\n❌ VIRHE: Ei numeroita lausekkeessa!");
        return 0;
    }
    if (digitBuffer.size() == 1) {
        if (DEBUG) std::println("ℹ️ Vain yksi numero: {}", digitBuffer[0]);
        return digitBuffer[0];
    }
    
    if (DEBUG) {
        std::println("\n📊  JÄSENNYKSEN JÄLKEEN:");
        std::print("   Numerot:     ");
        for (float num : digitBuffer) std::print("{} ", num);
        std::println("");
        std::print("   Operaattorit: ");
        for (char op : opBuffer) std::print("{} ", op);
        std::println("");
    }

    // Ensimmäinen läpikäynti: Käsitellään ^ (eksponentiointi)
    if (DEBUG) std::println("\n🔹 VAIHE 1: Eksponentiointi (^)");
    for (int i = 0; i < opBuffer.size(); i++) {             // Käydään läpi jokainen operaattori opBufferissä
        if (opBuffer[i] == '^') {                           // Jos operaattori on ^, suorita eksponentiointi
            float a = digitBuffer[i];                       // Hae ensimmäinen numero
            float b = digitBuffer[i + 1];                   // Hae toinen numero
            if (DEBUG) std::println("   Indeksi {}: {} ^ {}", i, a, b);
            digitBuffer[i] = calculateAnswer(a, b, '^');    // Suorita eksponentiointi ja tallenna tulos digitBufferiin
            digitBuffer.erase(digitBuffer.begin() + i + 1); // Poista toinen numero digitBufferistä
            opBuffer.erase(opBuffer.begin() + i);           // Poista ^ operaattori opBufferistä
            i--; // Siirry takaisin edelliseen indeksiin, koska opBuffer on lyhentynyt
        }
    }

    // Toinen läpikäynti: Käsitellään * ja /
    if (DEBUG) std::println("\n🔹 VAIHE 2: Kertolasku (*) ja Jakolasku (/)");
    for (int i = 0; i < opBuffer.size(); i++) {             // Käydään läpi jokainen operaattori opBufferissä
        if (opBuffer[i] == '*' || opBuffer[i] == '/') {     // Jos operaattori on * tai /, suorita kertolasku tai jakolasku
            float a = digitBuffer[i];                       // Hae ensimmäinen numero
            float b = digitBuffer[i + 1];                   // Hae toinen numero
            char op = opBuffer[i];                          // Hae operaattori
            if (DEBUG) std::println("   Indeksi {}: {} {} {}", i, a, op, b);
            digitBuffer[i] = calculateAnswer(a, b, op);     // Suorita laskutoimitus ja tallenna tulos digitBufferiin
            digitBuffer.erase(digitBuffer.begin() + i + 1); // Poista toinen numero digitBufferistä
            opBuffer.erase(opBuffer.begin() + i);           // Poista operaattori opBufferistä
            i--; // Siirry takaisin edelliseen indeksiin, koska opBuffer on lyhentynyt
        }
    }

    // Kolmas läpikäynti: Käsitellään + ja -
    if (DEBUG) std::println("\n🔹 VAIHE 3: Yhteenlasku (+) ja Vähennyslasku (-)");
    for (int i = 0; i < opBuffer.size(); i++) {             // Käydään läpi jokainen operaattori opBufferissä
        if (opBuffer[i] == '+' || opBuffer[i] == '-') {     // Jos operaattori on + tai -, suorita yhteen- tai vähennyslasku
            float a = digitBuffer[i];                       // Hae ensimmäinen numero
            float b = digitBuffer[i + 1];                   // Hae toinen numero
            char op = opBuffer[i];                          // Hae operaattori
            if (DEBUG) std::println("   Indeksi {}: {} {} {}", i, a, op, b);
            digitBuffer[i] = calculateAnswer(a, b, op);     // Suorita laskutoimitus ja tallenna tulos digitBufferiin
            digitBuffer.erase(digitBuffer.begin() + i + 1); // Poista toinen numero digitBufferistä
            opBuffer.erase(opBuffer.begin() + i);           // Poista operaattori opBufferistä
            i--; // Siirry takaisin edelliseen indeksiin, koska opBuffer on lyhentynyt
        }
    }
    
    if (DEBUG) std::println("\n✅ Yksinkertaisen lausekkeen tulos: {}", digitBuffer[0]);
    return digitBuffer[0];
}

// Evaluoi lausekkeita sulkeiden kanssa
float evaluateExpression(const std::string& expr) {
    std::string processed = expr;
    if (DEBUG) std::println("\n═════════════════════════════════════════════════════");
    if (DEBUG) std::println("   LAUSEKKEEN ARVIOINTI ALOITETTU");
    if (DEBUG) std::println("═════════════════════════════════════════════════════");
    if (DEBUG) std::println("📝 Alkuperäinen: {}", expr);
    
    // Etsi ja evaluoi sisimmät sulkeet
    int parenthesisCount = 0;
    while (processed.find('(') != std::string::npos) { // Kunnes kaikki sulkeet on käsitelty
        parenthesisCount++;
        if (DEBUG) std::println("\n▶️  SULKEIDEN KÄSITTELY #{}", parenthesisCount);
        
        int lastOpen = processed.rfind('('); // Löydä viimeisin avaus-sulku
        int firstClose = processed.find(')', lastOpen); // Löydä ensimmäinen sulkeutuva sulku avaus-sulun jälkeen
        
        if (DEBUG) std::println("   Paikat: {}...{}", lastOpen, firstClose);
        
        if (firstClose == std::string::npos) { // Jos sulkeutuvaa sulkua ei löydy 
            std::println("\n❌ VIRHE: Sulkeet eivät täsmää! Avaussulkua {} kohdalla ei löydy vastaavaa sulkea.", lastOpen);
            return 0;
        }
        
        std::string inner = processed.substr(lastOpen + 1, firstClose - lastOpen - 1); // Ota sisäinen lauseke sulkeiden välistä
        if (DEBUG) std::println("   Sisältö:  '{}'", inner);
        
        float result = evaluateSimple(inner); // Evaluoi sisäinen lauseke
        
        if (DEBUG) std::println("   Tulos:    {}", result);
        
        // Korvaa (inner) tuloksella, käyttäen rajoitettua desimaalitarkkuutta
        char buffer[32]; // Puskuri tuloksen muuntamiseen merkkijonoksi
        snprintf(buffer, sizeof(buffer), "%.10g", result); // Muunna tulos merkkijonoksi, rajoitettuna 10 desimaaliin
        processed = processed.substr(0, lastOpen) + std::string(buffer) + processed.substr(firstClose + 1); // Korvaa sulkeiden sisältö tuloksella
        
        if (DEBUG) std::println("   Päivitetty: '{}'", processed);
    }
    
    if (DEBUG) {
        std::println("▶️  LOPULLINEN ARVIOINTI (ilman sulkeita)");
        std::println("   Lauseke: '{}'", processed);
    }
    float finalResult = evaluateSimple(processed);
    
    return finalResult;
}

int main(int argc, char* argv[]) {
    // Tarkista --debug lippu
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--debug") {
            DEBUG = true;
            break;
        }
    }

    std::println("═════════════════════════════════════════════════════");
    std::println("  Tekijä: cha0s66 | GitHub: cha0s66 | Lisenssi: MIT  ");
    std::println("-----------------------------------------------------");
    std::println("                  🧮 Kalkulate V4                    ");
    std::println("═════════════════════════════════════════════════════");
    
    if (DEBUG) {
        std::println("🐛 DEBUG-TILA AKTIVOITU\n");
    }

    std::string equation;
    std::println("📥 Syötä yhtälö");
    std::println("   Esimerkki: (2^4) tai 3*(2+5)^2\n");
    std::print("➤ ");
    std::cin >> equation;

    if (equation.empty()) {
        std::println("\n❌ VIRHE: Tyhjä lauseke!");
        return 1;
    }

    float answer = evaluateExpression(equation);
    std::println("");
    std::println("═════════════════════════════════════════════════════");
    std::println("✨ LOPULLINEN VASTAUS");
    std::println("═════════════════════════════════════════════════════");
    std::println("Lauseke: {}", equation);
    std::println("Tulos:   {}", answer);
    std::println("═════════════════════════════════════════════════════");

    return 0;
}