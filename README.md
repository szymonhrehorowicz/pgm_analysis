## Files handler

### Jak używać?
Należy wywołać (z poziomu wiersza poleceń) program *./dist/filesHandler/filesHandler.exe*.

Program przyjmuje dwa formaty plików, tj. **tif** oraz **png**. Zamienia je na skalę szarości oraz zapisuje do pliku o takiej samej nazwie jak oryginał, lecz z rozszerzeniem **pgm**.

Przykłady użycia:
- tif:
`.\filesHandler.exe -tif 0.23C.tif` 
- png:
`.\filesHandler.exe -png 0.23C.png` 