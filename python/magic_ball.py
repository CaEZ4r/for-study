import random as rm

print('Привет Мир, я магический шар, и я знаю ответ на любой твой вопрос.')

answers = ['Весьма сомнительно', 'Перспективы не очень хорошие', 'По моим данным - нет', 'Мой ответ - нет', 'Даже не думай', 'Сконцентрируйся и спроси опять', 'Сейчас нельзя предсказать', 'Лучше не рассказывать', 'Спроси позже', 'Пока неясно, попробуй снова', 'Мне кажется - да', 'Вероятнее всего', 'Хорошие перспективы', 'Знаки говорят - да', 'Да', 'Можешь быть уверен в этом', 'Определённо да', 'Никаких сомнений', 'Предрешено', 'Бесспорно']

name = input('Ваше имя:')

print('Привет, ', name, '! Задавай любой вопрос.', sep='')
quest = input()
print(rm.choice(answers))
print()

while True:
    print('Хочешь задать ещё один вопрос?')
    if input() == 'Да':
        quest = input()
        print(rm.choice(answers))
        print()

    else:
        print('Возвращайся если возникнут вопросы!')
        break