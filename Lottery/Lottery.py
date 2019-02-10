#This is a lottery game that chooses three winners from the list of names taken as input.
#It selects a prize for the winner and adds it to the dictionary in the end
import random
names=[]
winners={}
prize=""
prizes=["smartphone", "ipod", "wrist watch", "washing machine", "laptop", "dining set"]
win_prizes=[]
n=0
file=open("names.txt","a")
file.write("NAMES:\n")
winner_list=open("winner_list.txt","a")
while True:
    name=input("Enter the name here:")
    while not name.isalpha():
        name=input("Enter the name here:")
        continue
    if name=="Exit":
        break
    names.append(name)
    file.write(name)
    file.write("\n")
file.close()
winner_list.write("WINNERS:\n")
while n<3:
    winner=random.choice(names)
    while winner in winners:
        winner=random.choice(names)
    winner_list.write(winner)
    winner_list.write("\n")
    prize=random.choice(prizes)
    winners[winner]=prize
    n+=1
print(winners)
winner_list.close()
