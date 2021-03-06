import itertools


def find_cows_and_bulls(your_number, computer_number):
    cows = 0
    bulls = 0
    for i1 in range(4):
        for j1 in range(4):
            if your_number[i1] == computer_number[j1]:
                if i1 == j1:
                    bulls += 1
                else:
                    cows += 1
    return bulls, cows


all_possible_numbers = set(itertools.permutations('0123456789', 4))

set_of_numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}

findNumb = ""

for i in range(4):
    findNumb += set_of_numbers.pop()

while True:
    print()
    for i in all_possible_numbers:
        number = i
        break
    cur_bulls, cur_cows = find_cows_and_bulls(number, findNumb)
    print(number)
    print(cur_bulls, cur_cows)
    if cur_cows == 0 and cur_bulls == 4:
        break
    new_set = set()
    for i in all_possible_numbers:
        possbl_b, possbl_c = find_cows_and_bulls(number, i)
        if cur_cows == possbl_c and cur_bulls == possbl_b:
            new_set.add(''.join(i))
    for i in new_set:
        print(i)
    all_possible_numbers = set(new_set)
