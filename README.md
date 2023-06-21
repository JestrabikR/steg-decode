# IJC (Jazyk C) - Domácí úkol č.1

Jako testovací příklad je implementovaná funkce, která použije algoritmus známý jako Eratostenovo síto a je použita pro výpočet posledních 10 prvočísel ze všech prvočísel od 2 do N=230000000 (230 milionů).
* spuštění: ```make run```

Testovací program "steg-decode.c", který ve funkci main načte ze
souboru zadaného jako jediný argument programu obrázek ve formátu PPM
a v něm najde uloženou "tajnou" zprávu. Zprávu je vytisknutá na stdout.
Zpráva je řetězec znaků (char, včetně '\0') uložený po jednotlivých bitech
(počínaje LSb) na nejnižších bitech (LSb) vybraných bajtů barevných složek
v datech obrázku. Dekódování je ukončeno po dosažení '\0'. Vybrané bajty jsou určeny 
prvočísly (počínaje od START_PRIME).
Bylo použito Eratostenovo síto podobně jako v příkladu "primes.c".\
(Tomuto principu ukrývání zpráv se říká také Steganografie)
* spuštění: ```make steg-decode && ./steg-decode du1-obrazek.ppm```

Celé zadání je v souboru ```zadání.txt```