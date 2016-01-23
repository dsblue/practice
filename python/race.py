import random

def run_trial():
    car1_distance = 0
    car2_distance = 0

    while car1_distance < 100 and car2_distance < 100:
        if random.random() < 0.1:
            car1_distance += 5
        if random.random() < 0.6:
            car2_distance += 1

    if car1_distance >= 100:
        return 1
    else:
        return 2

winners = {'1': 0, '2': 0}
TRIALS = 100000
for t in range(TRIALS):
    winner = run_trial()

    winners[str(winner)] += 1

print 'Car ' + str(2) + ' won ' + str(100.0 * winners['2']/TRIALS) + '% of the time!'

