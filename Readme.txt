Kalkulator Geometryczny

 Opis projektu

Geometry Calculator to aplikacja konsolowa napisana w języku C++. Aplikacja umożliwia użytkownikowi obliczanie obwodów i pól różnych figur geometrycznych, takich jak koło, prostokąt i kwadrat. Aplikacja została stworzona zgodnie z architekturą Model-View-Controller (MVC).

 Funkcjonalności

1. Obliczanie obwodu i pola koła:
   - Użytkownik podaje promień koła, a aplikacja zwraca obwód i pole.

2. Obliczanie obwodu, pola i przekątnej prostokąta:
   - Użytkownik podaje długość i szerokość prostokąta, a aplikacja zwraca obwód, pole i długość przekątnej.

3. Obliczanie obwodu i pola kwadratu:
   - Użytkownik podaje długość boku kwadratu, a aplikacja zwraca obwód i pole.

Struktura projektu

Projekt składa się z następujących klas:

- `Circle`: zawiera metody do obliczania obwodu i pola.
- `Rectangle`: zawiera metody do obliczania obwodu, pola oraz przekątnej.
- `Square`: zawiera metody do obliczania obwodu i pola.
- `IView`: zawiera metody do wyświetlania komunikatów i pobierania danych od użytkownika.
- `ConsoleView`: Implementacja widoku konsolowego, która wyświetla komunikaty i pobiera dane od użytkownika.
- `GeometryController`: Kontroler, który zarządza przepływem danych między modelem a widokiem.

