import timeit
import itertools

code_to_test = """
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

#set_of_numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
k = 0
for findNumb in all_possible_numbers:
    for i in all_possible_numbers:
        b, c = find_cows_and_bulls(i, findNumb)
        if(b == 4):
            #print(findNumb)
            #print(''.join(i))
            #print(b, c)
            break
"""
elapsed_time = timeit.timeit(code_to_test, number=10)/10
print(elapsed_time/5040)
