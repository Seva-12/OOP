@echo off
chcp 65001 > nul
echo Тестирование flipbyte.exe
echo ========================
echo.

:: Проверка существования файла
if not exist "flipbyte.exe" (
    echo Ошибка: flipbyte.exe не найден!
    pause
    exit /b
)

:: ТЕСТ 1: Пример из задания
echo Тест 1: flipbyte.exe 6
flipbyte.exe 6
echo Ожидается: 96
echo.

:: ТЕСТ 2: Нулевое значение
echo Тест 2: flipbyte.exe 0
flipbyte.exe 0
echo Ожидается: 0
echo.

:: ТЕСТ 3: Максимальное значение
echo Тест 3: flipbyte.exe 255
flipbyte.exe 255
echo Ожидается: 255
echo.

:: ТЕСТ 4: Единица
echo Тест 4: flipbyte.exe 1
flipbyte.exe 1
echo Ожидается: 128
echo.

:: ТЕСТ 5: 128
echo Тест 5: flipbyte.exe 128
flipbyte.exe 128
echo Ожидается: 1
echo.

:: ТЕСТ 6: Ошибка - отрицательное число
echo Тест 6: flipbyte.exe -5
flipbyte.exe -5
echo Ожидается сообщение об ошибке
echo.

:: ТЕСТ 7: Ошибка - число больше 255
echo Тест 7: flipbyte.exe 300
flipbyte.exe 300
echo Ожидается сообщение об ошибке
echo.

:: ТЕСТ 8: Ошибка - буквы
echo Тест 8: flipbyte.exe abc
flipbyte.exe abc
echo Ожидается сообщение об ошибке
echo.

:: ТЕСТ 9: Ошибка - без аргумента
echo Тест 9: flipbyte.exe
flipbyte.exe
echo Ожидается сообщение об ошибке
echo.

pause