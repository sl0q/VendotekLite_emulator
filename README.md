#VendotekLite_emulator
Данный проект разрабатывался в качестве дипломной работы бакалавра.

Эмулятор терминала чтения транспортных карт Vendotek (Lite) в форме десктоп приложения для Linux.

Для разработки использовался язык программирования С++.

Назначение программы состоит в том, чтобы тестировать поведение условного терминала с помощью специальных сценариев, заданных в виде JSON файлов.

Основными функциями эмулятора являются, приём сообщений, составленных согласно протоколу Intelligent Reader, их обработка и составление ответных сообщений, имитируя таким образом работу реального терминала. Составленные сообщения, являясь результатом работы эмулятора, записываются в JSON дамп, чтобы потом сравнить их с ожидаемым результатом, и на основе этого сравнения можно судить об успешности выполнения заданного сценария.
Протокол Intellireader, в котором описаны сообщения-команды, а также порядок их обработки, был разработан компанией ГК "Терминальные Технологии" (https://termt.ru) и был предоставлен мне для выполнения данной работы.

Так выглядит интерфейс программы
![start up screen with lables](https://github.com/user-attachments/assets/b5adb248-fc6c-4f76-bb10-47db28a12503)

Так выглядит программа после того, как загруженные сценарии были выполнены, а сгенерированные дампы проанализированы

![dumps compared](https://github.com/user-attachments/assets/8ce7e7f1-06e3-410f-921e-b6b7794095c8)
