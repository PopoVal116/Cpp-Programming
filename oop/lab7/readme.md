
# Лабораторная работа №7 — Контейнер std::stack (стек)

## Теория
**Стек** — структура LIFO (Last In – First Out).

`std::stack<T>` — адаптер (по умолчанию использует `deque`).

**Операции:**
- `push()` — положить на вершину
- `pop()` — снять с вершины
- `top()` — посмотреть верхний элемент

**Применение:** рекурсия, разбор выражений, компиляторы.

## Реализовано
- Класс `Flight` с данными о рейсе
- Инициализация `list<Flight>` и сортировка по проданным билетам (имитация обработки стека)
- Вывод отсортированного списка

## Ключевой фрагмент
```cpp
list<Flight> flights;
flights.sort(<a href="const Flight& a, const Flight& b" target="_blank" rel="noopener noreferrer nofollow"></a>{
    return a.getSoldTickets() > b.getSoldTickets();
});
