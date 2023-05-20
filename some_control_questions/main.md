# ХЭШ и хэш-таблицы

### Свойства Хэш Функции

1. Если $x_{1} = x_{2} \to hash(x_{1}) = hash(x_{2})$. Обратное неверно и такая ситуация называется коллизией
2. Обратная функция не существует. По значению хэша нельзя найти какой конкретно элемент был захэширован.
3. Хэш имеет фиксированную длину. 


### Устройство множества(хэш таблицы)

Определим хэш - отображение из множества рассматриваемых элементов в множество натуральных чисел.

Пусть имеется массив достаточно большого размера. Добавить элемент в хэш таблицу - означает рассчитать хэш элемента( положение элемента в массиве) и добавить его в массив по рассчитанному индексу.

### Избежание коллизий при помощи использования второго ХЭШа - метод двойного хэша

Определим два хэша, возвращающие взаимно - простые числа(целые числа не имеющие общих делителей кроме $\pm 1$).

Пусть 
- $\mathfrak{S}$ - результат работы первой хэш функции
- $\mathfrak{K}$ - результат работы второй хэш функции 

Если по индексу $\mathfrak{S}$ в массиве уже расположен элемент, начинаем поиск по массиву с шагом $\mathfrak{K}$:
- ($\mathfrak{S} + \mathfrak{K}$ )
- ($\mathfrak{S} + 2 \cdot \mathfrak{K}$ )
- ($\mathfrak{S} + 3 \cdot \mathfrak{K}$ )
- $\dots$

Данный метод называется **методом двойного хэширования**.

# Многопоточное программирование

### Что может влиять на скорость выполнения многопоточной программы?

1. Количество исполнителей - число ядер процессора
2. Взаимодействие между потоками. Работа с разделяемыми ресурсами
3. Размер исходных данных. Если исходные данные слишком малы, то нет смысла использовать большое количество потоков. Много времени уйдёт на их создание
4. Системные ресурсы

### Как в стандартной библиотеке реализована концепция асинхронного исполнения?

- Использование `std::async` и класса `std::future`. 
  - Например 
   ```cpp
    std::future<int> result = std::async(std::launch::async, function, 5); // Запускаем функцию в отдельном потоке
    std::cout << "Result: " << result.get(); //получаем результат выполнения
  ```
- Использование `std::promise` и `std::thread`(похоже на использование `std::thread` и передачи аргумента в функцию по ссылке/указателю)
    - Например
    ```cpp
    #include <iostream>
    #include <thread>
    #include <future>

    void function(std::promise<int> promiseObj) {
        int result = 42;
        promiseObj.set_value(result); // Устанавливаем значение для promise
    }

    int main() {
        std::promise<int> promiseObj; // Создаем объект promise
        std::thread threadObj(function, std::move(promiseObj)); // Создаем объект thread и передаем ему функцию и promise

        std::future<int> futureObj = promiseObj.get_future(); // Получаем future из promise
        std::cout << "Result: " << futureObj.get() << std::endl; // Выводим результат выполнения функции

        threadObj.join(); // Ожидаем завершения потока

        return 0;
    }
    ```
- Использование `std::packaged_task` вместе с `std::thread`:
    - Например
    ```cpp
    #include <iostream>
    #include <thread>
    #include <future>

    int sum(int a, int b) {
        return a + b;
    }

    int main() {
        std::packaged_task<int(int,int)> task(sum); // Создаем объект packaged_task и связываем его с функцией sum
        std::future<int> result = task.get_future(); // Получаем future из объекта packaged_task

        std::thread threadObj(std::move(task), 2, 3); // Создаем объект thread и передаем ему объект packaged_task и аргументы

        std::cout << "Result: " << result.get() << std::endl; // Выводим результат выполнения функции

        threadObj.join(); // Ожидаем завершения потока

        return 0;
    }
    ```

### Состояние гонки

Способы устранения:
- Локальное копирование данных
- Синхрронизация

### Взаимная блокировка потоков(`deadlock`)

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex2;

void thread_function_1() {
    // Захватываем mutex1
    mutex1.lock();
    std::cout << "Thread 1 locked mutex1" << std::endl;
    
    // Пытаемся захватить mutex2
    mutex2.lock();
    std::cout << "Thread 1 locked mutex2" << std::endl;
    
    // Разблокируем mutex2 и mutex1
    mutex2.unlock();
    mutex1.unlock();
}

void thread_function_2() {
    // Захватываем mutex2
    mutex2.lock();
    std::cout << "Thread 2 locked mutex2" << std::endl;
    
    // Пытаемся захватить mutex1
    mutex1.lock();
    std::cout << "Thread 2 locked mutex1" << std::endl;
    
    // Разблокируем mutex1 и mutex2
    mutex1.unlock();
    mutex2.unlock();
}

int main() {
    std::thread t1(thread_function_1);
    std::thread t2(thread_function_2);

    t1.join();
    t2.join();

    return 0;
}

```

# Стандартные алгоритмы

### Категории итераторов

- итератор ввода (input iterator): движение вперед, чтение, один проход;
- однонаправленный итератор (forward iterator): движение вперед, чтение;
- двунаправленный итератор (bidirectional iterator): однонаправленный итератор + движение назад;
- итератор произвольного доступа (random access iterator): двунаправленный итератор + движение вперед и назад на любое целое число, вычисление расстояния между двумя итераторами;
- непрерывный итератор (contiguous iterator): произвольный доступ + хранение элементов непрерывно;
- итератор вывода (output iterator): движение вперед, запись, один проход.

# Типы умных указателей


- std::unique_ptr — умный указатель, владеющий динамически выделенным ресурсом;
- std::shared_ptr — умный указатель, владеющий разделяемым динамически выделенным ресурсом. Несколько std::shared_ptr могут владеть одним и тем же ресурсом, и внутренний счетчик ведет их учет;
- std::weak_ptr — подобен std::shared_ptr, но не увеличивает счетчик.
