# Основы работы с git

Добавление первого файла(main.cpp) в репозиторий:

![Img](steps/step_1.png)

Модификация файла main.cpp, и публикация изменений в репозиторий:

![Img](steps/step_2.png)

### Пункт 1

Добавляем в код две функции `someFunc` и `anotherFunc`. Сначала закоммитим функцию someFunc, а потом anotherFunc:

![Img](steps/step_3.png)

![Img](steps/step_4.png)

### Пункт 2

Добавим функцию `newBranchFunc`. И зафиксируем изменение в новой ветке `newBranch`

![Img](steps/step_5.png)

Как видим, изменения не попали в ветку master:

![Img](steps/step_6.png)

В ветке `newBranch` изменения присутствуют:

![Img](steps/step_7.png)

Добавим изменения в ветку master:

![Img](steps/step_8.png)

Как видим, новая функция `newBracnchFunc` присутствует и в master

![Img](steps/step_9.png)

Удалим ветку `newBranch`:

![Img](steps/step_10.png)

Теперь в репозитории только одна ветка master:

![Img](steps/step_11.png)


