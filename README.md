# IJC (Jazyk C) - Domácí úkol č.1

Jako testovací příklad je implementovaná funkce, která použije algoritmus známý jako Eratostenovo síto a je použita pro výpočet posledních 10 prvočísel ze všech prvočísel od 2 do N=230000000 (230 milionů).
* spuštění: ```make run```

Testovací program "steg-decode.c", který ve funkci main načte ze
souboru zadaného jako jediný argument programu obrázek ve formátu PPM
a v něm najde uloženou "tajnou" zprávu.<br>Zprávu je vytisknutá na stdout.<br>
Zpráva je řetězec znaků (char, včetně '\0') uložený po jednotlivých bitech
(počínaje LSb) na nejnižších bitech (LSb) vybraných bajtů barevných složek
v datech obrázku. Dekódování je ukončeno po dosažení '\0'.<br>Vybrané bajty jsou určeny 
prvočísly (počínaje od START_PRIME).
Bylo použito Eratostenovo síto podobně jako v příkladu "primes.c".\
(Tomuto principu ukrývání zpráv se říká také Steganografie)
* spuštění: ```make steg-decode && ./steg-decode du1-obrazek.ppm```

Celé zadání je v souboru ```zadání.txt```

===== English: =====

# IJC (Language C) - Homework #1

As a test example, a function is implemented that uses an algorithm known as the Sieve of Eratosthenes and is used to calculate the last 10 primes from all primes from 2 to N=230000000 (230 million).
* run: ```make run```

Test program "steg-decode.c" which in the main function loads from the file, that is entered as the only argument of the program, image in PPM format
and finds a "secret" message stored in it.<br>The message is printed to stdout.<br>
A message is a string of characters (char, including '\0') stored bit by bit
(starting from LSb) on the least significant bits (LSb) of the selected color component bytes
in the image data. Decoding is finished when '\0' is reached.<br>The selected bytes are designated
prime numbers (starting from START_PRIME).
The Sieve of Eratosthenes was used similar to the "primes.c" example.\
(This principle of hiding messages is also called Steganography)
* run: ```make steg-decode && ./steg-decode du1-image.ppm```

The entire assignment is in the file ```zadání.txt```
