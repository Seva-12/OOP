@echo off
set PROGRAM=%~1

rem Тест 1:запуск без параметров (режим stdin)
echo Test 1: Run without parameters
echo. | %PROGRAM% > nul
if errorlevel 1 (
    echo Test 1 failed
    exit /b 1
)
echo Test 1 passed

rem Тест 2:несуществующий входной файл
echo Test 2: Non-existent file
%PROGRAM% missing.txt out.txt a b > nul
if not errorlevel 1 (
    echo Test 2 failed
    exit /b 1
)
echo Test 2 passed

rem Тест 3:обычная замена
echo Test 3: Replacing ma with mama
%PROGRAM% test-data\fox.txt "%TEMP%\out3.txt" dog cat

if errorlevel 1 (
    echo Test 3 failed: runtime error
    exit /b 1
)

fc "%TEMP%\out3.txt" test-data\fox-replace-dog-with-cat.txt > nul
if errorlevel 1 (
    echo Test 3 failed: files are different
    exit /b 1
)

echo Test 3 passed

rem Тест 4:пустая строка поиска
echo Test 4: Empty search string
%PROGRAM% test-data\fox.txt "%TEMP%\out4.txt" "" cat
if errorlevel 1 goto err
fc "%TEMP%\out4.txt" test-data\fox.txt > nul
if errorlevel 1 goto err
echo Test 4 passed

rem Тест 5:замена на пустую строку
echo Test 5: Replace with empty string (remove dog)
%PROGRAM% test-data\test5-input.txt "%TEMP%\out5.txt" dog ""
if errorlevel 1 goto err
fc "%TEMP%\out5.txt" test-data\test5-expected.txt > nul
if errorlevel 1 goto err
echo Test 5 passed

rem Пример 1: зхамена ma на mama
echo Example 1: Replace ma with mama
%PROGRAM% test-data\example1-input.txt "%TEMP%\ex1.txt" ma mama
if errorlevel 1 goto err
fc "%TEMP%\ex1.txt" test-data\example1-expected.txt > nul
if errorlevel 1 goto err
echo Example 1 passed

rem Пример 2: 1231234 - rep
echo Example 2: 1231234 -> rep
%PROGRAM% test-data\example2-input.txt "%TEMP%\ex2.txt" 1231234 rep
if errorlevel 1 goto err
fc "%TEMP%\ex2.txt" test-data\example2-expected.txt > nul
if errorlevel 1 goto err
echo Example 2 passed

rem Пример 3:две строки в stdin
echo Example 3: stdin with no text
(echo replace & echo random string) | %PROGRAM% > "%TEMP%\ex3.txt"
set /p result=<"%TEMP%\ex3.txt"
if "%result%"=="random string " (
    echo Example 3 passed
) else (
    echo Example 3 failed
    goto err
)

rem Тест 6: ошибка открытия выходного файла
echo Test 6: Output file error
%PROGRAM% test-data\fox.txt "C:\Program Files\out.txt" dog cat > nul
if errorlevel 1 (echo Test 6 passed) else (echo Test 6 failed & goto err)

rem Тест 7: очень линные строки 1000 символоа
echo Test 7: Long lines
%PROGRAM% test-data\long.txt "%TEMP%\out7.txt" aaaa bbbb
if errorlevel 1 goto err
echo Test 7 passed

echo Test 8: Special characters
%PROGRAM% test-data\special.txt "%TEMP%\out8.txt" a.b x
if errorlevel 1 goto err
fc "%TEMP%\out8.txt" test-data\special-expected.txt > nul
if errorlevel 1 goto err
echo Test 8 passed

rem Тест 8: спецсимволы 
echo Test 9: No newline at end
%PROGRAM% test-data\nonewline.txt "%TEMP%\out9.txt" a b
if errorlevel 1 goto err
echo Test 9 passed

rem Тест 9: файл без перевода строки в конце
echo Test 10: No infinite loop
%PROGRAM% test-data\loop.txt "%TEMP%\out10.txt" a aa
if errorlevel 1 goto err
fc "%TEMP%\out10.txt" test-data\loop-expected.txt > nul
if errorlevel 1 goto err
echo Test 10 passed

rem Тест 10: зацикливание a - aa
echo Test 11: Help mode
%PROGRAM% -h | find "Usage" > nul
if errorlevel 1 goto err
echo Test 11 passed

echo All tests passed
exit /b 0

:err
echo Test failed
exit /b 1