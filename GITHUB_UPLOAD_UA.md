# Как опубликовать проект на GitHub

Этот файл — инструкция для публикации лабораторной работы № 1, вариант 5. Главная страница репозитория GitHub будет автоматически показывать содержимое `README.md`.

## 1. Создайте репозиторий

1. Откройте https://github.com/new и войдите в свой аккаунт.
2. Назовите репозиторий, например `lb1-variant5`.
3. Выберите `Public` или `Private` в соответствии с требованиями преподавателя.
4. Если отправляете уже подготовленные локальные файлы, не создавайте на GitHub дополнительные README, `.gitignore` или лицензию — они уже есть в папке проекта.
5. Нажмите **Create repository**.

## 2. Откройте папку в VS Code

Распакуйте архив, если работаете с ZIP. В VS Code выберите **File → Open Folder…** и откройте папку `LB1_Variant5_GitHub`, в которой лежат `main.cpp`, `README.md` и `.gitignore`.

## 3. Сделайте два содержательных коммита

Откройте встроенный терминал VS Code. Выполняйте команды из корня папки проекта:

```bash
git init
git status
git add main.cpp .gitignore
git commit -m "Добавлена программа и проверка входных данных"
git add README.md TESTS.md GITHUB_UPLOAD_RU.md
git commit -m "Добавлена документация и результаты тестирования"
```

Если Git впервые используется на этом компьютере, сначала настройте имя и электронную почту, которые будут отображаться в коммитах:

```bash
git config --global user.name "Ваше имя"
git config --global user.email "ваш-email@example.com"
```

Замените примеры своими данными. Не публикуйте пароли, токены или другие секреты.

## 4. Подключите репозиторий и отправьте файлы

На странице созданного репозитория GitHub скопируйте HTTPS-адрес. Затем выполните команды, подставив свой адрес вместо `https://github.com/USERNAME/lb1-variant5.git`:

```bash
git branch -M main
git remote add origin https://github.com/USERNAME/lb1-variant5.git
git push -u origin main
```

Если GitHub попросит авторизацию, используйте предложенный им способ входа. Не вставляйте пароль от аккаунта в команду.

## 5. Проверьте публикацию

1. Обновите страницу репозитория на GitHub.
2. Убедитесь, что видны `main.cpp`, `README.md`, `TESTS.md`, `.gitignore` и этот файл.
3. Откройте `README.md`: GitHub отображает его на главной странице репозитория.
4. Скопируйте ссылку на репозиторий и добавьте её в отчёт.
5. В терминале выполните `git log --oneline -2`, чтобы увидеть два последних коммита. Для отчёта сохраните хеш коммита финальной версии.

Если Git сообщает, что `origin` уже существует, не повторяйте `git remote add origin`: проверьте текущий адрес командой `git remote -v`. При необходимости измените его командой `git remote set-url origin <URL-репозитория>`.
git init
git status
git add main.cpp .gitignore
git commit -m "Добавлена программа и проверка входных данных"
git add README.md TESTS.md GITHUB_UPLOAD_RU.md
git commit -m "Добавлена документация и результаты тестирования"
git config --global user.name "krrmdbzp87-commits"
git config --global user.email "krrmdbzp87@privaterelay.appleid.com"