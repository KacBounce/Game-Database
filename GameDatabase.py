def BoolIn():
    x = int(input("Is the game +18 (1 - Yes | 2 - No) : "))
    if(x == 1):
        return True
    else:
        return False
class GameData:
    size = 0
    max_size = 100
    name = ""
    company = ""
    genre = ""
    price = 0.0
    adult = 0
    active_players = 0
    time_played = 0.0
    games = []
    def Get_Genre(self):
        self.genre = input("Enter the genre of your game : ")
    def Get_Name(self):
        self.name = input("Enter the name of the game : ")
    def Get_Company(self):
        self.company = input("Enter the company of the game : ")
    def Get_Price(self):
        self.price = float(input("Enter the price of the game : "))
    def Get_Players(self):
        self.active_players = int(input("How many active players are there in your game : "))
    def Get_Time(self):
        self.time_played = float(input("How long did you play the game for : "))
    def Get_Adult(self):
        self.adult = BoolIn()
    def Get_Data(self):
        self.Get_Genre()
        self.Get_Name()
        self.Get_Company()
        self.Get_Price()
        self.Get_Players()
        self.Get_Time()
        self.Get_Adult()
        print()
    def Add_Game(self):
        x = GameData()
        x.Get_Data()
        self.games.append(x)
        self.size += 1
    def Show_All(self):
        for obj in self.games:
            x = 1
            print("Game nr.",x," :")
            print()
            print("Genre : ",obj.genre)
            print("Name : ",obj.name)
            print("Company : ",obj.company)
            print("Price : ",obj.price)
            print("Active players : ",obj.active_players)
            print("Time played : ",obj.time_played)
            print("Is it +18 : ",obj.adult)
            print()
            x += 1
    def Del_Game(self):
        x = int(input("Enter the number of the element you want to delete : "))
        x -= 1
        del self.games[x]
    def Change_Game(self):
        x = int(input("Enter the number of the element you want to change : "))
        print()
        go = True
        x -=1
        while(go):
            y = int(input("What do you want to change\n\n1.Genre\n2.Name\n3.Company\n4.Price\n5.Active players\n6.Time playes\n7.Is it +18\n8.Stop changing\n\nNumber : "))
            if(y == 1):
                self.games[x].Get_Genre()
            elif(y == 2):
                self.games[x].Get_Name()
            elif(y == 3):
                self.games[x].Get_Company()
            elif(x == 4):
                self.games[x].Get_Price()
            elif(y == 5):
                self.games[x].Get_Players()
            elif(y == 6):
                self.games[x].Get_Time()
            elif(y == 7):
                self.games[x].Get_Adult()
            elif(y == 8):
                go = False
            else:
                print("Not an option")
            print()
        print()
database = GameData()
go = True
while(go):
    print("Database size : ",database.size)
    print("DO YOU WANT TO :")
    print("1.Add a new game")
    print("2.Show all games in the database")
    print("3.Delete an element")
    print("4.Change an element")
    print("5.Turn off the program")
    x = int(input("Number : "))
    print()
    if(x == 1):
        database.Add_Game()
    elif(x == 2):
        database.Show_All()
    elif(x == 3):
        database.Del_Game()
    elif(x == 4):
        database.Change_Game()
    elif(x == 5):
        go = False
    else:
        print("That's not an option")
        print()
