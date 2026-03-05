@echo off
set PROGRAM=%~1

rem Тест1:запуск без аргументов
echo Test 1: No arguments
%PROGRAM% > nul
if errorlevel 1 (echo Test 1 passed) else (echo Test 1 failed & goto err)

rem Tест2:несуществующий файл
echo Test 2: Non-existent file
%PROGRAM% missing.txt hello > nul
if errorlevel 1 (echo Test 2 passed) else (echo Test 2 failed & goto err)

rem Тест3:поиск существующего слова
echo Test 3: Find existing word
%PROGRAM% test-data\test.txt needle > "%TEMP%\out3.txt"
if errorlevel 1 goto err
fc "%TEMP%\out3.txt" test-data\expected-3.txt > nul
if errorlevel 1 (echo Test 3 failed & goto err) else (echo Test 3 passed)

rem тест4:поиск отсутствующего слова
echo Test 4: Find non-existing word
%PROGRAM% test-data\test.txt nonexistent > "%TEMP%\out4.txt"
set /p result=<"%TEMP%\out4.txt"
if "%result%"=="Text not found" (echo Test 4 passed) else (echo Test 4 failed & goto err)

rem тест5:проверка регистр
echo Test 5: Case sensitivity
%PROGRAM% test-data\test.txt HELLO > "%TEMP%\out5.txt"
set /p result=<"%TEMP%\out5.txt"
if "%result%"=="Text not found" (echo Test 5 passed) else (echo Test 5 failed & goto err)

rem тест6:пустой файл
echo Test 6: Empty file
%PROGRAM% test-data\empty.txt hello > "%TEMP%\out6.txt"
set /p result=<"%TEMP%\out6.txt"
if "%result%"=="Text not found" (echo Test 6 passed) else (echo Test 6 failed & goto err)

rem тест7:пустая строка поиска
echo Test 7: Empty search string
%PROGRAM% test-data\test.txt "" > "%TEMP%\out7.txt"
fc "%TEMP%\out7.txt" test-data\expected-7.txt > nul
if errorlevel 1 (echo Test 7 failed & goto err) else (echo Test 7 passed)

rem тест8:поиск подстроки не целого слова
echo Test 8: Substring search
%PROGRAM% test-data\test8.txt test > "%TEMP%\out8.txt"
fc "%TEMP%\out8.txt" test-data\expected-8.txt > nul
if errorlevel 1 (echo Test 8 failed & goto err) else (echo Test 8 passed)

rem тест9:спецсимволы 
echo Test 9: Special characters
%PROGRAM% test-data\test9.txt "C:\Program" > "%TEMP%\out9.txt"
fc "%TEMP%\out9.txt" test-data\expected-9.txt > nul
if errorlevel 1 (echo Test 9 failed & goto err) else (echo Test 9 passed)

rem тест11:много совпадений
echo Test 10: All lines match
%PROGRAM% test-data\test10.txt x > "%TEMP%\out11.txt"
fc "%TEMP%\out11.txt" test-data\expected-10.txt > nul
if errorlevel 1 (echo Test 10 failed & goto err) else (echo Test 10 passed)

echo All tests passed
exit /b 0

:err
echo Test failed
exit /b 1