<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQsQNvEqjnkYAZa4ZjqcJTX2TNqcsu-T-RBw_PMH3ZAVr6QQczC3w"/>

Skład:  
  
| Imię i nazwisko | Rola |  
| -------- | -------- |  
| Piotr Rozponczyk   | Developer (c++)   |  
| Artur Knopik  | Developer (c++)   |  
| Łukasz Włuka   | Grafik   |  
| Tomasz Król   | Grafik   |  
| Kordian Gajewski   | Człowiek od wszystkiego   |    

-----

![](https://thinkspacestudio.com/images/z/zombiemazecalendar15c556c9919.jpg)
# Instrukcja kompilacja/używania gotowego pliku .exe
- Aby program po skompilowaniu poprawnie działał należy skopiowa folder z głównego katalogu repozytorium ```"resource"``` do ``` "C:\SFML_GAME_PROJECT" ``` (domylny folder budowy projektu)  
* Nastpnie naley skopiowa ```"libgcc_s_dw2-1.dll"``` i ```"libstdc++-6.dll"``` z folderu ```"C:\MinGW\bin"``` (domylny folder instalacji MinGW) do ```"C:\SFML_GAME_PROJECT"```

  > Podczas bezpośredniego uruchomienia pliku ```.exe``` jest wymagany folder``` "resource"``` wraz z zawartością oraz pliki ```.dll```

 ---
 
# Rozwój PROJETKU i nowe zasoby oraz .dll
Podczas rozwijania projektu nowe zasoby dodajemy do folderu ```"resource"``` do odpowienich folderów.
W przypadku gdy do Projektu dochodzi nowy plik ```.dll``` należy uaktualnić TEN wpis i podać dokładną informację na jego temat (lokalizacja względem pliku ```.exe``` i w skład jakiego pakietu wchodzi wraz z informacją gdzie dokładnie się znajduje)


# Co aktualnie jest zrobione
 * Głównu szablon aplikacji
 * Przełączanie między stanami gry (Menu, Gra, Pause)
 * Podstawowe przyciski (sterowane klawiaturą)