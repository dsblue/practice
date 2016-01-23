"""
Code to compute the number of lockers open after iteratively toggling every n'th locker after N trials, from
  the popular brain teaser.
"""

NUMBER_LOCKERS = 100

lockers = [0 for i in range(0, NUMBER_LOCKERS + 1)]

for i in range(1, NUMBER_LOCKERS + 1):
    for locker in range(1, NUMBER_LOCKERS + 1):
        if i == 0:
            lockers[locker] = 0
        else:
            if locker % i == 0:
                lockers[locker] = ~lockers[locker]

count = 0
for i in range(1, NUMBER_LOCKERS + 1):
    if lockers[i] == -1:
        count += 1

print "Open lockers: ", count
