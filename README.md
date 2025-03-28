# Tic Tac Toe (Крестики-нолики) на C++

Эта консольная игра реализует классическую игру "Крестики-нолики" с двумя режимами:
- **Человек vs Человек**
- **Человек vs Компьютер** (с использованием алгоритма минимакс для выбора оптимальных ходов)

## Особенности

- **Игровое поле:**  
  Представлено в виде сетки 3×3.

- **Проверка победы:**  
  Игра проверяет победу по строкам, столбцам и диагоналям.

- **Режимы игры:**  
  Возможность игры как между двумя игроками, так и против компьютера.

- **Искусственный интеллект:**  
  Алгоритм минимакс используется для вычисления оптимального хода компьютера.

- **Валидация ввода:**  
  Обеспечивается проверка корректности координат и отсутствие повторного выбора занятой ячейки.

## Требования

- **Компилятор C++:**  
  Требуется поддержка стандарта C++11 или выше (используются стандартные контейнеры STL, такие как `vector`).

## Компиляция и запуск

1. Сохраните исходный код в файл, например, `tic_tac_toe.cpp`.

2. Откройте терминал в каталоге с файлом и выполните команду для компиляции:
   ```bash
   g++ -std=c++11 -o tic_tac_toe tic_tac_toe.cpp
